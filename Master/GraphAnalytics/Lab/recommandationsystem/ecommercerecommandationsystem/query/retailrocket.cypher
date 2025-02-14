// What did userId 911093 buy? Who are the other users who made the same purchase?
MATCH (u:User {userId:'911093'})-[:PURCHASES]-(i:Item) RETURN u,i
MATCH (u:User {userId:'911093'})-[:PURCHASES]-(i:Item)-[:PURCHASES]-(otherUser) RETURN otherUser

// Find the best sellers (the items with the highest number of purchases)
MATCH (u:User)-[p:PURCHASES]->(i:Item) RETURN i.itemId, count(DISTINCT u) as num_User ORDER BY num_User DESC

// Find the best buyers (the users with the highest number of purchases)MATCH (i:Item {itemId:'37029'})-[r:PURCHASES]-(u:User) RETURN id(u) as index, 1 as value order by index
MATCH (u:User)-[p:PURCHASES]->(i:Item) RETURN u.userId, count(DISTINCT i) as num_Item ORDER BY num_Item DESC

// Find recurrent buys (items purchased more than one time by the same user)
MATCH (u:User)-[p:PURCHASES]->(i:Item) WITH i.itemId as gitem, u.userId as guser, count(DISTINCT p) as num_occurrence 
RETURN gitem, guser, num_occurrence ORDER BY num_occurrence DESC

// Who are the users who bought item 360200? What did these users buy in addition to this item?
MATCH (i:Item {itemId:'360200'})<-[:PURCHASES]-(u:User)-[:PURCHASES]-(other:Item) RETURN i,u,other

// Explore the multiple purchases of the user with userId: "890980" for item with itemId:"213834"
MATCH g=(u:User {userId: "890980"})-[p:PURCHASES]->(i:Item {itemId:"213834"}) RETURN g


// Write a query for extracting the nonzero elements of each vector for users – try the query for {userId: "121688"}
MATCH (u:User {userId:'121688'})-[r:PURCHASES]-(i:Item) RETURN id(i) as index, 1 as value order by index
MATCH (u:User {userId:'890980'})-[r:PURCHASES]-(i:Item) RETURN id(i) as index, COUNT(DISTINCT r) as value order by index //weighted vector

//  Write a query for extracting the nonzero elements of each vector for items – try the query for {itemId: "37029"}
MATCH (i:Item {itemId:'37029'})-[r:PURCHASES]-(u:User) RETURN id(u) as index, 1 as value order by index