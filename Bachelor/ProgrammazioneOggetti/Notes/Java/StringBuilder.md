StringBuilder é una classe che rappresenta una sequenza mutevole di caratteri. Questa classe è progettata per essere utilizzata come sostituto immediato di StringBuffer nei punti in cui il buffer delle stringhe veniva utilizzato da un singolo thread. Vediamo i principali metodi.

1. **Append**, converte il dato fornito in una stringa e poi lo accoda
```java
String string = new String("Hello");
StringBuilder sb = new StringBuilder();  
for (Character c:  
     string.toCharArray()) {  
    sb.append(c);  
}

System.out.println(sb.toString()); //Hello
```

2. **Reverse**
```java
public static String reverse(String s) {  
    return new StringBuilder(s).reverse().toString();
}
```

3. **Remove**
```java
public static String removeFirstTwoChars(String s) {  
    return new StringBuilder(s).delete(0,2).toString();  
}
```