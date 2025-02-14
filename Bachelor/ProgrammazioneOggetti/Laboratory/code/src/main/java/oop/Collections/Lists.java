package oop.Collections;


import java.util.*;

/**
 * You can find many more here:
 * https://www.w3resource.com/java-exercises/collection/index.php
 *
 * Preferences -> Editor -> General -> Code folding -> One-line methods (uncheck)
 * Code -> Folding -> Collapse All
 * Code -> Folding -> Expand Doc Comments
 */
public class Lists {

    /**
     * Write a function to insert an element into a list at the beginning
     */
    public static void insertFirst(ArrayList<Integer> list, int value) {
        list.add(0,value);
    }

    /**
     * Write a function to insert an element into a list at the end
     */
    public static void insertLast(ArrayList<Integer> list, int value) {
        list.add(list.size(), value);
    }

    /**
     * Write a function to replace the 3rd element of a list with a given value
     */
    public static void replace(ArrayList<Integer> list, int value) {
        list.set(2,value);
    }

    /**
     * Write a function to remove the 3rd element from a list
     */
    public static void removeThird(ArrayList<Integer> list) {
        list.remove(2);
    }

    /**
     * Write a function to remove the element "666" from a list
     */
    public static void removeEvil(ArrayList<Integer> list) {
        list.remove(Integer.valueOf("666"));
    }

    /**
     * Write a function returning a ArrayList<Integer> containing the first
     * 10 square numbers (i.e., 1, 4, 9, 16, ...)
     */
    public static ArrayList<Integer> generateSquare() {
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 1; i <= 10; i++) {
            list.add((int)Math.pow(i,2));
        }
        return list;
    }

    /**
     * Write a function to verify if a list contains a certain value
     */
    public static boolean contains(ArrayList<Integer> list, int value) {
        return list.contains(value);
    }

    /**
     * Write a function to copy a list into another list (without using library functions)
     * Note well: the target list must be emptied before the copy
     */
    public static void copy(ArrayList<Integer> source, ArrayList<Integer> target) {
        target.clear();
        for(int i : source){
            target.add(i);
        }
    }

    /**
     * Write a function to reverse the elements of a list (using java.util.Collections methods)
     */
    public static void reverse(ArrayList<Integer> list) {
        Collections.reverse(list);
    }

    /**
     * Write a function to reverse the elements of a list (without using java.util.Collections methods)
     */
    public static void reverseManual(ArrayList<Integer> list) {
        for (int i = 0; i < (Math.floor((double) (list.size() / 2))); i++) {
            int tmp = list.get(list.size() - i - 1);
            list.set(list.size() - i - 1, list.get(i));
            list.set(i,tmp);
        }
    }

    /**
     * Write a function to insert the same element both at the beginning and the end of the same LinkedList
     * Note well: you can use LinkedList specific methods
     */
    public static void insertBeginningEnd(LinkedList<Integer> list, int value) {
        list.addFirst(value);
        list.addLast(value);
    }

    /*
    Write a method that removes every nth String from a List<String>.

    downSize(["A", "B", "C", "D", "E", "F"], 2) -> ["A", "C", "E"]
    downSize(["A", "B", "C", "D", "E", "F"], 3) -> ["A", "B", "D", "E"]
     */
    public static void downsize(List<String> list, int n){
        int j = 1;
        for (Iterator<String> i = list.iterator(); i.hasNext();) {
            i.next();
            if(j % n == 0){
                i.remove();
            }
            j++;
        }

    }






}
