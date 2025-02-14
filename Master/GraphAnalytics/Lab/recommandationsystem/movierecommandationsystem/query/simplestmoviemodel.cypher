CREATE (p:Movie {
title: 'Pulp Fiction',
actors: ['John Travolta', 'Samuel Jackson', 'Bruce Willis', 'Uma Thurman'],
director: 'Quentin Tarantino',
genres: ['Action', 'Crime', 'Thriller'],
writers: ['Quentin Tarantino', 'Roger Avary'],
year: 1994
})
CREATE (t:Movie {
title: 'The Punisher',
actors: ['Thomas Jane', 'John Travolta', 'Samantha Mathis'],
director: 'Jonathan Hensleigh',
genres: ['Action', 'Adventure', 'Crime', 'Drama', 'Thriller'],
writers: ['Jonathan Hensleigh', 'Michael France'],
year: 2004
})
CREATE (k:Movie {
title: 'Kill Bill: Volume 1',
actors: ['Uma Thurman', 'Lucy Liu', 'Vivica A. Fox'],
director: 'Quentin Tarantino',
genres: ['Action', 'Crime', 'Thriller'],
writers: ['Quentin Tarantino', 'Uma Thurman'],
year: 2003
})


// Retrieve all the movies directed by Quentin Tarantino
MATCH (m:Movie {director:'Quentin Tarantino'}) RETURN m

// Retrieve Actors who worked together in the same movie
MATCH (m:Movie)
WITH m.actors as actors
UNWIND actors as actor  // unwind the list of actors
MATCH (n:Movie)
WHERE actor IN n.actors
WITH actor, n.actors as otherActors, n.title as title
UNWIND otherActors as otherActor
WITH actor, otherActor, title
WHERE actor <> otherActor
RETURN actor, otherActor, title
ORDER BY actor