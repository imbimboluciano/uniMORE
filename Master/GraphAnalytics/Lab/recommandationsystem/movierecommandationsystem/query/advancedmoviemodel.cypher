// remove all node 
MATCH (n)
DETACH DELETE n;

// add constraint for uniqueness
CREATE CONSTRAINT FOR (a:Movie) REQUIRE a.title IS UNIQUE;
CREATE CONSTRAINT FOR (a:Genre) REQUIRE a.genre IS UNIQUE;
CREATE CONSTRAINT FOR (a:Person) REQUIRE a.name IS UNIQUE;

CREATE (pulp:Movie {title: 'Pulp Fiction'})
FOREACH (director IN ['Quentin Tarantino']
| MERGE (p:Person {name: director}) SET p:Director MERGE (p)-[:DIRECTED]-> (pulp))
FOREACH (actor IN ['John Travolta', 'Samuel L. Jackson', 'Bruce Willis', 'Uma Thurman']
| MERGE (p:Person {name: actor}) SET p:Actor MERGE (p)-[:ACTS_IN]->(pulp))
FOREACH (writer IN ['Quentin Tarantino', 'Roger Avary']
| MERGE (p:Person {name: writer}) SET p:Writer MERGE (p)-[:WROTE]->(pulp))
FOREACH (genre IN ['Action', 'Crime', 'Thriller']
| MERGE (g:Genre {genre: genre}) MERGE (pulp)-[:HAS]->(g))


CREATE (punisher:Movie {title: 'The Punisher'})
FOREACH (director IN ['Jonathan Hensleigh']
| MERGE (p:Person {name: director}) SET p:Director MERGE (p)-[:DIRECTED]-> (punisher))
FOREACH (actor IN ['Thomas Jane', 'John Travolta', 'Samantha Mathis']
| MERGE (p:Person {name: actor}) SET p:Actor MERGE (p)-[:ACTS_IN]->
(punisher))
FOREACH (writer IN ['Jonathan Hensleigh', 'Michael France']
| MERGE (p:Person {name: writer}) SET p:Writer MERGE (p)-[:WROTE]->
(punisher))
FOREACH (genre IN ['Action', 'Adventure', 'Crime', 'Drama', 'Thriller']
| MERGE (g:Genre {genre: genre}) MERGE (punisher)-[:HAS]->(g))


CREATE (bill:Movie {title: 'Kill Bill: Volume 1'})
FOREACH (director IN ['Quentin Tarantino']
| MERGE (p:Person {name: director}) SET p:Director MERGE (p)-[:DIRECTED]-> (bill))
FOREACH (actor IN ['Uma Thurman', 'Lucy Liu', 'Vivica A. Fox']
| MERGE (p:Person {name: actor}) SET p:Actor MERGE (p)-[:ACTS_IN]->(bill))
FOREACH (writer IN ['Quentin Tarantino', 'Uma Thurman']
| MERGE (p:Person {name: writer}) SET p:Writer MERGE (p)-[:WROTE]->(bill))
FOREACH (genre IN ['Action', 'Crime', 'Thriller']
| MERGE (g:Genre {genre: genre}) MERGE (bill)-[:HAS]->(g))


// Retrieve Actors who worked together in the same movie
MATCH (a:Actor)-[:ACTS_IN]->(m:Movie)<-[:ACTS_IN]-(o:Actor) RETURN a.name,o.name,m.title