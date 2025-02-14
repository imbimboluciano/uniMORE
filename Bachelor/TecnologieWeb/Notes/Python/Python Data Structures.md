Le principali strutture dati in [[Python]] sono le Liste ,le Tuple , i Dizionari  ed i Set.

### Liste
La struttura dati più versatile è la lista, che può essere scritta come un elenco di oggetti elementi), separati da virgola, tra parentesi quadre (o con costruttore list()) e può  
contenere oggetti di diverso tipo. Sono collezioni mutabili di oggetti ordinati selezionabili attraverso il loro “index”.

```python
list = [1, 'stringa', [1,2,3]]
l[1] #stringa
l[0] = 3
del l[2] #[3, 'stringa']
l[0:2] #slicing
l.append('d')
l.count(1) #conta occorrenze
l.index('d')
l.insert(2,'l')
len(l)
l.pop(2) #estrae dalla lista
```

### Tuple 
Le tuple sono sequenze, proprio come le liste. La differenza principale tra le tuple e le  
liste è che le tuple non possono essere modificate. Per istanziare una tupla si usano  
parentesi tonde o il costruttore tuple().

```python
t = ('a', 'b', 'c')
t[0]
t[1] = 'l' #errore
```

### Set
Un set è una collezione non ordinata e non indicizzati di elementi unici e immutabili. Per istanziare un set si usano parentesi graffe o il costruttore set(). L’idea del set è quella di ricreare le funzionalità tipiche degli insiemi matematici. Sono sequenze  “mutabili” ma possono contenere SOLO elementi immutabili (hashtable). 

```python
s = {1, 2, 3, 4, 4}
s[0] #errore i set non sono indicizzati
s.add(4)
s.remove(3) #solleva un errore se non trova l'elemento
s.discard(2) #non solleva un errore se non trova l'elemento
```

### Dizionari
I dizionari si trovano talvolta in altri linguaggi come "memorie associative" o "array associativi". A differenza delle sequenze (str, list, tuple), che sono indicizzate con numeri, i dizionari sono indicizzati da key, che possono essere di  qualsiasi tipo immutabile,  accoppiati con value; stringhe e numeri possono sempre essere chiavi. Si possono  
istanziare con parentesi graffe o con il costruttore dict(). I dizionari sono strutture dati mutabili e possono contenere QUALSIASI oggetto come value. Per modificare la struttura di un dizionario si può ricorrere a diversi strumenti.

```python
d = {'a': 1, 'b': 2, 'c': 3}
d['a'] #1
d.get('b') #2 
d['d'] = [1,2,3] #inserimento nuovo elemento
del d['c'] #cancellazione elemento
```

