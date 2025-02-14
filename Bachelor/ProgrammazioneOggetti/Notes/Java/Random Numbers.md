Per la generazione di numeri casuali in [[Java]] possiamo utilizzare diversi metodi di differenti classi.

1. **Math.random()**
2. **java.util.Random**
```java
Random random = new Random();
random.nextInt();
random.nextDouble();
random.nextBoolean();
```

3. **java.util.random.RandomGenerator**
```java
RandomGenerator generator = RandomGenerator.getDefault();
generator.nextInt();
generator.nextDouble();
generator.nextBoolean();
```

4. **java.util.concurrent.ThreadLocalRandom**
```java
ThreadLocalRandom.nextInt();
ThreadLocalRandom.nextDouble();
```
