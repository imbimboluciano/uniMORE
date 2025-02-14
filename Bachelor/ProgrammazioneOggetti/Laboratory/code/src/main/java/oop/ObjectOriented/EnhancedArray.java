package oop.ObjectOriented;

import java.util.Arrays;
import java.util.random.RandomGenerator;

/*
Write a class named EnhancedArray representing an enhanced array.
Internally, the class keeps an int array but provides its key functionalities via a set of methods:

* public EnhancedArray(int capacity) creating a new array of the specified capacity.
* public int size() returning the capacity of the array.
* public int get(int index) returning the element at the specified index.
* public void set(int index, int value) setting the element at the specified index with value.
* public boolean contains(int value) returning true if the specified value is contained within the array.
* public void resetZero() setting all the elements to 0.
* public void resetRandom() setting all the elements to random values between [0, size()].
* public int[] toArray() returning a copy of the internal array.
 */

public class EnhancedArray {

    int[] v;

    public EnhancedArray(int capacity) {
        this.v = new int[capacity];
    }

    public int size(){
        return v.length;
    }

    public int get(int index){
        return v[index];
    }

    public void set(int index, int value){
        v[index] = value;
    }

    public boolean contains(int value){
        for (int i = 0; i < v.length; i++) {
            if(v[i] == value){
                return true;
            }
        }

        return false;
    }

    public void resetZero(){
        Arrays.fill(v,0);
    }

    public void resetRandom(){
        for (int i = 0; i < v.length; i++) {
            v[i] = RandomGenerator.getDefault().nextInt(0,size());
        }
    }

    public int[] toArray(){
        return v;
    }


}



