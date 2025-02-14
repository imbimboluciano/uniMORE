Essendo [[Java]] un linguaggio ad oggetti le stringhe, a differenza del C, non sono sequenze di caratteri ma istanze della Classe String. Quindi possiamo definire le stringhe come degli oggetti che mantengono una sequenza di caratteri alfanumerici. Per via della loro natura ad oggetto le stringhe sono immutabili e quindi i valori delle istanze non possono essere modificati.

```java
String s1 = "ciao"; //allocazione C-likes
String s2 = new String("hello");
```


Alla classe String sono associati tantissimi metodi, tra i piú importanti troviamo:

```java
String string = new String("Hello");  

System.out.println(string.length()); // 5 
System.out.println(string.substring(1,3)); // el  
System.out.println(string.charAt(1));  // e
System.out.println(string.toLowerCase());  // hello
System.out.println(string.toUpperCase());  // HELLO
System.out.println(string.indexOf("e")); // 1
```


### Confronto tra stringhe

Il confronto tra stringhe può essere fatto con l'operatore == solo se entrambe vengono allocate C-like (sono memorizzate in un pool di memoria speciale in cui la stessa stringa viene memorizzata una sola volta).

```java
String s1 = " ciao ";  
String s2 = " ciao ";  
if ( s1 == s2 ) { 
	System.out.println(" Le due stringhe sono uguali ");  
}
```

Se volessimo confrontare due oggetti String dovremmo utilizzare il metodo equals(), il quale confronta il contenuto dei 2 oggetti. L'operatore == applicato agli oggetti confronta solo i riferimenti agli oggetti.

```java
String s3 = new String ( " Hello " );  
String s4 = new String ( " Hello " );  
if ( s1 == s2 ) { // non funziona perche ' confronta i riferimenti  
	System.out.println(" Le due stringhe sono uguali");  
} 
if ( s1.equals(s2) ) {  
	System.out.println(" Le due stringhe sono uguali ");
}
```

### Concatenazione stringhe

Una delle operazioni piu comuni eseguita sulle stringhe é la concatenazione. Possiamo eseguire questa operazione in diversi modi.

1. **Operatore +**, concatenazione lenta e molto dispendiosa dal punto di vista prestazionale (quando due stringhe vengono concatenate usando +, le due stringhe vengono effettivamente scartate e ne viene istanziata una nuova contenente la loro concatenazione).
```java
String string = new String("Hello");
String result = new String();  
for (int i = 0; i < string.length(); i++) {  
    result += string.charAt(i);  
}
```

2. [[StringBuilder]] (anche StringBuffer ormai deprecato)
```java
String string = new String("Hello");
StringBuilder sb = new StringBuilder();  
for (Character c:  
     string.toCharArray()) {  
    sb.append(c);  
}

System.out.println(sb.toString()); //Hello
```


### Operazioni con le stringhe

Vediamo ora i principali metodi della classe String.
```java
String s = new String("Hello"); 

// Returns the character at the specified index (position)
System.out.println(s.charAt(0));  // H

// Compares two strings lexicographically
System.out.println(s.compareTo("hello")); // -32

//Appends a string to the end of another string
System.out.println(s.concat("World"));  // HelloWorld

//Checks whether a string ends with the specified character(s)
System.out.println(s.endsWith("lo"));  // true

//Checks whether a string starts with specified characters
System.out.println(s.startsWith("He"));  // true

//Checks whether a string is empty or not
System.out.println(s.isEmpty());  // false

//Returns the length of a specified string
System.out.println(s.length());  // 5

//Returns a new string which is the substring of a specified string
System.out.println(s.substring(2,3)); //  l

//Returns the string representation of the specified value
System.out.println(String.valueOf(5));  // 5

//Searches a string for a specified value, and returns a new string where those values are replaced
System.out.println(s.replace('l','c')); // Hecco

//Checks whether a string contains a sequence of characters
System.out.println(s.contains("e")); //true

//Splits a string into an array of substrings 
String amici = "Mario,Luca,Claudio";  
if (amici.contains(",")) {  // checks if there is that separator in the string
    String[] nomi = amici.split(",");  
    for (int i = 0; i < nomi.length; i++) {  
        System.out.println(nomi[i]);  // Mario Luca Claudio
    }  
}

```