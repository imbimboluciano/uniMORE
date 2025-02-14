package oop.Basics;

import java.util.Collection;
import java.util.Collections;
import java.util.Random;
import java.util.random.RandomGenerator;

/**
 * You can find many more here:
 * https://www.w3resource.com/java-exercises/array/index.php
 *
 * Preferences -> Editor -> General -> Code folding -> One-line methods (uncheck)
 * Code -> Folding -> Collapse All
 * Code -> Folding -> Expand Doc Comments
 */
public class Arrays {
    /**
     * Write a function accepting a double[] and a factor f (double)
     * returning a double[] representing the original double[] divided by f
     */
    public static double[] divideArray(double[] in, double f) {
        double[] ret = new double[in.length];
        for (int i = 0; i < ret.length; i++) {
            ret[i] = in[i] / f;
        }

        return  ret;
    }


    /**
     * Write a function accepting two double[]
     * returning a double[] representing the first array divided by the second array
     * The two arrays must have the same size. Returns null otherwise.
     */
    public static double[] divideArrays(double[] a, double[] b){
        if(a.length == b.length){
            double[] ret = new double[a.length];

            for (int i = 0; i < ret.length; i++) {
                ret[i] = a[i] / b[i];
            }

            return ret;
        }
        return null;
    }


    /*
     * Write a function accepting an int[]
     * returning a sorted version of it (bubble sort)
     */
    static int[] bubbleSort(int[] v) {
        for (int i = 0; i < v.length; i++) {
            boolean scambio = true;
            for (int j = 0; j < v.length - 1; j++) {
                if( v[j] >= v[j + 1]){
                    int tmp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = tmp;
                    scambio = true;
                }
            }
            if(!scambio) break;;
        }
        return v;
    }

    /*
     * Write a function accepting an int
     * returning a long[] composed of the first n numbers of the Fibonacci series (without recursion).
     * In mathematics, the Fibonacci sequence is
     * a sequence in which each number is the sum of the two preceding one; the sequence commonly starts from 0 and 1
     */
    public static long[] fibonacci(int n){
        if (n == 0){
            return null;
        }

        long[] ret = new long[n];
        for (int i = 0; i < ret.length; i++) {
            if(i == 0) {
                ret[i] = 0;
            }else if(i == 1){
                ret[i] = 1;
            }else{
                ret[i] = ret[i - 1] + ret[i - 2];
            }
        }
        return ret;
    }

    /*
     * Write a function accepting an int[]
     * returning an int[] in which all the 0s have been moved to the end of an array.
     * Maintain the relative order of the other (non-zero) elements.
     */
    public static int[] moveZerosEnd(int[] v) {
        int[] ret = new int[v.length];
        int j = 0;
        for (int i = 0; i < ret.length; i++) {
            if(v[i] != 0){
                ret[j] = v[i];
                j++;
            }
        }
        return ret;
    }
    /*
     * Write a function accepting an int
     * returning the sequence of individual digits.
     * (e.g. 363738229 -> [3,6,3,7,3,8,2,2,9])
     */
    public static int[] splitter(int input){
        String sequence = new String(String.valueOf(input));
        int[] ret = new int[sequence.length()];
        for (int i = 0; i < sequence.length(); i++) {
            ret[i] = Character.getNumericValue(sequence.charAt(i));
        }

        return ret;
    }

    /*
    Write a method accepting a double[]
    and returning a copy of the initial double[]
    (see System.arraycopy()).
     */
    public static double[] copyArray(double[] v){

        double[] ret = new double[v.length];
        /*
        for (int i = 0; i < ret.length; i++) {
            ret[i] = v[i];
        }
         */
        System.arraycopy(v,0,ret,0,ret.length);

        return ret;

    }

    /*
    Write a method returning a double[] already filled with values (see java.util.Arrays,
    java.util.random.RandomGenerator).
    * **size** is the size of the new array.
    * **value** is the value to be assigned to all the elements of the new array.
    * **randomize** if true, all the elements have to be randomized adding a random number between [-0.5, 0.5]
     */

    public static double[] fillArray(int size, int value, boolean randomize){

        double[] ret = new double[size];
        if(randomize){
            for (int i = 0; i < ret.length; i++) {
                ret[i] = value + RandomGenerator.getDefault().nextDouble(-0.5,0.5);
            }
        }else{
            java.util.Arrays.fill(ret,value);
        }



        return ret;
    }


