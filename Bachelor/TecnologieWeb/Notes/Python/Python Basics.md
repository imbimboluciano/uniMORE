
### Struttura Lessicale
[[Python]] usa l’indentazione per esprimere la struttura dei blocchi di un programma. Quindi  
un blocco è un insieme di linee contigue tutte indentate della stessa quantità. La fine di una linea delimita la fine di uno statement. Se lo statement è più lungo di 80  caratteri utilizzo backslash (\) per continuare in una nuova linea. L’apertura di parentesi ( () [] {} ) determinano la fine dello statement solo alla loro chiusura.
In python ogni linea logica è una sequenza di componenti lessicali noti come tokens,  
questi sono identifiers (nomi usati per funzioni e variabili), keywords (indentificatori riservati per uso sintattico), operators , delimiters , literals.


### Tipi di Dato
Python è object oriented e con tipizzazione dinamica delle variabili (queste sono però  
strettamente tipizzate). Non è necessario dichiarare le variabili prima di usarle né  
dichiarare il loro tipo. Ogni variabile in Python è un’istanza di una classe che si può  
assegnare a un identificatore.

```python
# commento su una linea 
"""commento 
	su piú linee"""

var = 50
```

I principali “tipi” di numero che Python supporta sono numeri interi e numeri in virgola  
mobile (supporta anche i numeri complessi). Grazie alla funzione type possiamo capire qual é il tipo attuale della variabile.

```python
>>> x = 3
>>> type(x)
<class 'int'>
>>> y = int('3')
>>> type (y)
<class 'int'>
```

Python supporta anche valori logici/booleani con la classi bool e valori nulli come istanza della classe NoneType.

Le stringhe possono essere definite indifferentemente con single quote (‘ ‘) o con  
double quote (“ “). Sono sequenze immutabili di caratteri testuali sulle quali è possibile  
iterare. Per stampare un qualsiasi dato a video possiamo utillizare la funzione print() , la quale converte automaticamente il dato in stringa; print ha diversi parametri, tra i quali troviamo end usato per specificare cosa inserire alla fine della stringa. In Python3 le stringhe sono sequenze di caratteri UNICODE e questo permette di gestire qualsiasi simbolo o carattere a prescindere dalla lingua utilizzataTuttavia appare immediatamente evidente che l’utilizzo di 4 byte a carattere risulta molto dispendioso in termini di memoria quando in realtà si utilizzano tipicamente pochi caratteri in una stringa (normalmente facenti parte di una stessa lingua). 

```python
x = 3
print(x)
print('prima riga')
print('seconda riga', end = '') # non crea una new line
print('\tsempre riga', end = '\ttab!\n')
print('terza riga', end = '\t...fine terza riga\n')
print ("prima riga", end='come va')


#caso di errore
>>>print ("ciao" + 3)
Traceback (most recent call last):
 File "<stdin>", line 1, in <module>
TypeError: can only concatenate str (not "int") to str
>>> print ("ciao" + str(3))
ciao3
```


### Slicing 
Python offre una notazione chiamata slicing (to slice = affettare) che permette di  
accedere ad una serie di elementi di una sequenza ordinata (stringa, lista, etc.)  
attraverso il loro “index” (indice). La sintassi utilizza le parentesi quadre con i  
seguenti parametri: [{start}: stop {: step}]

```python
"casa"[:3] #cas (start di default é 0)
"casa"[2:] #sa (stop se non specificato arriva alla fine dell'oggetto)
"abcdefg"[0:5:2] #ace (step di default é 1)
```

### Operatori
Gli operatori aritmetici, di assegnamento e di confronto sono gli stessi dei piú comuni linguaggi di programmazione con l'aggiunta di alcuni operatori molto utili.

```python
x = x ** 5 #potenza
x = x // 5 #radice quadrata
```

Gli operatori logici sono i medesimi dei linguaggi di programmazioni piú famosi con la particolaritá di utilizzare parole e non simboli

```python
x < 5 and x < 10
x < 5 or x < 4
not x > 5
```

Python introduce anche altri operatori utili:
- Gli operatori di identitá usati per confrontare gli oggetti, non per verificare se i valori sono uguali, ma se sono lo stesso oggetto (che occupa la stessa locazione nella memoria)

```python
x is y
x is not y
```

- Gli operatori di appartenenza controllano l’appartenenza  di un oggetto ad  una sequenza come una lista, una stringa o una tupla.

```python
x in y
x not in y
```

