//visualizzare lo schema dei dati
CALL db.schema.visualization()
CALL apoc.meta.graph()

// visualizzare gli utenti che condivido un qualche dettaglio personale come telefono, email o tessera sanitaria con altri utenti 
MATCH (u:User)-[:HAS_EMAIL|HAS_HEALTHINSURANCE|HAS_PHONE_NUMBER]->()<-[:HAS_EMAIL|HAS_HEALTHINSURANCE|HAS_PHONE_NUMBER]-(other:User) RETURN u,other

// visualizzare gli utenti che condivido un qualche dettaglio personale o professionale come telefono, email, tessera sanitaria, indirizzo lavorativo con altri utenti 
MATCH (u:User)-[:HAS_EMAIL|HAS_HEALTHINSURANCE|HAS_PHONE_NUMBER|HAS_WORKADDRESS]->()<-[:HAS_EMAIL|HAS_HEALTHINSURANCE|HAS_PHONE_NUMBER|HAS_WORKADDRESS]-(other:User) RETURN u,other

// visualizzare gli utenti che condivido un qualche dettaglio personale o professionale o di connessione con altri utenti (come telefono, email, tessera sanitaria, indirizzo lavorativo, IP da cui si sono connessi) 
MATCH (u:User)--(common)--(other:User) RETURN u,common,other

// discutere l’ipotetico giro di frode in base ai risultati che si sono trovati ai punti precedenti
MATCH (u:User)--()--(other:User) 
WITH gds.alpha.graph.project('user-user',u,other, {}, {relationshipType:'HAS_LINK'}) as graph 
RETURN graph.nodeCount as nodeCount, graph.relationshipCount as relationshipCount

CALL gds.wcc.stream('user-user')
YIELD nodeId, componentId
RETURN componentId AS partition, COUNT(*) AS members, COLLECT(gds.util.asNode(nodeId).name) AS names
ORDER BY members DESC