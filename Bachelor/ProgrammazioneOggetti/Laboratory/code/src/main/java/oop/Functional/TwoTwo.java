package oop.Functional;

import java.util.List;
import java.util.stream.Collectors;

public class TwoTwo {

    /*
    Given a list of non-negative integers, return a list of those numbers multiplied by 2, omitting any of
the resulting numbers that end in 2 (see Stream.map(), Stream.filter(), Stream.collect()).
     */

    public static List<Integer> twoTwo(List<Integer> nums){
        return nums.stream().map(n -> n * 2).filter(n -> n % 10 != 2).collect(Collectors.toList());
    }
}