    /*
    We'll say that a value is "everywhere" in an array if for every pair of adjacent elements in the
array, at least one of the pair is that value. Return true if the given value is everywhere in the array.
     */

    public static boolean isEveryWhere(int[] v, int value){

        for (int i = 0; i < v.length - 1; i++) {
            if(v[i] != value && v[i + 1] != value){
                return false;
            }
        }
        return true;
    }

    /*
    For each multiple of 10 in the given array, change all the values following it to be that multiple of
10, until encountering another multiple of 10. So {2, 10, 3, 4, 20, 5} yields {2, 10, 10, 10, 20, 20}.
     */

    public static int[] tenRun(int[] v){

        for (int i = 0; i < v.length; i++) {
            if(v[i] % 10 == 0){
                for (int k = i + 1; k < v.length; k++) {
                    if(v[k] % 10 != 0){
                        v[k] = v[i];
                    }else{
                        i = k - 1;
                        break;
                    }
                }
            }
        }
        return java.util.Arrays.copyOf(v,v.length);
    }

    /*
    Consider the series of numbers beginning at **start** and running up to but not including **end**.
    For example start=1 and end=5 gives the series 1, 2, 3, 4. Return a new String[] array containing the string form of
    these numbers. For multiples of 3, use "Fizz" instead of the number, for multiples of 5 use "Buzz", and for multiples of
    both 3 and 5 use "FizzBuzz" (see Integer.toString()).
     */

    public static String[] fizzBuzz(int start, int end){

        String[] s = new String[end - 1];

        for (int i = start; i < end; i++) {
            if(i % 3 == 0){
                if(i % 5 == 0){
                    s[i - 1] = "FizzBuzz";
                }else{
                    s[i - 1] = "Fizz";
                }
            } else if (i % 5 == 0) {
                s[i - 1] = "Buzz";
            }else {
                s[i - 1] = Integer.toString(i);
            }
        }
        return s;
    }

    /*
    Given two int[] v1 and v2 of the same length, for every element in v1, consider the corresponding
    element in v2 (at the same index). Return the count of the number of times that the two elements differ by 2 or less,
    but are not equal.
     */


    public static int matchUp(int[] v1, int[] v2){

        int match = 0;
        for (int i = 0; i < v1.length; i++) {
            if(v1[i] != v2[i]){
                if(Math.abs(v1[i] - v2[i]) <= 2){
                    match++;
                }

            }
        }
        return match;

    }


    /*
    Given a non-empty array, return true if there is a place to split the array so that the sum of the
numbers on one side is equal to the sum of the numbers on the other side.
     */

    public static boolean canBalance(int[] v){

        int sumRight = 0;
        int sumLeft = 0;

        for (int i = 0; i < v.length; i++) {
            for (int k = i; k >= 0; k--) {
                sumRight += v[k];
            }

            for (int j = i + 1; j < v.length; j++) {
                sumLeft += v[j];
            }

            if(sumLeft == sumRight){
                return true;
            }
            sumLeft = 0;
            sumRight = 0;
        }
        return false;
    }



    /*
     Given a String[] and a String return true if the String is contained within the String[].
If the String is not present return false. Write two different versions:
(a) uses brute-force search (i.e., which is slow! because tests all elements of the array);
(b) sorts the array and uses binary search (which is much faster!) (see java.util.Arrays)

Both versions should not modify the original array!
     */


    public static boolean containsBruteForce(String[] strings, String searched){
        for (String tmp:
             strings) {
            if(tmp.equals(searched)){
                return true;
            }
        }

        return false;

    }
    public static boolean containsBinary(String[] strings, String searched){
        java.util.Arrays.sort(strings);

        if(java.util.Arrays.binarySearch(strings,searched) >= 0){
            return true;
        }

        return false;
    }

    /*
    Write a method accepting an int[][] and returning a deep copy of the original.
Deep copies differ from shallow copies in that the whole multidimensional array is duplicated instead of the first tier
of pointers only.
     */

    public static int[][] deepCopy(int[][] original){
        int[][] ret = new int[original.length][];
        for (int i = 0; i < original.length; i++) {
            ret[i] = java.util.Arrays.copyOf(original[i],original[i].length);
        }

        return ret;
    }

}