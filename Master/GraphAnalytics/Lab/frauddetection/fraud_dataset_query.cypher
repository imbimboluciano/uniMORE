// Write a query that visualize the transactions leading up to a fraud
MATCH p = (fraud:Fraudulent)<-[:HAS_NEXT*]-(tx:Transaction)
RETURN p

// Write a query to select the top five common merchants in fraudulent transaction chains
MATCH p = (fraud:Fraudulent)<-[:HAS_NEXT*]->(tx)-[:AT_MERCHANT]->(merchant)
RETURN merchant.name, COUNT(*) AS txCount
ORDER BY txCount DESC
LIMIT 5

// Compute the score
MATCH (t:Transaction)
WITH count(t) as txCount
MATCH p = (fraud:Fraudulent)<-[:HAS_NEXT*]-(tx)
WITH txCount, count(distinct tx) as txForegoundCount
MATCH p = (fraud:Fraudulent)<-[:HAS_NEXT*]-(tx)
WITH txCount, nodes(p) AS nodes, txForegoundCount
UNWIND nodes AS tx
WITH DISTINCT txCount, txForegoundCount, tx
MATCH (tx)-[:AT_MERCHANT]->(merchant)
with merchant, txCount, count(tx) as count_of_tx, txForegoundCount as count_of_tx_fore
WITH merchant, txCount, 1.0f*count_of_tx/count_of_tx_fore AS forePer
MATCH (t:Transaction)-[:AT_MERCHANT]->(merchant)
with merchant, count(t) as count_of_t, txCount, forePer as foregroundPercentage
with merchant, 1.0f*count_of_t/txCount as backgroundPercentage, foregroundPercentage
RETURN merchant.name, backgroundPercentage, foregroundPercentage, (foregroundPercentage*foregroundPercentage/backgroundPercentage) - foregroundPercentage as score
ORDER BY score DESC
LIMIT 5


// Write the query that finds users/credit cards that are at risk
MATCH (merchant:Merchant {name:"Gas Station"})<-[:AT_MERCHANT]-(tx)<-[:MAKES]-(user)
WHERE tx.date > datetime() - duration('P14D')
RETURN user.name