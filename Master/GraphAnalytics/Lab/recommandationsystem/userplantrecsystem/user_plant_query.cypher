
CALL apoc.meta.graph()

MATCH (n) RETURN n

MATCH (n) RETURN COUNT(n)

CALL gds.graph.project(
    'plant-user',
    ['Plant','User'],
    {BUY: {orientation: 'REVERSE'}})
YIELD
graphName AS graph, nodeProjection, nodeCount AS nodes, relationshipProjection, relationshipCount AS rels


CALL gds.nodeSimilarity.stream('plant-user')
YIELD node1, node2, similarity
RETURN gds.util.asNode(node1).name AS Plant1, gds.util.asNode(node2).name AS Plant2, similarity
ORDER BY similarity DESCENDING, Plant1, Plant2

CALL gds.nodeSimilarity.stream('plant-user')
YIELD node1, node2, similarity
WITH gds.util.asNode(node1) AS Plant1, gds.util.asNode(node2) AS Plant2, similarity
WHERE Plant1 <> Plant2 AND similarity > 0.2 //0.4 troppo alto
MERGE (Plant1)-[r:SIMILAR_TO {similarity: similarity}]->(Plant2)
RETURN Plant1.name AS Plant1, Plant2.name AS Plant2, r.similarity AS Similarity
ORDER BY r.similarity DESC;


MATCH (frank:User {name: 'Frank'})-[r:BUY]->(p:Plant)
MATCH (p)-[sim:SIMILAR_TO]->(rec:Plant)
WHERE NOT EXISTS ((frank)-[:BUY]->(rec))
RETURN rec.name AS RecommendedPlant, sim.similarity AS Similarity
ORDER BY sim.similarity DESC
LIMIT 5;
// Cactus

MATCH (carol:User {name: 'Carol'})-[r:BUY]->(p:Plant)
MATCH (p)-[sim:SIMILAR_TO]->(rec:Plant)
WHERE NOT EXISTS ((carol)-[:BUY]->(rec))
RETURN rec.name AS RecommendedPlant, sim.similarity AS Similarity
ORDER BY sim.similarity DESC
LIMIT 5;
// Rose

CREATE (anne:User {name: 'Anne', userId: 9})

MATCH (u:User {name:'Hank'})-[:HAS_WORK]-(w:TypeOfWork) 
MERGE (anne:User {name: 'Anne'})-[:HAS_WORK]->(w)

CALL gds.graph.project(
    'user-similarity',
    ['User','TypeOfWork'],
    ['HAS_WORK'])
YIELD
graphName AS graph, nodeProjection, nodeCount AS nodes, relationshipProjection, relationshipCount AS rels


CALL gds.nodeSimilarity.stream('user-similarity')
YIELD node1, node2, similarity
RETURN gds.util.asNode(node1).name AS user1, gds.util.asNode(node2).name AS user2, similarity
ORDER BY similarity DESCENDING, user1, user2

CALL gds.nodeSimilarity.stream('user-similarity')
YIELD node1, node2, similarity
WITH gds.util.asNode(node1) AS user1, gds.util.asNode(node2) AS user2, similarity
WHERE user1 <> user2 AND similarity > 0.2// Imposta una soglia per la similarità
MERGE (user1)-[r:SIMILAR_TO {similarity: similarity}]->(user2)
RETURN user1.name AS user1, user2.name AS user2, r.similarity AS Similarity
ORDER BY r.similarity DESC;


MATCH (anne)-[sim:SIMILAR_TO]->(other:User)-[:BUY]-(rec:Plant)
WHERE NOT EXISTS ((anne)-[:BUY]->(rec))
RETURN rec.name AS RecommendedPlant, sim.similarity AS Similarity
ORDER BY sim.similarity DESC
LIMIT 5;