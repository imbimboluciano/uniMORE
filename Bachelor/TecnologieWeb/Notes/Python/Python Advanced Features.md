### Funzioni/Metodi
In [[Python]] funzioni e metodi sono oggetti che appartengono alla categoria "callable". Essendo oggetti, seguono le regole delle variabili. Possono essere creati, distrutti,  
passati come parametro, copiati e ri-definiti. Questo permette l'introduzione del meccanismo di **Duck Typing**.

```python
class Duck:  
	def verso(self):  
		print("QUACK")  

class Donkey:  
	def verso(self):  
		print("IOOOOHH")  

def fai_verso(a):  
	a.verso()  
	
fai_verso(Duck())  #Quack 
fai_verso(Donkey()) #IOOOOHH
```

Il programma stamperà “QUACK” ed “IOOOOHH”: assistiamo quindi ad una sorta di polimorfismo pur non essendo le classi Duck e Donkey imparentate tra di loro.  
Ciò è reso possibile dalla natura interpretativa di python, unitamente alla sua gestione completamente dinamica del concetto di “tipo di dato”.


### Default args
Abbiamo visto come una funzione o un metodo Python sia in grado di accettare dei  
parametri di default:  

```python
def stampa_nome(nome=”inserisci nome”):  
	print(“Ciao ” + nome)
```

Occorre chiedersi quando questi parametri vengono istanziati, visto che tutto in Python é un oggetto. La risposta é che i parametri di default vengono istanziati una volta sola alla prima chiamata della funzione. 
Se volessi comunque esprimere l’idea “se non ti passo un oggetto, createlo da solo tutte le volte e non una tantum al caricamento del modulo" potremmo fare in questo modo:

```python
def funzione_migliore(o : Oggetto = None):  
	if o==None:  
		o = Oggetto()  
	[...resto della funzione...]
```


### Variable args
Python, così come tanti altri linguaggi ammette il concetto di var args nei propri  
metodi e funzioni. Con var args s’intende la possibilità di specificare un numero variabile di  
argomenti in ingresso ad un “callable”. Si parla quindi di lista di Non-keyword args e Keyword-args.
- **Non keyword args**, in cui ciascun parametro non si differenzia “semanticamente” da quello successivo.  L’operatore unario * “esplode” strutture dato come per esempio liste per riempire i singoli parametri in ingresso alle nostre funzioni.
```python
def fvarargs_v1(*args):  
	for a in args:  
		print(a)

l = ["a",4,4.3,True,[1,2],False]
fvarargs_v1(*l)
```

- **Keyword-args**, in cui ogni parametro si differenzia “semanticamente” da quello successivo. L’operatore unario ** “esplode” strutture dato a dizionario per riempire i singoli parametri in ingresso alle nostre funzioni. Le chiavi ed i nomi dei parametri della funzione devono essere congruenti in valore e numero (no requisiti di ordinamento)
```python
def dict_varargs_v1(**kwargs):  
	for e in kwargs:  
		print(str(e)+":"+str(kwargs[e]))

d = { "eta":77, "l_mansioni": ["Giardino", "Reception", "Magazzino"],  
"nome":"Mario", "cognome":"Rossi"}  
dict_varargs_v1(**d)
```


### Function Decorators
Un decoratore in Python è una funzione che prende in ingresso una funzione e ne  
restituisce una versione “pre o post” processata; permettono di aggiungere codice/funzionalità ad una funzione. 

```python
def funz_decoratrice(f):  
	def inner(a):  
		print("Pre process della funzione")  
		f(a)  
		print("Post process della funzione")  
	return inner  
	
@funz_decoratrice  
def funzione(a):  
	print("Eseguo la funzione con parametro " + str(a))

funzione("args")
```

in Django verranno utilizzati per subordinare le funzionalità delle views (quindi i  
moduli python che dettagliano la logica della nostra applicazione) a logiche di  
preprocessing.

### Python Threads
Come Java, Python mette a disposizione diversi costrutti per il multi-threading. Vedremo solo il più semplice che deriva dal package threading. Un thread viene “creato” specificando la sua funzione “target” e gli argomenti di tale funzione. Una volta creato, verrà eseguito con il metodo “start” ed una volta in esecuzione un altro thread può “aspettare” che finisca.

```python
import threading
import time
def func(a):
    print("Ciao! sono il thread " + threading.current_thread().name + "dormiro per " + str(a) + " secs")
    time.sleep(a)
    print(threading.current_thread().name+": ho finito di dormire")
if __name__ == "__main__":
    NUM_THREADS = 2
    print("Sono il " + threading.current_thread().name  + " e gestiro " + str(NUM_THREADS) + " threads")
    l = []
    for i in range(NUM_THREADS):
        t = threading.Thread(target=func, args=(i+1,))
        t.start()
        l.append(t)
    for t in l: 
        t.join()
    print(threading.current_thread().name  + " ho finito di aspettare i threads")
```

Oltre ai thread, versioni recenti di python (>=3.4) permettono il lancio di funzioni e  
metodi asincroni. Ciò aggiunge una dimensione di parallelismo aggiuntivo, senza necessariamente coinvolgere thread paralleli al main thread della nostra applicazione

```python
import asyncio
def funz():
    print("Funzione sincrona")
    
async def funza(): #indica che la funzione è una co-routine
    print("Funzione asincrona")
    await asyncio.sleep(1) #indica una funzione da “aspettare”
a = funz()
print(type(a))
a = funza() #ad un certo punto questa istruzione solleva un warning...
print(type(a))
input("Premi un tasto per lanciare la funzione async con gather")
a = asyncio.gather(funza()) #schedula ed esegue "awaitable objects" uno dopo l'altro
print(type(a))
#input("Premi un tasto per lanciare la funzione async con run")
    
#a = asyncio.run(funza())
#print(type(a))
```

Perchè abbiamo visto asyncio?  Perché in Django i metodi di risposta asincroni e bidirezionali tra client e server tramite canali e websockets, sfruttando il protocollo ASGI (Asynchronous Server Gateway Interface).