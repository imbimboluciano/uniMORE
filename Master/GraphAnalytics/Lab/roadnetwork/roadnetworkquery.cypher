// Create NEAR relationship
MATCH (p:OSMWayNode)
WITH p, p.location AS poi
MATCH (n:RoadJunction)
WHERE distance(n.location, poi) < 100 AND n <> p
MERGE (p)-[r:NEAR]->(n)
ON CREATE SET
r.distance = distance(n.location,p.location), r.status = 'active'
MERGE (p)<-[ri:NEAR]-(n)
ON CREATE SET
ri.distance = distance(n.location, p.location), ri.status = 'active'

// Add Spatial Layer
CALL spatial.addWKTLayer('spatial', 'geometry')

// I 10 incroci collegati al maggior numero di punti di interesse
MATCH(r:RoadJunction)-[:NEAR]->(o:OSMWayNode)<-[:MEMBER]-(p:PointOfInterest) 
RETURN r.id,COUNT(DISTINCT p) as NumberOfPoI ORDER BY NumberOfPoI DESC LIMIT 10

// Incroci a meno di 100m da una scuola (T:Tag{amenity:"school"})
MATCH (t:Tag{amenity:"school"})-[:TAGS]-()-[:MEMBER]-(o:OSMWayNode)-[:NEAR]-(r:RoadJunction) RETURN r.id, COUNT(r)

// Make a projection (this graph remain in memory)
CALL gds.graph.project(
    'roads',
    ['RoadOsm'],
    ['CONNECTED'] )
YIELD graphName AS graph, nodeProjection, nodeCount AS nodes, relationshipProjection, relationshipCount AS rels

// Betweenness centrality
CALL gds.betweenness.write(
    'roads',
    {
    writeProperty: 'bc'  // bc become a property of the node
    })
YIELD nodePropertiesWritten

// Roads with the highest bc
MATCH (r:RoadOsm) RETURN r.osmid as l,r.bc as bc ORDER BY bc DESC LIMIT 100