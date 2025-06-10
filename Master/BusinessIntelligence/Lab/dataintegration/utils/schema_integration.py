
import networkx as nx
import pandas as pd


def generaLAT(Sources):
  LAT = pd.DataFrame(columns=['SOURCE', 'LAT', 'SLAT'])
  for x in Sources:
    for y in Sources[x].columns:
      LAT.loc[len(LAT)]=[str(x),str(y), str(x)+'_'+str(y)]
  return LAT

def ClusterComponentiConnessi(LMT, SOURCES):

    MatchTable = LMT.iloc[:, :2].copy()
    MatchTable.columns = ['SLAT_A', 'SLAT_B']
    

    TuttiInodi= generaLAT(SOURCES)['SLAT'].to_list()
    Singleton = set(TuttiInodi) - set(MatchTable['SLAT_A']).union(set(MatchTable['SLAT_B']))


    # Creazione del grafo a partire dagli elementi della MatchTable
    G = nx.Graph()
    for _, row in MatchTable.iterrows():
        G.add_edge(row['SLAT_A'], row['SLAT_B'])

    # Aggiungi gli elementi singleton all'insieme dei nodi
    for element in Singleton:
        G.add_node(element)

    # Calcola i componenti connessi (clusters)
    clusters = list(nx.connected_components(G))

    # Creazione del DataFrame dei cluster
    cluster_data = {'ClusterKey': [], 'ClusterElement': []}
    for i, cluster in enumerate(clusters):
        for element in cluster:
            cluster_data['ClusterKey'].append(i + 1)
            cluster_data['ClusterElement'].append(element)

    cluster_df = pd.DataFrame(cluster_data)
    return cluster_df


def GMTComponentiConnessi(LocalMatchingTable, Sources):
    
    Cluster=ClusterComponentiConnessi(LocalMatchingTable,Sources)
    LAT = generaLAT(Sources)
    
    GMT=pd.merge(Cluster,LAT, \
      left_on='ClusterElement', right_on='SLAT'). \
       rename(columns={'ClusterKey': 'GAT'}). \
            drop(columns='ClusterElement')

    return GMT




