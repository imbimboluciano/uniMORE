// Write the query that finds the users that share with other users any kind of detail (example: email, address etc.)
MATCH (u:User)-[]->()<-[]-(other:User) RETURN u,other
MATCH (u:User)--()--(other:User) RETURN u,other


// We want to create a projection graph called ‘emails’:
MATCH (source:User)-[:HAS_EMAIL]->(target:Email)
WITH gds.alpha.graph.project('emails', source, target) AS graph
RETURN graph.nodeCount AS nodeCount,
graph.relationshipCount AS relationshipCount


// Projection with any kind of relations
CALL {
    MATCH (source:User)-[r:HAS_EMAIL]->(target:Email)
    RETURN source, target, r
    UNION
    MATCH (source:User)-[r:HAS_PHONE_NUMBER]->(target:PhoneNumber)
    RETURN source, target, r
    UNION
    MATCH (source:User)-[r:HAS_ADDRESS]->(target:Address)
    RETURN source, target, r
}
WITH gds.alpha.graph.project('user-details', source, target,
    {sourceNodeLabels: labels(source),
    targetNodeLabels: 'Detail'},
    {relationshipType: 'HAS_DETAIL'}) AS graph
RETURN graph.nodeCount AS nodeCount, graph.relationshipCount AS relationshipCount


// Search for the most relevant detail
CALL gds.pageRank.stream('user-details')
YIELD nodeId, score
RETURN gds.util.asNode(nodeId).value AS detail_value, score
ORDER BY score DESC
LIMIT 5

//Suppose we want to examine any possible user based on their details and discover if some couple of users share any details
MATCH (u:User)--()--(other:User) 
WITH gds.alpha.graph.project('user-user',u,other, {}, {relationshipType:'HAS_LINK'}) as graph 
RETURN graph.nodeCount as nodeCount, graph.relationshipCount as relationshipCount

// Now we can use the Weakly Connected Components (WCC) algorithm finds sets of connected nodes in directed and undirected graphs.
//  We will use wcc to identify rings and assign users to them.
CALL gds.wcc.stream('user-user-link')
YIELD nodeId, componentId
RETURN componentId AS partition, COUNT(*) AS members, COLLECT(gds.util.asNode(nodeId).name) AS names
ORDER BY members DESC

// Rerunning the projection and clustering with extended database (IP)
MATCH (u:User)--()--(other:User) 
WITH gds.alpha.graph.project('user-user-IP',u,other, {}, {relationshipType:'HAS_LINK'}) as graph 
RETURN graph.nodeCount as nodeCount, graph.relationshipCount as relationshipCount

CALL gds.wcc.stream('user-user-IP')
YIELD nodeId, componentId
RETURN componentId AS partition, COUNT(*) AS members, COLLECT(gds.util.asNode(nodeId).name) AS names
ORDER BY members DESC


// Eexplore all the graphs that are stored in the DB
CALL gds.graph.list()
YIELD graphName, nodeCount, relationshipCount
RETURN graphName, nodeCount, relationshipCount
ORDER BY graphName ASC

// you can drop a graph using gds.graph.drop