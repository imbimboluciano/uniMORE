import pandas as pd



def Valuta(Gold:pd.DataFrame, Match:pd.DataFrame):
    Gold = Gold.iloc[:, :2].copy()
    Match = Match.iloc[:, :2].copy()
    Gold.columns = Match.columns = ['A', 'B']

    FOJ = Gold.merge(Match, how='outer', indicator=True) # full outer join between Gold and Match

    TP = FOJ[FOJ['_merge']=='both']
    FP = FOJ[FOJ['_merge']=='right_only']
    FN = FOJ[FOJ['_merge']=='left_only']

    if len(TP) == 0:
        return pd.DataFrame({
                'MT':[len(Match)],
                'TP':[len(TP)],
                'FP':[len(FP)],
                'FN':[len(FN)],
                'P':[round(0,4)],
                'R':[round(0,4)],
                'F':[round(0,4)]
            })
    else:
        P = len(TP)/(len(TP)+len(FP))
        R = len(TP)/(len(TP)+len(FN))
        F = 2 * P * R / ( P + R )
        return pd.DataFrame({
                'MT':[len(Match)],
                'TP':[len(TP)],
                'FP':[len(FP)],
                'FN':[len(FN)],
                'P':[round(P,4)],
                'R':[round(R,4)], 
                'F':[round(F,4)]
            })

def Vedi_Valuta(Gold:pd.DataFrame, Match:pd.DataFrame, metrics:str):
    Gold = Gold.iloc[:, :2].copy()
    Match = Match.iloc[:, :2].copy()
    Gold.columns = Match.columns = ['A', 'B']
    FOJ=pd.merge(Gold, Match, how='outer', indicator=True)

    TP=FOJ[FOJ['_merge']=='both']
    FP=FOJ[FOJ['_merge']=='right_only']
    FN=FOJ[FOJ['_merge']=='left_only']

    if metrics == 'FP' :
        return FP
    if metrics == 'TP' :
        return TP
    if metrics == 'FN' :
        return FN
    


def AnalisiGlobalMatchTable(GMT, Sources):
    """
    Verifica che la GMT sia coerente con le sorgenti. Stabilisce il tipo di mapping
    """
    # 1) Verifica che tutte le SOURCE usate in ['SOURCE'] siano presenti in Sources
    sources_in_GMT = set(GMT['SOURCE'])
    defined_sources = set(Sources.keys())
    print("1) Le seguenti SOURCE di GMT non sono definite in Sources:" , sorted(sources_in_GMT - defined_sources))

    # 2) Verifica che tutte le gli attributi locali GMT  siano presenti in Sources
    all_slat = set([f"{source}_{col}" for source, df in Sources.items() for col in df.columns])
    slat_in_GMT = set(GMT['SLAT'])
    print("2) I seguenti SLAT di GMT non sono definiti in Sources:" , sorted(slat_in_GMT - all_slat))

    # 3) GAT mappati in una sola SOURCE
    gat_source_counts = GMT.groupby('GAT')['SOURCE'].nunique()
    single_source_gats = gat_source_counts[gat_source_counts == 1].index.tolist()
    print("3) GAT mappati da una sola SOURCE:", sorted(single_source_gats))
    
    # 4) Per ogni SOURCE: GAT → più LAT
    print("4) GAT mappati in più LAT (per ciascuna SOURCE):")
    grouped = GMT.groupby(['SOURCE', 'GAT'])['LAT'].nunique()
    for (source, gat), count in grouped.items():
        if count > 1:
            print(f"   SOURCE: {source}, GAT: {gat}, LAT diversi: {count}")

    # 5) Per ogni SOURCE: LAT → più GAT
    print("5) LAT mappati in più GAT (per ciascuna SOURCE):")
    grouped = GMT.groupby(['SOURCE', 'LAT'])['GAT'].nunique()
    for (source, lat), count in grouped.items():
        if count > 1:
            print(f"   SOURCE: {source}, LAT: {lat}, GAT diversi: {count}")