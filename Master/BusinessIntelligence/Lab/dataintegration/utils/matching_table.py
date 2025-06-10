import pandas as pd

# These imports are assumed from your file context:
# from combined_approaches import *
# from label_based_measures import *
# from local_single_attribute import *
# from global_strategies import *
# from value_overlap import *

# For clarity in defining defaults, let's imagine explicit imports for default functions:
from .label_based_measures import levenshtein_label_based_similarity, jaro_label_based_similarity
from .value_overlap import value_overlap_simjoin_jaccard
from .combined_approaches import Weighted_sum, max_sim_table, min_sim_table, avg_sim_table
from .local_single_attribute import thresholding, top_K
from .global_strategies import simmetric_best_match, stable_marriage


# --- Default configurations to replicate original behavior ---
# Note: The parameter names in the dictionaries (for keyword arguments) or the order in tuples (for positional arguments)
# must match the signature of the respective functions being called.

DEFAULT_BASE_MATCHER_CONFIGS = [
    (levenshtein_label_based_similarity,),  # No extra params beyond TableL, TableR
    (jaro_label_based_similarity,),         # No extra params beyond TableL, TableR
    (value_overlap_simjoin_jaccard, (0.5,)) # 0.5 passed as a positional argument after TableL, TableR
]

# Original code effectively uses Weighted_sum as the final combiner for SimTable
DEFAULT_COMBINED_APPROACH_CONFIG = (Weighted_sum, ([0.3, 0.4, 0.3],)) # Weights for Weighted_sum

DEFAULT_LOCAL_STRATEGIES_CONFIGS = [
    (thresholding, (0.6,)) # 0.6 passed as a positional argument after the similarity table
]

DEFAULT_GLOBAL_STRATEGY_CONFIG = (simmetric_best_match,) # No extra params beyond the match table


def CalcoloMatchingTable(
    TableL: pd.DataFrame,
    TableR: pd.DataFrame,
    base_matcher_configs: list = None,
    combined_approach_config: tuple = None,
    local_strategies_configs: list = None,
    global_strategy_config: tuple = None
) -> pd.DataFrame:
    """
    Calculates a matching table between two input tables (TableL, TableR) using a configurable
    pipeline of similarity calculation, combination, local, and global strategies.

    Args:
        TableL (pd.DataFrame): The left table for matching.
        TableR (pd.DataFrame): The right table for matching.
        base_matcher_configs (list, optional): Configuration for base similarity matchers.
            Each item is a tuple: (matcher_function, (args_tuple)) or (matcher_function, {kwargs_dict})
            or (matcher_function,).
            matcher_function should take TableL, TableR as first two args.
            Defaults to DEFAULT_BASE_MATCHER_CONFIGS.
        combined_approach_config (tuple, optional): Configuration for combining similarity tables.
            A tuple: (combiner_function, (args_tuple)) or (combiner_function, {kwargs_dict})
            or (combiner_function,).
            combiner_function takes a list of similarity tables as its first argument.
            Defaults to DEFAULT_COMBINED_APPROACH_CONFIG.
        local_strategies_configs (list, optional): Configuration for local single attribute strategies.
            Each item is a tuple: (strategy_function, (args_tuple)) or (strategy_function, {kwargs_dict})
            or (strategy_function,).
            strategy_function takes the current match table as its first argument.
            Defaults to DEFAULT_LOCAL_STRATEGIES_CONFIGS.
        global_strategy_config (tuple, optional): Configuration for the global mapping strategy.
            A tuple: (strategy_function, (args_tuple)) or (strategy_function, {kwargs_dict})
            or (strategy_function,).
            strategy_function takes the current match table as its first argument.
            Defaults to DEFAULT_GLOBAL_STRATEGY_CONFIG.

    Returns:
        pd.DataFrame: The final matching table.
    """

    # Set default configurations if not provided
    if base_matcher_configs is None:
        base_matcher_configs = DEFAULT_BASE_MATCHER_CONFIGS
    if combined_approach_config is None:
        combined_approach_config = DEFAULT_COMBINED_APPROACH_CONFIG
    if local_strategies_configs is None:
        local_strategies_configs = DEFAULT_LOCAL_STRATEGIES_CONFIGS
    if global_strategy_config is None:
        global_strategy_config = DEFAULT_GLOBAL_STRATEGY_CONFIG

    # 1. Calculate individual similarity tables using Base Matchers
    sim_tables_list = []
    for config_item in base_matcher_configs:
        matcher_func = config_item[0]
        params = config_item[1] if len(config_item) > 1 else None
        
        if isinstance(params, dict): # Keyword arguments
            sim_table = matcher_func(TableL, TableR, **params)
        elif isinstance(params, (list, tuple)): # Positional arguments
            sim_table = matcher_func(TableL, TableR, *params)
        else: # No extra parameters
            sim_table = matcher_func(TableL, TableR)
        sim_tables_list.append(sim_table)

    # 2. Combine similarity tables
    combiner_func = combined_approach_config[0]
    combiner_params = combined_approach_config[1] if len(combined_approach_config) > 1 else None

    # Special handling for Weighted_sum(dataframes, weights) vs other combiners like max_sim_table(SimTableList)
    if combiner_func.__name__ == "Weighted_sum":
        if isinstance(combiner_params, dict) and 'weights' in combiner_params:
             SimTable = combiner_func(sim_tables_list, combiner_params['weights'])
        elif isinstance(combiner_params, (list, tuple)): # weights passed as positional arg(s)
             SimTable = combiner_func(sim_tables_list, *combiner_params)
        else:
             raise ValueError("Invalid or missing 'weights' parameter for Weighted_sum.")
    else: # For combiners like max_sim_table, avg_sim_table, etc.
        if isinstance(combiner_params, dict):
            SimTable = combiner_func(sim_tables_list, **combiner_params)
        elif isinstance(combiner_params, (list, tuple)):
            SimTable = combiner_func(sim_tables_list, *combiner_params)
        else: # No extra params
            SimTable = combiner_func(sim_tables_list)

    # 3. Apply Local Single Attribute Strategies
    # Start with the combined similarity table. Each local strategy refines this table.
    MatchTable = SimTable.copy() 
    for strategy_config_item in local_strategies_configs:
        strategy_func = strategy_config_item[0]
        strategy_params = strategy_config_item[1] if len(strategy_config_item) > 1 else None

        if isinstance(strategy_params, dict):
            MatchTable = strategy_func(MatchTable, **strategy_params)
        elif isinstance(strategy_params, (list, tuple)):
            MatchTable = strategy_func(MatchTable, *strategy_params)
        else: # No extra params
            MatchTable = strategy_func(MatchTable)
            
    # 4. Apply Global Mapping Strategy
    global_func = global_strategy_config[0]
    global_params = global_strategy_config[1] if len(global_strategy_config) > 1 else None

    if isinstance(global_params, dict):
        MatchTable = global_func(MatchTable, **global_params)
    elif isinstance(global_params, (list, tuple)):
        MatchTable = global_func(MatchTable, *global_params)
    else: # No extra params
        MatchTable = global_func(MatchTable)

    return MatchTable