### Loop e dichiarazioni condizionali
I costrutti condizionali  forniscono un modo per  eseguire un blocco di codice  scelto in base alla valutazione  in fase di esecuzione di una o  più espressioni booleane. A differenza di altri  
linguaggi, Python si basa su  l'indentazione, usando 4 spazi, per definire i blocchi di codice (le espressioni rimangono le medesime if, elif e else).

Anche i per i loop non abbiamo grandi differenze in Python rispetto ad altri linguaggi di programmazione se non per l'eliminazione del do-while

```python
for i in range(3): ##ciclo da 0 a 3
	print()
	
primes = [2,3,5,7]
for prime in primes:
	print(prime)
```


### Exception Handling
Quando si verifica un errore l’esecuzione del codice si interrompe e Python genera un messaggio d’errore. Queste eccezioni possono essere gestite usando le clausole try ed except. In Python, a differenza di Java, le eccezioni sono tutte uncheck e quindi vengono generato a tempo di esecuzione. 

```python
try:
	l + 'a'
except:
	print("Si é verificato un'eccezione")
else: ## se non viene generata nessuna eccezione viene eseguito il codice nell'else
	print("Hello world!")
```

Per generare un'eccezione specifica possiamo utilizzare la dichiarazione raise.

```python
raise NameError("Sollevo un'eccezione")
```

Per gestire un eventuale errore possiamo anche utilizzare la dichiarazione assert, la quale ci permette di verificare la validitá di input ed output

```python
assert isinstance(l, (int,float)), "Input Errato" 
```


### Context Manager
Il context manager é un oggetto che definisce il contesto di runtime da stabilire quando si esegue il blocco di codice with. Gli usi tipici dei context manager includono il salvataggio e il ripristino di vari tipi di stato globale, il blocco e lo sblocco delle risorse, la chiusura di file aperti,ecc...

```python
# with garantisce la chiusura del file a dispetto di possibili errori nel blocco di codice.
with open('test.txt', 'w') as f:
	f.write("Test text, first line.")
```


### Moduli
I moduli sono librerie di codice che si possono importare nel proprio script o in un’istanza interattiva dell’interprete.  Per importare un modulo si ricorre alla keyword import.

```python
import math
import pillow # manipolazione immagini
import numpy # elaborazione di array e matrici
import opencv # open source computer vision, modulo python per computer vision
```

Con l'utilizzo dei metodi capiamo la differenza che c'é tra metodi e funzioni: un metodo è una funzione che fa parte di una classe ed è utilizzabile su un oggetto della classe stessa, mentre una funzione è un oggetto istanza della classe function.


### Copy
Come in altri linguaggi di programmazione ad oggetti esistono due tipi di copia: la copia shallow (“superficiale”) e la copia deep (“profonda”) (utilizzabile importando il  modulo “copy”). La differenza tra shallow copy e deep copy è rilevante solo per oggetti con altri oggetti annidati o istanze di classe. 


### Generatori
I generatori sono uno strumento semplice e potente per la creazione di iteratori. Possono essere definiti anche mediante funzioni  regolari che usano la keyword yield ogni volta che vogliono restituire un dato. A dispetto delle funzioni, hanno il vantaggio di poter interrompere e di riprendere l’esecuzione quando viene invocata la funzione next(). Inoltre il loro utilizzo risulta vantaggioso circa l’impiego di memoria in quanto viene generato  
un oggetto alla volta. 

```python
def gen():
	for n in range(5):
		yield n

for n in gen():
	print(n) #0,1,2

iter_gen = iter(gen())
next(iter_gen) #0
next(iter_gen) #1
next(iter_gen) #2
next(iter_gen) #3
next(iter_gen) #4
next(iter_gen) #5
```

Può essere più efficiente usare le generator expression anche in combinazione con funzioni built-in tipiche degli oggetti iterabili (max(), min(), sum()). 

```python
sum(x for x in range(5)) #10
```


### Syntax comprehension
La syntax comprehension fornisce un modo conciso per creare qualsiasi tipo di struttura dati. Le applicazioni comuni  sono di creare nuovi oggetti iterabili in cui ogni elemento è il risultato di alcune operazioni applicate a ciascun membro di un'altra sequenza o di creare una sottosequenza di quegli elementi che soddisfano una determinata  condizione. 

```python
quadrati = [n ** 2 forn n in range(11)] #lista dei quadrati da 0 a 10
l = [n for n in range(5)]
t = tuple(n for n in range(5))
s = {n for n in range(5)}
d = dict((k,v) for k,v in zip(range(5), 'abcde'))
```

È inoltre possibile stabilire delle condizioni (con conditional statement).

```python
l = [x ** 2 for x in range(11) if x % 2 != 0]
```
