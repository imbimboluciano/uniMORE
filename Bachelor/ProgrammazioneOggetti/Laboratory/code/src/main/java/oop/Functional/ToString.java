package oop.Functional;

import java.util.stream.Collectors;
import java.util.stream.Stream;

public class ToString {

    /*
    Write a method turning a Stream<T> into a comma-separated list of its first n elements (see Collectors.joining())
     */

    public static <T> String toString(Stream<T> stream, int n){
        return stream.limit(n).map(Object::toString).collect(Collectors.joining());

    }
}
