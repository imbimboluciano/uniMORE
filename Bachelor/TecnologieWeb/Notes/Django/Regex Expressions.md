Un'espressione regolare (regular expression o regex) è una sequenza di caratteri che identifica tramite un meccanismo di pattern matching un insieme di stringhe. In parole povere, una regex stabilisce una serie di regole che una stringa deve seguire al fine di fare “match” con il pattern descritto dalla regex stessa. Un motore di regex prende in ingresso un’espressione regolare e una stringa da controllare e restituisce se esiste una corrispondenza.
```python
re_path(r'^$|^/$|^home/$',home_page,name = "homepage")
```

r specifica che la stringa che segue è una regex, ^ indica l'inizio della stringa, $ fine della stringa e con | indichiamo una alternativa.

Cos’altro possiamo fare con le regex?  Possiamo controllare l'input dell’utente per costringerlo ad inserire stringhe ben formattate.

```txt
^[A-Z][a-z]+\s[A-Z][a-z]+$
```

Possiamo testare le regex su https://regex101.com/




