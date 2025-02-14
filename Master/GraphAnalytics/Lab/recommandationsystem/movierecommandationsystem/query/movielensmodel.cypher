// Search for pairs of actors who worked on the same movie. Add LIMIT 50 at the end of the query.
MATCH (a:Actor)-[:ACTS_IN]->(m:Movie)<-[:ACTS_IN]-(o:Actor) RETURN a.name,o.name,m.title LIMIT 50

// Count, for each actor, how many movies they acted in.
MATCH (a:Actor)-[r:ACTS_IN]->() RETURN a.name,COUNT(r) as numberOfMovies 

// Get a movie (by movieId), and list all the features.
MATCH (m:Movie {movieId:'27'})-[]-(f) RETURN m, f 

// List the movies rated by user (userId =1) ordered from the highest rated.
MATCH (u:User {userId:'1'})-[r:RATED]->(m:Movie) RETURN m.title, r.rating ORDER BY r.rating DESC

// Discover relationships between users and item features (search for all the graph patterns ((u:User)-[:WATCHED|RATED]-> (m:Movie))
MATCH (user:User)-[:WATCHED|RATED]->(movie:Movie)-[:ACTS_IN|WROTE|DIRECTED|PRODUCED|HAS]-(feature)
RETURN user,movie,feature LIMIT 20

// Computing relationships between users and item features (derive new relations)
MATCH (user:User)-[:WATCHED|RATED]->(movie:Movie)-[:ACTS_IN|WROTE|DIRECTED|PRODUCED|HAS]-(feature)
WITH user, feature, count(feature) as occurrences
WHERE occurrences > 2
MERGE (user)-[:INTERESTED_IN]->(feature)
SET r.weight = occurence

MATCH (user:User)-[r:RATED]->(movie:Movie)-[:ACTS_IN|WROTE|DIRECTED|PRODUCED|HAS]-(feature)
WHERE r.rating = '5.0'
WITH user, feature, count(feature) as occurrences
WHERE occurrences > 2
MERGE (user)-[:LIKES]->(feature)

// Discover relationships between user and item feature of Actors
MATCH (u:User {userId:'1'})-[r:RATED]->(m:Movie)-[r2:ACTS_IN]-(f)
WITH f.name AS groupingKey, COUNT(*) as occurence
RETURN groupingKey, occurence ORDER BY occurence DESC


// Vectorize items
MATCH (feature)
WHERE "Genre" in labels(feature) OR "Director" in labels(feature)
WITH feature
ORDER BY id(feature)
MATCH (movie:Movie)
WHERE movie.title STARTS WITH "Pulp Fiction"
OPTIONAL MATCH (movie)-[r:DIRECTED|HAS]-(feature)
RETURN CASE WHEN r IS null THEN 0 ELSE 1 END as Value,
CASE WHEN feature.genre IS null THEN feature.name ELSE feature.genre END as Feature
ORDER BY Value DESC

// To speed up vectorization
CREATE INDEX FOR (n:Movie) ON(n.title)