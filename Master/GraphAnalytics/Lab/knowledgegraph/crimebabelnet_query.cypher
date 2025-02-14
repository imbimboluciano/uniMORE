// Collane, o oggetti simili, rubati
MATCH (s:StolenObjectInstance {label_to_search:'collana'}) RETURN s

// Numero di furti collegati al termine gioielleria
MATCH (s:Synset {lemma:'gioielleria'})-[*1..3]-(o:StolenObjectInstance) RETURN o.label_to_search, COUNT(*)
MATCH (s:Synset {lemma:'gioielleria'})-[:IS_A*0..2]->(s1:Synset)-[:SAME_SYNSET]-(o:StolenObjectInstance) RETURN  s1.lemma, COUNT(*)
