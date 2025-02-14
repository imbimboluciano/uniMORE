package oop.Functional;

import java.util.List;
import java.util.function.Predicate;
import java.util.stream.Collector;
import java.util.stream.Collectors;

public class NoTeen {

    /*
    Given a list of integers, return a list of those numbers, omitting any that are between 13 and 19
inclusive (see Stream.filter(), Stream.collect()).
     */

    public static List<Integer> noTeen(List<Integer> nums){
       return nums.stream().filter(n -> n < 13 || n > 19).collect(Collectors.toList());
    }
}
