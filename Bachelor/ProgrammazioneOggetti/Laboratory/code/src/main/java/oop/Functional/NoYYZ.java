package oop.Functional;

import java.util.List;
import java.util.stream.Collectors;

import static java.util.stream.Collectors.toList;

public class NoYYZ {

    /*
    Given a list of strings, return a list where each string has "y" added at its end, omitting any
resulting strings that contain "yy" as a substring anywhere.
Nevertheless, each string starting with "z" has to printed to standard output. (see Stream.peek())
     */

    public static List<String> noYYZ(List<String> strings){
        return strings.stream().map(s -> s + "y").filter(s -> !s.contains("yy")).peek(s -> {
            if (s.startsWith("z")) {
                System.out.println(s);
            }
        }).toList();
    }
}
