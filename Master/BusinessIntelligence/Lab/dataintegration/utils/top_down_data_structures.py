import pandas as pd


def to_GMT(GMM:pd.DataFrame):
    """
    Converte una Global Matching Matrix (GMM) in una Global Matching Table (GMT),
    elencando per ogni attributo globale (GAT) gli attributi locali (LAT) associati 
    nelle varie sorgenti (SOURCE), con identificatore univoco SLAT = SOURCE_LAT.
    """
    GMT = pd.DataFrame(columns=['GAT', 'SOURCE', 'LAT', 'SLAT'])

    for x in GMM.index:
        for y in GMM.columns:
            for z in GMM.loc[x, y]:
                GMT.loc[len(GMT)] = [x, y, z, f"{y}_{z}"]

    return GMT


def to_GMM(GMT: pd.DataFrame):
    """
    Converte una Global Matching Table (GMT) in una Global Matching Matrix (GMM),
    raggruppando gli attributi locali (LAT) per attributo globale (GAT) e sorgente (SOURCE).
    """
    df = GMT.groupby(['GAT', 'SOURCE'])['LAT'].agg(list).unstack('SOURCE')
    for c in df.columns:
        df.loc[df[c].isnull(), [c]] = df.loc[df[c].isnull(), c].apply(lambda x: [])
    return df