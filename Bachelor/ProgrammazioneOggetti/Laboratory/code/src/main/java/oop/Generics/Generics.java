package oop.Generics;

import java.util.*;
import java.util.random.RandomGenerator;

/**
 * You can find many more here:
 *
 *
 * Preferences -> Editor -> General -> Code folding -> One-line methods (uncheck)
 * Code -> Folding -> Collapse All
 * Code -> Folding -> Expand Doc Comments
 */
public class Generics {
    /**
     * Write a function to fill a generic list with the same object (without using java.util.Collections methods)
     */
    public static <T> void fill(List<? super T> list, T obj) {
        for(int i = 0; i < list.size();i++){
            list.set(i,obj);
        }
    }

    /**
     * Write a function to copy a generic list inside another generic list (without using java.util.Collections methods)
     */
    public static <T> void copy(List<? super T> dest, List<? extends T> src) {
        if(dest.size() != src.size()){
            throw new ArrayIndexOutOfBoundsException("size are differents");
        }
        for(int i = 0; i < src.size();i++){
            dest.set(i, src.get(i));
        }
    }

    /**
     * Write a function to swap 2 elements within a generic list (without using java.util.Collections methods)
     */
    public static void swap(List<?> list, int i, int j) {
       final List l = list; // dobbiamo riportare la lista a pre generics
       l.set(i,l.set(j,list.get(i))); // set the element previously at the specified position
    }

    /**
     * Write a function to shuffle a generic list (without using java.util.Collections methods)
     */
    public static void shuffle(List<?> list) {
        Random rm = new Random();
        for (int i = 0; i < list.size(); i++) {
            swap(list,i, rm.nextInt(0, list.size()));
        }

    }

    /**
     * Write a function to reverse a generic list (without using java.util.Collections methods)
     */
    public static void reverse(List<?> list) {
        for (int i = 0; i < (Math.floor((double) list.size() / 2)); i++) {
            swap(list,i,list.size() - i - 1);
        }
    }

    /**
     * Write a function to find the minimum within a generic Collection of comparable objects (without using java.util.Collections methods)
     * Note well: The Collection interface does not support indexing (e.g., get(index)...)!
     */
    public static <T extends Comparable<? super T>> T min(Collection<T> list) {
        Iterator<T> i = list.iterator();
        T min = i.next();
        while(i.hasNext()){
            T tmp = i.next();
            if((tmp.compareTo(min)) < 0){
                min = tmp;
            }
        }

        return min;
    }

    /**
     * Write a function to find the maximum within a generic List of Comparable objects (without using java.util.Collections methods)
     */
    public static <T extends Comparable<? super T>> T max(List<T> list) {
        Iterator<T> i = list.iterator();
        T max = i.next();
        while(i.hasNext()){
            T tmp = i.next();
            if((tmp.compareTo(max)) > 0){
                max = tmp;
            }
        }

        return max;
    }

    /**
     * Write a function to find the maximum within a generic List of objects using an external Comparator (without
     * using java.util.Collections methods)
     */
    public static <T> T max(List<T> list, Comparator<? super T> cmp) {
        Iterator<T> i = list.iterator();
        T max = i.next();
        while(i.hasNext()){
            T tmp = i.next();
            if(cmp.compare(tmp,max) > 0){
                max = tmp;
            }
        }

        return max;
    }

    /**
     * Write a function to sort a generic list using Bubble Sort (without using java.util.Collections methods)
     */
    public static <T extends Comparable<? super T>> void sort(List<T> list) {
        boolean scambio = true;
        while(scambio){
            scambio = false;
            for (int i = 0; i < list.size() - 1; i++) {
                T tmp = list.get(i);
                if(tmp.compareTo(list.get(i + 1)) > 0){
                    swap(list,i,i+1);
                    scambio = true;
                }
            }
        }
    }

    /**
     * Write a function returning the floating point division of any two numbers regardless of their type
     * Note: Use the java.lang.Number class
     */
    public static <T extends Number> double divide(T a, T b){

        return a.doubleValue() / b.doubleValue();
    }

    /**
     *  Write a generic static method counting all occurrences of a specific item of type T within a T[].
     * It the passed item is null, the method should return the number of null values within the array.
     */
    public static <T> int countOccurrences(T[] src, T item) {
        int occurrences = 0;
        if(item == null){
            for (T tmp: src) {
                if(tmp == item){
                    occurrences++;
                }
            }
        } else{
            for (T tmp: src) {
                if(tmp.equals(item)){
                    occurrences++;
                }
            }
        }
        return occurrences;
    }

    /*
    Write a generic static method returning a
    string representing all the elements of an object
    implementing the Iterable interface. The elements should be separated by commas.
     */

    public static <E> String printIterable(Iterable<E> src){
        StringBuilder sb = new StringBuilder();

        for (Iterator<E> i = src.iterator();i.hasNext();){
            sb.append(i.next()).append(", ");
        }
        /*
        for (E tmp : src){
            sb.append(tmp).append(",");
        }
         */

        return sb.toString();
    }


    public static <T> void append(List<T> a, List<T> b){
        a.addAll(b);
    }


    /*
     Modify the exercise Append.java so that the b list can contain elements of a subclass. For
     example, if people is a list of Person objects and students is a list of Student objects, then append(people, students)
     should compile but append(students, people) should not. The prototype of the method is not reported because it is the
     answer.
     */
    public static <T> void appendBounded(List<T> a, List<? extends T> b){
        a.addAll(b);
    }



    /*
    Write a generic static method that, given a Map<K, V>, returns a List<Pair<K, V>> of the key/value
    pairs in the map. The method has the following prototype:
     */

    public static <K, V> List<Pair<K, V>> mapToPairs(Map<K, V> src){
        List<Pair<K,V>> list = new ArrayList<>();

        for (K tmp: src.keySet()) {
            list.add(new Pair<>(tmp,src.get(tmp)));
        }

        return list;
    }

    /*
    Make the Measurer interface (see below) into a generic interface. Additionally, implement two static
    generic methods returning the maximum and minimum values of the array (see prototype below). The Measurer object
    provides the sorting criteria.
     */

    public static <T> T max(T[] values, Measurer<T> measurer){
        T max = values[0];

        for (int i = 1; i < values.length ; i++) {
            if(measurer.measure(values[i]) > measurer.measure(max)){
                max = values[i];
            }
        }
        return max;
    }
    public static <T> T min(T[] values, Measurer<T> measurer){
        T min = values[0];

        for (int i = 1; i < values.length ; i++) {
            if(measurer.measure(values[i]) < measurer.measure(min)){
                min = values[i];
            }
        }
        return min;
    }

}
