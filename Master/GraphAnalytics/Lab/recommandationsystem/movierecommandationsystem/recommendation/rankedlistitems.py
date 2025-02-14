#Code for getting a ranked list of items for the user
import numpy as np


def recommendTo(self, user_id, k):                 
    dtype = [('movieId', 'U10'), ('value', 'f4')]
    top_movies = np.array([], dtype=dtype)
    query = """                                    
        MATCH (user:User)
        WHERE user.userId = $userId
        WITH user
        MATCH (targetMovie:Movie)
        WHERE NOT EXISTS((user)-[]->(targetMovie))
        WITH targetMovie, user
        MATCH (user:User)-[]->(movie:Movie)-[r:SIMILAR_TO]->(targetMovie)
        RETURN targetMovie.movieId as movieId, sum(r.weight)/count(r) as 
         relevance
        order by relevance desc
        LIMIT %s
    """
    with self._driver.session() as session:
        tx = session.begin_transaction()
        for result in tx.run(query % (k), {"userId": user_id}):
            top_movies = np.concatenate((top_movies, np.array([(result["movieId"], result["relevance"])], dtype=dtype)))
 
    return top_movies