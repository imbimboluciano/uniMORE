package oop.Functional;

import java.util.List;
import java.util.stream.Collectors;

public class NoYY {

    /*
    Given a list of strings, return a list where each string has "y" added at its end, omitting any
resulting strings that contain "yy" as a substring anywhere.
     */

    public static List<String> noYY(List<String> strings){
        return strings.stream().map(s -> s + "y").filter(s -> !s.contains("yy")).collect(Collectors.toList());
    }
}
