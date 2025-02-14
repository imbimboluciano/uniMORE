Tutto in [[Python]] è un oggetto. Le classi forniscono un mezzo per raggruppare dati  
(variabili di classe) e funzionalità (metodi di classe) insieme. La creazione di una nuova  
classe crea un nuovo tipo di oggetto consentendo di creare nuove istanze di  uell’oggetto. Le istanze di classe possono anche avere metodi (definiti dalla sua classe) per modificare il suo stato.

```python
class Test:
	
	a = "variabile di classe"
	# self parola riservata riferimento all'istanza corrente della classe 
	def p(self):
		print('metodo di classe')

t = Test()
t.a #variabile di classe
t.p() #metodo di classe
```

Con il metodo speciale **init** (simile a un costruttore) è possibile creare oggetti con istanze personalizzate per definire uno stato iniziale specifico.

```python
class Persona:

	def __init__(self, nome, cognome):
		self.nome = nome
		self.cognome = cognome
		
	def presentazione(self):
		printf(f'Ciao, mi chiamo {self.nome} {self.cognome}')
```

In Python le classi supportano ereditarietà (inheritance). La classe che eredita si chiama Sub Class, quella che fa ereditare Super Class.

```python
class Lavoratore(Persona):

	def __init__(self, nome, cognome, azienda):
		Persona.__init__(self, nome, cognome)
		self.azienda = azienda
		
	def presentazione_azienda(self):
		printf(f'Lavoro per {self.azienda}')
```

A differenza di Java, in Python non esiste privacy degli attributi. La privacy viene sostituita da “suggerimenti” riguardo l’accesso delle variabili; qesto fa storcere il naso a chi viene da altri linguaggi, perché la protezione delle variabili di classe non può essere risolta con suggerimenti o velate minacce. 

```python
class Classe:  
	def __init__(self,a,b,c):  
		self.a = a  #attributo pubblico
		self._b = b  #suggerimento di non accedere direttamente all'attributo
		self.__c = c #suggerimento di non accedere all'attributo
```

Python risolve comunque questo problema con un meccanismo molto elegante  
che “unisce” le due filosofie: controllo degli accessi delle variabili senza dover imbruttire il codice con getter e setter.  L’annotazione @property crea un alias con “raggio” e  qualsiasi scrittura e lettura di “raggio” è subordinata al codice definito tra le altre annotazioni  @nomeattributo.[getter|setter|deleter]. Chi usa questa classe non dovrà mai chiamare direttamente questi metodi, in quanto verranno eseguiti ogni qualvolta si accede “normalmente” all’attributo raggio di Cerchio. 

```python
class Cerchio:  
	def __init__(self,raggio = 1):  
		self.raggio = raggio 
		 
	def __str__(self):  
		return "Questo cerchio ha raggio " +  str(self.raggio) 
		 
	@property  
	def raggio(self):  
		return self.__raggio  
		
	@raggio.setter  
	def raggio(self,value):  
		if value <= 0:  
			self.__raggio = 1  
			print("Errore!")  
		else: self.__raggio = value  
		
	@raggio.getter  
	def raggio(self):  
		return self.__raggio
```

Altra differenza con Java, in Python non esiste  il concetto di interfaccia, così come non esiste il concetto di classe o metodo astratto. Esistono solo metodi e funzioni “non implementate”. La presenza di metodi non implementati non impedisce all’utente di istanziare comunque un oggetto. Esiste peró “abc” un modulo python che permette la creazione di “vere” classi astratte.

```python
class ClasseAstratta: 

	def __init__(self,a):  
		self.a = a 
		 
	def metodo_astratto(self):  
		raise NotImplementedError("Non sono implementato!")  
```

Come in altri linguaggi anche in Python é possibile definire attributi statici, omettendo la parola riservata "self". 

```python
class Classe:  
	attributo_statico = 10  
	def __init__(self,a)  
		self.attributo_dinamico = a
```

Infine possiamo anche definire metodi statici, i quali  in Python si dividono in due categorie:  
- Metodi statici puri : somigliano molto ai metodi statici di altri linguaggi, come Java e C++ (annotazione @staticmethod)
- Metodi statici di classe: si usano per avere un modo “pulito” per creare factory methods  (annotazione @classmethod)

```python
from datetime import date  

class Persona:  
		def __init__(self, nome, eta):  
			self.nome = nome  
			self.eta = eta  
			print(f"La persona inserita è adulta?  {Persona.maggiorenne(eta)}")  
		
		# un class method che crea una persona  
		#a partire dal suo anno di nascita  
		@classmethod  
		def dalla_nascita(cls, name, year):  
			return cls(name, date.today().year - year)  
		
		# Un metodo statico che ci dice se  
		# una generica persona èmaggiorenne  
		@staticmethod  
		def maggiorenne(eta):  
			return eta > 18
```

Python supporta anche l’ereditarietà multipla (multiple-inheritance) con tutti i problemi che ne conseguono (Django utilizza molto frequentemente l'ereditarietá multipla). 

```python
class Padre:
	def __init__(self, nome):
		self.nome_padre = nome
	
	def mostra_padre(self):
		printf(f'Padre: {self.nome_padre}')

class Madre:
	def __init__(self, nome):
		self.nome_madre = nome
	
	def mostra_madre(self):
		printf(f'Madre: {self.nome_madre}')

class Figlio(Padre, Madre):
	def __init__(self, nome, nome_padre, nome_madre):
		Padre.__init__(self, nome_padre)
		Madre.__init__(self, nome_madre)
		self.nome_figlio = nome
	
	def mostra_famiglia(self):
		print(f'Questa é la mia famiglia: ')
		self.mostra_padre()
		self.mostra_madre()
		print(f'Figlio: {self.nome_figlio}')
```

Facciamo un esempio per capire le vere problematiche di questa feature: Ho una classe A e una classe B; ho una terza classe C che eredita sia da A che da B ma  non ha un costruttore. Chiamerà quello di default.... di A, di B o di entrambi? 
L’ordine dei due “padri” è fondamentale per cercare di prevedere il comportamento della classe derivata! Questo in Python è noto come MRO (Method Resolution Order), non è semplice e si presta a svariate ambiguità (bisogna cercare di evitare queste situazioni).

```python
class A:  
	def __init__(self,a):  
		print("A inizializzato")  
		self.a = a  
		
	def metodo(self):  
		print(f"Sono A e Stampo {self.a}")
		  
	def metodo_specifico_a(self):  
		print("Sono un metodo specifico di A")  
		
class B:  
	def __init__(self,b):  
		print("B inizializzato")  
		self.b = b  
		
	def metodo(self):  
		print(f"Sono B e Stampo {self.b}")

class ClasseABMigliore(A,B):  
	def __init__(self, a=0, b=0):  
		A.__init__(self,a)  
		B.__init__(self,b)  
		
	def metodo(self):  
		A.metodo(self)  
		B.metodo(self)  
		
	def metodo_specifico(self):  
		print(f"Metodo specifico della classe {type(self)} : ", end="")  
		super().metodo_specifico_a()

oggetto3 = ClasseABMigliore(3,4)  
oggetto3.metodo()  
oggetto3.metodo_specifico()  
oggetto3.metodo_specifico_a()

"""A inizializzato  
B inizializzato  
Sono A e Stampo 3  
Sono B e Stampo 4  
Metodo specifico della classe <class '__main__.ClasseABMigliore'> : Sono un metodo specifico di A  
Sono un metodo specifico di A"""
```




