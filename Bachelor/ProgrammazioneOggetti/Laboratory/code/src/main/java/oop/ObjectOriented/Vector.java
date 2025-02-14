package oop.ObjectOriented;

import java.util.Arrays;
import java.util.Random;


/**
 * Write a class named Vector representing a vector of integers with additional features.
 *
 * Supported methods:
 * void init() initialize the vector with random numbers [0, 100]
 * void sort() sorts the vector in ascending order
 * void show() shows the content of the vector
 * int search(int value) returns the index in which "value" is stored. -1 if "value" is missing.
 *
 * @author Nicola Bicocchi
 */
public class Vector {
    int[] v;

    public Vector(int[] v) {
        this.v = v;
    }

    public void init(){
        Random rand = new Random();
        for (int i = 0; i < v.length; i++) {
            v[i] = rand.nextInt(100);
        }
    }

    public void sort(){
        Arrays.sort(v);
    }

    public void show(){
        for (int i = 0; i < v.length; i++) {
            System.out.println(v[i]);
            System.out.println("\t");
        }
    }

    public int search(int value){
        for (int i = 0; i < v.length; i++) {
            if(v[i] == value){
                return i;
            }
        }
        return -1;
    }
}

