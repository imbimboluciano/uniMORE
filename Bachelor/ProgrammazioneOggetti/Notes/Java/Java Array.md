In [[Java]] gli array sono oggetti composti da una sequenza di variabili dello stesso tipo (possono contenere sia tipi primitivi che riferimenti ad oggetti). Essendo un oggetto deve essere istanziato con l'operatore new e memorizzato nell'heap (la dimensione deve essere definita durante la dichiarazione e non puó essere piú cambiata). Tutti gli elementi dell'array sono inizializzati con il valore di default previsto dal tipo che abbiamo indicato (0 se é un int e null se é un oggetto).

```java
int[] array = new int[16]; //inizializzazione classica (dichiarazione)
int[] array = {1,2,3,4,5}; //inizializzazione statica (creazione)
String[]  = new String[6]; // array di riferimenti ad oggetti String
```


### Usare gli Array

Una volta creato l'array, possiamo accedere ai singoli elementi indicandone la posizione, grazie all'operatore '`[]`' (bisogna ricordare che gli elementi sono numerati a partire da zero).

```java
int[] array = {1,2,3,4,5};
System.out.println(array[3]);
System.out.println(array[0]);
array[2] = 31;
```

La dimensione dell'array é data dall'attributo interno length, il quale descrive la dimensione effettiva e non il numero di elementi contenuto. Non esistendo in Java l'aritmetica dei puntatori, il riferimento ad un array non é un puntatore al primo elemento ma un riferimento all'oggetto array. 

```java
System.out.println(array.length);
System.out.println(array[array.length - 1]);
```

Per scorrere un array possiamo utilizzare i costrutti tipici (for, do-while, while) ma risulta molto utile il costrutto foreach.

```java
double[] ret = new double[v.length];
//explicit index
for (int i = 0; i < ret.length; i++) {  
    ret[i] = i + 1;
}
//implicit index
for (Double tmp : ret) {  
	System.out.println(tmp);
}
```


### Array Multidimensionali 

Java permette anche l'utilizzo di array di array con numero di dimensioni arbitrario e la sintassi per la loro dichiarazione ed allocazione si ottiene semplicemente ripetendo le parentesi quadre tante volte quante il numero di dimensioni.
```java
int[][][] arrayConDimensione3 = new int[4][5][6];
```

### Errori con gli Array

Quando utilizziamo gli array è nostra responsabilità non tentare di accedere ad elementi esterni al range definito.

```java
int l = 5;
int [] a = new int[l];
a[9] = 10;
```

Quando mandiamo in esecuzione di questo pezzo di codice, esso genera un errore di runtime e la JVM, quando chiudiamo di accedere al decimo elemento dell'array, emette una eccezione di tipo ArrayIndexOutOfBoundException.

### Util.Arrays
Possiamo utilizzare la classe java.util.Arrays, la quale é una classe che contiene una serie di funzioni statiche (come se fosse una liberia del linguaggio C), per manipolare gli array ed effettuare operazioni comuni sulle strutture dati (ordinamento, ricerca, ecc...).

```java
int[] arr = {1,3,6,5,89,67};  
java.util.Arrays.sort(arr);  
java.util.Arrays.fill(arr,10);  
System.out.println(java.util.Arrays.binarySearch(arr,3));
int[] copy = java.util.Arrays.copyOf(arr, arr.length);
System.out.println(java.util.Arrays.toString(arr,3));
```

### System.arraycopy()
Un altro metodo molto utile da utilizzare sugli array é arraycopy(), metodo della classe System che ci permette di copiare  un array di origine da una specifica posizione iniziale all'array di destinazione dalla posizione specificata.

```java
System.arraycopy(src,0,dest,0,lenght);
```
