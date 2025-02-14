package oop.Collections;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.*;

/**
 * You can find many more here:
 * https://www.w3resource.com/java-exercises/collection/index.php
 *
 * Preferences -> Editor -> General -> Code folding -> One-line methods (uncheck)
 * Code -> Folding -> Collapse All
 * Code -> Folding -> Expand Doc Comments
 */
public class Maps {
    /**
     * Write a function to return the number of key-value mappings of a  map
     */
    public static int count(Map<Integer, Integer> map) {
        return map.size();
    }

    /**
     * Write a function to remove all mappings from a map
     */
    public static void empty(Map<Integer, Integer> map) {
       map.clear();
    }

    /**
     * Write a function to test if a map contains a mapping for the specified key
     */
    public static boolean contains(Map<Integer, Integer> map, int key) {
        return map.containsKey(key);
    }

    /**
     * Write a function to test if a map contains a mapping for the specified key and if its value equals the
     * specified value
     */
    public static boolean containsKeyValue(Map<Integer, Integer> map, int key, int value) {
        if(map.containsKey(key)){
            return map.get(key) == value;
        }
        return false;
    }

    /**
     * Write a function to return the key set of map
     */
    public static Set<Integer> keySet(Map<Integer, Integer> map) {
        return map.keySet();
    }

    /**
     * Write a function to return the values of a map
     */
    public static Collection<Integer> values(Map<Integer, Integer> map) {
        return map.values();
    }

    /**
     * Write a function, internally using a map, returning "black", "white", or "red" depending on int input value.
     * "black" = 0, "white" = 1, "red" = 2
     */
    public static String getColor(int value) {
        
        HashMap<Integer,String> m = new HashMap<>();
        m.put(0,"black");
        m.put(1,"white");
        m.put(2,"red");

        return m.get(value);
    }


     /*
    Write a static method accepting a String, converting it to lowercase, and returning its [Morse](https://en.wikipedia.org/wiki/Morse_code) translation.
You have to use a ```Map<Characher, String>>``` as a conversion table (dot='.', dash='_').
     */

    public static String morseCode(String string){
        Map<Character, String> morseMap = new HashMap<>();
        morseMap.put('a',"._");
        morseMap.put('b',"_...");
        morseMap.put('c',"._._");
        morseMap.put('d',"_..");
        morseMap.put('e',".");
        morseMap.put('f',".._.");
        morseMap.put('g',"__.");
        morseMap.put('h',"....");
        morseMap.put('i',"..");
        morseMap.put('j',".___");
        morseMap.put('k',"_._");
        morseMap.put('l',"._..");
        morseMap.put('m',"__");
        morseMap.put('n',"_.");
        morseMap.put('o',"___");
        morseMap.put('p',".__.");
        morseMap.put('q',"__._");
        morseMap.put('r',"._.");
        morseMap.put('s',"...");
        morseMap.put('t',"_");
        morseMap.put('u',".._");
        morseMap.put('v',"..._");
        morseMap.put('w',".__");
        morseMap.put('x',"_.._");
        morseMap.put('y',"_.__");
        morseMap.put('z',"__..");

        StringBuilder sb = new StringBuilder();
        for (Character tmp: string.toLowerCase().toCharArray()) {
            sb.append(morseMap.get(tmp)).append(' ');
        }

        return sb.substring(0,sb.length() - 1);

    }


    /*
    Write a static method accepting a ```Map<String, String>``` and returning true if some values have been used as keys as well.
     */

    public static boolean valuesKeys(Map<String, String> map){

        for (String tmp: map.values()) {
            if(map.containsKey(tmp)){
                return true;
            }
        }
        return false;

    }

    /*
    Write a static method accepting a ```Map<Integer, String>``` and returning a ```Map<String, Integer>``` in which the original keys and values have been inverted.
    In case of repeated values (thus associated to multiple keys) you can select one of the keys.
     */

    public static Map<String, Integer> invertMap(Map<Integer, String> src){

        Map<String,Integer> invertedMap = new HashMap<>();

        for (Integer tmp:
                src.keySet()) {
            invertedMap.put(src.get(tmp),tmp);
        }
        return invertedMap;
    }

    /*
    Write a method, reading all the lines of the file and returning a ```Map<String, Integer>``` having all the unique words
    of the book as keys, associated with the number of times they appeared.
     */

    public static Map<String, Integer> wordFrequency(String filename) throws IOException {

        Map<String,Integer> frequency = new HashMap<>();
        List<String> lines = Files.readAllLines(Path.of(filename));
        List<String> words = new ArrayList<>();
        for (String tmp: lines) {
            words.addAll(Arrays.asList(tmp.replaceAll("[^a-zA-Z ]", "").toLowerCase().split("\\s+")));
        }

        for (String tmp: words) {
            if(frequency.containsKey(tmp)){
                frequency.put(tmp,frequency.get(tmp) + 1);
            }else{
                frequency.put(tmp,1);
            }
        }

        return frequency;
    }

    /*
    Add two methods to WordFrequency.java for returning a new ```Map<String, Integer>```
    containing only the n most (or less) frequent words and their frequency. Entries within the returned Map, have to be
    sorted by value (i.e. frequency). For sorting, you can transform the ```Map<String, Integer>``` into
    a ```List<Map.Entry<String, Integer>>``` which can be sorted using a ```Comparator<Map.Entry<String, Integer>>```.
    Remember also that LinkedHashMap is an implementation of Map maintaining the insertion order.
     */

    public static Map<String, Integer> mostFrequent(Map<String, Integer> map, int limit){
        return sortAndCut(map, (e1, e2) -> e2.getValue() - e1.getValue(), limit);

    }
    public static Map<String, Integer> lessFrequent(Map<String, Integer> map, int limit){
        return sortAndCut(map, Comparator.comparingInt(Map.Entry::getValue), limit);
    }

    public static Map<String, Integer> sortAndCut(Map<String, Integer> map, Comparator<Map.Entry<String, Integer>> comparator, int limit) {
        List<Map.Entry<String, Integer>> entries = new ArrayList<>(map.entrySet());
        entries.sort(comparator);
        entries = new ArrayList<>(entries.subList(0, limit));

        Map<String, Integer> dst = new LinkedHashMap<>();
        for (Map.Entry<String, Integer> entry : entries) {
            dst.put(entry.getKey(), entry.getValue());
        }
        return dst;
    }


}
