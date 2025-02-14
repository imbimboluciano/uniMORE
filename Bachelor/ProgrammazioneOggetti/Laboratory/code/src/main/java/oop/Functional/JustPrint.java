package oop.Functional;

import java.util.List;
import java.util.function.Consumer;
import java.util.stream.Stream;

public class JustPrint {

    /*
    Given a list of String, print all the elements using the Stream approach (see Stream.forEach()).
     */

    public static void justPrint(List<String> strings){
        strings.stream().forEach(System.out::println);
    }
}
