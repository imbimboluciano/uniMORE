package oop.ObjectOriented;

/*Write a class named EnhancedResizableArray representing a resizable array. It internally keeps an int array, enlarges it when needed, and provides its key functionalities via a set of methods:

public EnhancedResizableArray() creating an empty resizable array (the underlying int[] has a default capacity of 4 items).
public int get(int index) returning the element at the specified index.
public void set(int index, int value) setting the element at the specified index with value. If the underlying int[] capacity is smaller than index, a new int[] (with a capacity of index * 2 items) have to be allocated. All the newly allocated elements have to be set to 0.
public boolean contains(int value) returning true if the specified value is contained within the internal array.
public void fill(int) setting all the elements of the internal array to the specified value.
public int length() returning the capacity of the internal array.
public int[] toArray() returning a copy of the internal array. */


import java.util.Arrays;

public class EnhancedResizableArray {

    private final int default_capacity = 4;

    private int[] v;

    public EnhancedResizableArray() {
        v = new int[default_capacity];
    }

    public int get(int index){
        return v[index];
    }

    public void set(int index,int value){
        if(index >= v.length) {
            int[] tmp = new int[index * 2];
            System.arraycopy(v, 0, tmp, 0, v.length);
            v = tmp;
        }
        v[index] = value;
    }

    public boolean contains(int value){
        for (int i = 0; i < v.length; i++) {
            if(value == v[i]){
                return true;
            }
        }
        return false;
    }

    public void fill(int value){
        Arrays.fill(v,value);
    }

    public int length(){
        return v.length;
    }

    public int[] toArray(){
        return Arrays.copyOf(v,v.length);
    }
}
