package oop.Collections;

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
public class Sets {
    /**
     * Write a function returning the intersection of two given sets (without using library functions)
     */
    public static Set<Integer> intersection_manual(Set<Integer> first, Set<Integer> second) {
        Set<Integer> ret = new HashSet<>();
        for (Integer i: first) {
            if(second.contains(i)){
                ret.add(i);
            }
        }
        return ret;
    }

    /**
     * Write a function returning the union of two given sets (without using library functions)
     */
    public static Set<Integer> union_manual(Set<Integer> first, Set<Integer> second) {
        Set<Integer> s = new HashSet<>();
        for (int i:
             first){
            s.add(i);
        }
        for (int i:
             second) {
            s.add(i);
        }

        return s;
    }

    /**
     * Write a function returning the intersection of two given sets (see retainAll())
     */
    public static Set<Integer> intersection(Set<Integer> first, Set<Integer> second) {
        Set<Integer> s = new HashSet<>(first);
        s.retainAll(second);
        return s;
    }

    /**
     * Write a function returning the union of two given sets (see addAll())
     */
    public static Set<Integer> union(Set<Integer> first, Set<Integer> second) {
        Set<Integer> s = new HashSet<>(first);
        s.addAll(second);
        return s;
    }

    /**
     * Write a function to transform a set into a list without duplicates
     * Note well: collections can be created from another collection!
     */
    public static List<Integer> toList(Set<Integer> source) {
        return new ArrayList<>(source);
    }

    /**
     * Write a function to remove duplicates from a list
     * Note well: collections can be created from another collection!
     */
    public static List<Integer> removeDuplicates(List<Integer> l) {
        return new ArrayList<>(new HashSet<>(l));
    }

    /**
     * Write a function to remove duplicates from a list without using the constructors trick seen above
     */
    public static List<Integer> removeDuplicates_manual(List<Integer> l) {
        Set<Integer> unique = new HashSet<>();
        List<Integer> list = new ArrayList<>();
        for(int i : l){
            if(!unique.contains(i)){
                unique.add(i);
                list.add(i);
            }
        }
        return list;
    }

    /**
     * Write a function accepting a string s
     * returning the first recurring character
     * For example firstRecurringCharacter("abaco") -> a.
     */
    public static String firstRecurringCharacter(String s) {
        Set<Character> unique = new HashSet<>();
        for(char c : s.toCharArray()) {
            if (unique.contains(c)) {
                return Character.toString(c);
            } else {
                unique.add(c);
            }
        }
        return null;
    }

    /**
     * Write a function accepting a string s, and returning a set comprising all recurring characters.
     * For example allRecurringChars("mamma") -> [m, a].
     */
    public static Set<Character> allRecurringChars(String s) {
        Set<Character> unique = new HashSet<>();
        Set<Character> set = new HashSet<>();
        for(char c : s.toCharArray()) {
            if (unique.contains(c)) {
                set.add(c);
            } else {
                unique.add(c);
            }
        }
        return set;
    }

    /**
     * Write a function to transform a set into an array
     */
    public static Integer[] toArray(Set<Integer> source) {
        return source.toArray(new Integer[0]);
    }

    /**
     * Write a function to return the first item from a TreeSet
     * Note well: use TreeSet specific methods
     */
    public static int getFirst(TreeSet<Integer> source) {
        return source.first();
    }

    /**
     * Write a function to return the last item from a TreeSet
     * Note well: use TreeSet specific methods
     */
    public static int getLast(TreeSet<Integer> source) {
        return source.last();
    }

    /**
     * Write a function to get an element from a TreeSet which is strictly greater than a given element.
     * Note well: use TreeSet specific methods
     */
    public static int getGreater(TreeSet<Integer> source, int value) {
         return source.higher(value);
    }

    /*
    Write a method accepting a string and returning a set comprising all recurring characters of
    the string.
     */

    public static Set<Character> recurringChars(String string){
        Set<Character> recurring = new HashSet<>();
        Set<Character> noRecurring = new HashSet<>();

        for (Character c: string.toCharArray()) {
            if(noRecurring.contains(c)){
                recurring.add(c);
            }else{
                noRecurring.add(c);
            }
        }

        return recurring;
    }


    /*
    Implement the sieve of Eratosthenes: a method for computing prime numbers, known to the ancient Greeks.
    This method will compute all prime numbers up to n. Choose an n. First insert all numbers from 1 to n into a set.
    Then erase all multiples of 2 (except 2); that is, 4, 6, 8, 10, 12, . . . . Erase all multiples of 3; that is, 6, 9, 12, 15, . . . . Go up to sqrt(n). Then return the set.
     */

    public static Set<Integer> eratosthenes(int n){
        Set<Integer> sEra = new HashSet<>();

        for (int i = 2; i <= n; i++) {
            sEra.add(i);
        }

        for (int i = 2; i <= (int)Math.sqrt(n); i++) {
            for (Iterator<Integer> j = sEra.iterator();j.hasNext();) {
                int tmp = j.next();
                if(tmp % i == 0 && tmp != i){
                    j.remove();
                }
            }
        }

        return sEra;
    }

    public static String wordAfterWord (String filename, String word) throws IOException{
        TreeSet<String> set = new TreeSet<>();
       List<String> lines = Files.readAllLines(Path.of(filename));
        for (String tmp: lines) {
           set.addAll(Arrays.asList(tmp.replaceAll("[^a-zA-Z ]", "").toLowerCase().split("\\s+")));
        }

        return set.tailSet(word,false).first();
    }





}