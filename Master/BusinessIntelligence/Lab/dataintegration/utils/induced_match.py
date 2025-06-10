import pandas as pd

def MatchIndottiGMT(GMT):
  Join=pd.merge(GMT,GMT, on='GAT')
  Join=Join[Join.SOURCE_x<Join.SOURCE_y]
  Join=Join[['SLAT_x','SLAT_y']]
  Join.columns=['SLAT_A','SLAT_B']

  return Join.drop_duplicates()