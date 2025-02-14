from neo4j import GraphDatabase, Driver
import numpy as np
from sklearn.metrics.pairwise import cosine_similarity


def recommend_to(userId, k):
    user_VSM = get_user_vector(userId)
    movies_VSM, titles = get_movie_vectors(userId)
    top_k = compute_top_k (user_VSM, movies_VSM, k)
    results = []
    for movie in top_k:
        item = {}
        item["movie_id"] = movie[0]
        item["title"] = titles[movie[0]]
        item["score"] = movie[1]
        results.append(item)
        print("item:" + item)
    return results

def compute_top_k(user, movies, k):
    dtype = [ ('movieId', 'U10'),('value', 'f4')]
    knn_values = np.array([], dtype=dtype)
    for other_movie in movies:
        value = cosine_similarity([user], [movies[other_movie]])
        if value > 0:
            knn_values = np.concatenate((knn_values, np.array([(other_movie, value)], dtype=dtype)))
    knn_values = np.sort(knn_values, kind='mergesort', order='value' )[::-1]
    return np.array_split(knn_values, [k])[0]

def get_user_vector(user_id):
    query = """
            MATCH (u:User {userId: $userId})-[r:INTERESTED_IN]->(feature)
            WITH CASE WHEN r IS NULL THEN 0 ELSE r.weight END as value
            RETURN COLLECT(value) as vector
        """
    user_VSM = None
    with driver.session() as session:
        tx = session.begin_transaction()
        vector = tx.run(query, {"userId": user_id})
        user_VSM = vector.single()[0]
    print("length user vector:" + str(len(user_VSM)))
    return user_VSM

def get_movie_vectors(user_id):
    list_of_moview_query = """
            MATCH (movie:Movie)-[r:DIRECTED|HAS]-(feature)<-[i:INTERESTED_IN]-(user:User {userId: $userId})
            WHERE NOT EXISTS((user)-[]->(movie)) AND EXISTS((user)-[]->(feature))
            WITH movie, count(i) as featuresCount
            WHERE featuresCount > 5
            RETURN movie.movieId as movieId, movie.title as title
        """

    query = """
            MATCH (feature)
            WHERE "Genre" in labels(feature) OR "Director" in labels(feature)
            WITH feature
            ORDER BY id(feature)
            MATCH (movie:Movie)
            WHERE movie.movieId = $movieId
            OPTIONAL MATCH (movie)-[r:DIRECTED|HAS]-(feature)
            WITH CASE WHEN r IS null THEN 0 ELSE 1 END as Value,
            CASE WHEN feature.genre IS null THEN feature.name ELSE feature.genre END as Feature
            RETURN COLLECT(Value) as vector;
        """
    movies_VSM = {}
    titles = {}

    with driver.session() as session:
        tx = session.begin_transaction()
        i = 0
        for movie in tx.run(list_of_moview_query, {"userId": user_id}):
            movie_id = movie["movieId"]
            title = movie["title"]
            vector = tx.run(query, {"movieId": movie_id})
            movies_VSM[movie_id] = vector.single()[0]
            titles[movie_id] = title
            print(f'movie {movie_id} {title} processed')
            i += 1
            if i % 100 == 0:
                print(i, "lines processed")
        print(i, "lines processed")
    return movies_VSM, titles

if __name__ == '__main__':
    with GraphDatabase.driver(uri='bolt://localhost:7687',auth=('neo4j','movielens')) as driver:
        driver.verify_connectivity()
        top10 = recommend_to("598", 10) #Replace 598 with any other user id you are interested in
        print("movie recommend:" + top10)
