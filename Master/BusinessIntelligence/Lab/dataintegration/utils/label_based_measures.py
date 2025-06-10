import pandas as pd

import warnings
warnings.filterwarnings('ignore')

import py_stringmatching as sm
from .similarity_structures import *





def levenshtein_sim(row:pd.Series):
    lev = sm.Levenshtein()
    return lev.get_sim_score(
            string_preprocess(row["A"]),
            string_preprocess(row["B"])
        )

def levenshtein_label_based_similarity(TableA:pd.DataFrame, TableB:pd.DataFrame):
    C = sim_table(TableA, TableB)
    C["sim"] = C.apply(levenshtein_sim, axis=1)
    return C.sort_values("sim", ascending=False)

# Jaro
def jaro_sim(row:pd.Series):
    jaro = sm.Jaro()
    return jaro.get_sim_score(
            string_preprocess(row["A"]),
            string_preprocess(row["B"])
        )

def jaro_label_based_similarity(TableA:pd.DataFrame,TableB:pd.DataFrame):
    C = sim_table(TableA, TableB)
    C["sim"] = C.apply(jaro_sim, axis=1)                   
    return C


# Jaccard
def jaccard_sim(row:pd.Series):
    jac=sm.Jaccard()
    tok = sm.WhitespaceTokenizer(return_set=True)
    return jac.get_sim_score(
            tok.tokenize(string_preprocess(row["A"])),
            tok.tokenize(string_preprocess(row["B"]))
    )

def jaccard_label_based_similarity(TableA:pd.DataFrame, TableB:pd.DataFrame):
    C = sim_table(TableA, TableB)
    C["sim"] = C.apply(jaccard_sim, axis=1)
    return C.sort_values("sim", ascending=False)

# OverlapCoefficient
def OC_sim(row:pd.Series):
    oc = sm.OverlapCoefficient()
    tok = sm.WhitespaceTokenizer(return_set=True)
    return oc.get_sim_score(
            tok.tokenize(string_preprocess(row["A"])),
            tok.tokenize(string_preprocess(row["B"]))
    )

def OC_label_based_similarity(TableA:pd.DataFrame, TableB:pd.DataFrame):
    C = sim_table(TableA, TableB)
    C["sim"] = C.apply(OC_sim, axis=1)
    return C.sort_values("sim", ascending=False)

# JaroWinkler
def JaroWinkler_sim(row:pd.Series):
    jw = sm.JaroWinkler()
    return jw.get_sim_score(
            string_preprocess(row["A"]),
            string_preprocess(row["B"])
        )

def JaroWinkler_label_based_similarity(TableA:pd.DataFrame, TableB:pd.DataFrame):
    C = sim_table(TableA, TableB)
    C["sim"] = C.apply(JaroWinkler_sim, axis=1)
    return C.sort_values("sim", ascending=False)

# MongeElkan
#Secondary similarity function. This is expected to be a sequence-based similarity measure 
#(defaults to Jaro-Winkler similarity measure).
def MongeElkan_sim(row:pd.Series):
    me = sm.MongeElkan()
    tok = sm.WhitespaceTokenizer(return_set=True)
    return me.get_raw_score(
            tok.tokenize(string_preprocess(row["A"])),
            tok.tokenize(string_preprocess(row["B"]))
    )


def MongeElkan_label_based_similarity(TableA:pd.DataFrame, TableB:pd.DataFrame):
    C = sim_table(TableA, TableB)
    C["sim"] = C.apply(MongeElkan_sim, axis=1)
    return C.sort_values("sim", ascending=False)