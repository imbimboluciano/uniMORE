package oop.Generics;

import oop.Generics.Pair;
public class PairUtil {

    /*
        Write a generic static method whose argument is a Pair object. The method returns a new pair, with the first and second element swapped.
     */

    public static <K, V> Pair<V, K> swap(Pair<K, V> src){
        return new Pair<>(src.getSecond(), src.getFirst());
    }

}
