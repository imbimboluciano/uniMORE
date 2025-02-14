// Visualizza lo schema
CALL apoc.meta.graph()

// Esplora i dati.
MATCH (n) RETURN n

// Conteggia nodi e proprietà.
MATCH (n) RETURN COUNT(n)


// Proietta un grafo bipartito degli utenti e piatti.
CALL gds.graph.project(
    'user-dish',
    ['User','Dish'],
    ['RATED'])
YIELD
graphName AS graph, nodeProjection, nodeCount AS nodes, relationshipProjection, relationshipCount AS rels


// Crea anche un grafo con edge orientati in senso opposto
// In neo4j non esistono grafi indiretti quindi con la clausola UNDIRECTED l’engine crea due grafi con direzioni opposte.
CALL gds.graph.project(
    'dish-user',
    ['User','Dish'],
    {RATED: {orientation: 'REVERSE'}})
YIELD
graphName AS graph, nodeProjection, nodeCount AS nodes, relationshipProjection, relationshipCount AS rels


// Stimiamo il costo del calcolo di similaritæ
CALL gds.nodeSimilarity.write.estimate('user-dish', {
    writeRelationshipType: 'SIMILAR',
    writeProperty: 'score'
    })
YIELD nodeCount, relationshipCount, bytesMin, bytesMax, requiredMemory


// Eseguiamo il calcolo di similarità
CALL gds.nodeSimilarity.stream('user-dish')
YIELD node1, node2, similarity // Estrae i nodi e la similarità dal risultato della funzione di similarità.
RETURN gds.util.asNode(node1).name AS User1, gds.util.asNode(node2).name AS User2, similarity
ORDER BY similarity DESCENDING, User1, User2


// Vediamo le statistiche sui nodi e coppie create
CALL gds.nodeSimilarity.stats('user-dish')
YIELD nodesCompared, similarityPairs


// Ora ho calcolato la similarità, ma non l’ho inserita nel grafo. Devo scegliere una soglia sul valore di similarità minimo
CALL gds.nodeSimilarity.stream('user-dish')
YIELD node1, node2, similarity
WITH gds.util.asNode(node1) AS user1, gds.util.asNode(node2) AS user2, similarity
WHERE user1 <> user2 AND similarity > 0.2// Imposta una soglia per la similarità
MERGE (user1)-[r:SIMILAR_TO {similarity: similarity}]->(user2)
RETURN user1.name AS user1, user2.name AS user2, r.similarity AS Similarity
ORDER BY r.similarity DESC;


// Proviamo ora a vedere lo stesso calcolo sulla proiezione reverse
CALL gds.nodeSimilarity.stream('dish-user')
YIELD node1, node2, similarity
RETURN gds.util.asNode(node1).name AS Dish1, gds.util.asNode(node2).name AS Dish2, similarity
ORDER BY similarity DESCENDING, Dish1, Dish2

CALL gds.nodeSimilarity.stream('dish-user')
YIELD node1, node2, similarity
WITH gds.util.asNode(node1) AS dish1, gds.util.asNode(node2) AS dish2, similarity
WHERE dish1 <> dish2 AND similarity > 0.2
MERGE (dish1)-[r:SIMILAR_TO {similarity: similarity}]->(dish2)
RETURN dish1.name AS dish1, dish2.name AS dish2, r.similarity AS Similarity
ORDER BY r.similarity DESC;

// Cancella le relazioni di similarità tra piatti e riscrivi impedendo che si crei una relazione di similarità tra due piatti se uno dei due è stato valutato da un solo utente
CALL gds.nodeSimilarity.stream('project_REVERSE')
YIELD node1, node2, similarity
WITH gds.util.asNode(node1) AS dish1, gds.util.asNode(node2) AS dish2, similarity
WHERE dish1 <> dish2 AND similarity > 0.2  // Imposta una soglia per la similarità

// Controlla che entrambi i piatti siano valutati da più di un utente
MATCH (dish1)<-[:RATED]-(user1)
WITH dish1, dish2, similarity, COUNT(user1) AS countUser1
WHERE countUser1 > 1

MATCH (dish2)<-[:RATED]-(user2)
WITH dish1, dish2, similarity, countUser1, COUNT(user2) AS countUser2
WHERE countUser2 > 1

MERGE (dish1)-[r:SIMILAR_TO {similarity: similarity}]->(dish2)
RETURN dish1.name AS dish1, dish2.name AS dish2, r.similarity AS Similarity
ORDER BY r.similarity DESC;


// RACCOMANDAZIONE: Voglio suggerire un piatto a Bob basandomi sulla relazione di similarità tra piatti come faccio?

// Step 1: Identificare i piatti che Bob ha valutato positivamente (ad esempio, rating >= 4)
MATCH (bob:User {name: 'Bob'})-[r:RATED]->(p:Dish)
WHERE r.rating >= 4

// Step 2: Trovare piatti simili a quelli valutati positivamente da Bob
MATCH (p)-[sim:SIMILAR_TO]->(rec:Dish)

// Step 3: Escludere i piatti che Bob ha già valutato
WHERE NOT EXISTS ((bob)-[:RATED]->(rec))

// Step 4: Restituire i piatti simili ordinati per grado di similarità
RETURN rec.name AS RecommendedDish, sim.similarity AS Similarity
ORDER BY sim.similarity DESC
LIMIT 5;

// RACCOMANDAZIONE 2: Aggiungi che bob ha mangiato salad e che charlie ha mangiato burger

// Bob ha mangiato Salad
MATCH (bob:User {name: 'Bob'}), (salad:Dish {name: 'Salad'})
CREATE (bob)-[:RATED {rating: 5}]->(salad);

// Charlie ha mangiato Burger
MATCH (charlie:User {name: 'Charlie'}), (burger:Dish {name: 'Burger'})
CREATE (charlie)-[:RATED {rating: 4}]->(burger);


// Riesegui il calcolo similarità tra piatti [comando sopra]


// Ora scrivi una query che fornisca per ogni utente una raccomandazione 
MATCH (u:User)-[r:RATED]->(p:Dish)
WHERE r.rating >= 4
MATCH (p)-[sim:SIMILAR_TO]->(rec:Dish)
WHERE NOT EXISTS ((u)-[:RATED]->(rec))
RETURN u.name, rec.name AS RecommendedDish, sim.similarity AS Similarity
ORDER BY sim.similarity DESC


// Ora usiamo la similarità tra utenti per suggerire raccomandazioni, ma prima arricchiamo le similarità tra utenti.

// Aggiungi una relazione di similarità con valore similarity 0.3 se due utenti vivono nella stessa città,. Poi visualizza tutti gli utenti simili ( con relazione SIMILAR_TO che li collega)
// Identificare gli utenti che vivono nella stessa città e creare una relazione SIMILAR_TO con similarity 0.3
MATCH (u1:User)-[:LIVES_IN]->(c:City)<-[:LIVES_IN]-(u2:User)
WHERE u1 <> u2
MERGE (u1)-[r:SIMILAR_TO {similarity: 0.3}]->(u2);

//Usa la similarità tra utenti per suggerire raccomandazioni
MATCH (u:User)-[r:RATED]->(p:Dish)
WHERE r.rating >= 4
MATCH (u)-[sim:SIMILAR_TO]->(other:User)-[r2:RATED]->(rec:Dish)
WHERE NOT EXISTS ((u)-[:RATED]->(rec))
RETURN u.name, rec.name AS RecommendedDish, sim.similarity AS Similarity
ORDER BY sim.similarity DESC
