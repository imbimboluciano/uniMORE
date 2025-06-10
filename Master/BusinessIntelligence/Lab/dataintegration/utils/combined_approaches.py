import pandas as pd


def max_sim_table(SimTableList:list):
    ST = pd.DataFrame(columns=["A","B","sim"])
    for x in SimTableList:
        ST = ST.append(x, ignore_index=True)
    return ST.groupby(["A","B"])["sim"].max().reset_index()

def min_sim_table(SimTableList:list):
    ST = pd.DataFrame(columns=["A","B","sim"])
    for x in SimTableList:
        ST = ST.append(x, ignore_index=True)
    return ST.groupby(["A","B"])["sim"].min().reset_index()

def avg_sim_table(SimTableList:list):
    ST = pd.DataFrame(columns=["A","B",'sim'])
    for x in SimTableList:
        ST = ST.append(x, ignore_index=True)
    return ST.groupby(["A","B"])["sim"].mean().reset_index()


def  Weighted_sum(dataframes, weights):
    if len(dataframes) < 2 or len(dataframes) != len(weights):
        raise ValueError("È necessario fornire almeno due DataFrame e i relativi pesi.")

    result_df = dataframes[0].copy()

    result_df["sim"] = result_df["sim"] * weights[0]

    for i in range(1, len(dataframes)):
        df = dataframes[i]
        weight = weights[i]

        result_df = pd.merge(result_df, df, on=["A", "B"], how="outer")

        result_df["sim"] = result_df.apply(lambda row: row["sim_x"] + row["sim_y"] * weight if not pd.isnull(row["sim_x"]) and not pd.isnull(row["sim_y"]) else row["sim_x"] if not pd.isnull(row["sim_x"]) else row["sim_y"] * weight, axis=1)

        result_df = result_df.drop(columns=["sim_x", "sim_y"])

    return result_df