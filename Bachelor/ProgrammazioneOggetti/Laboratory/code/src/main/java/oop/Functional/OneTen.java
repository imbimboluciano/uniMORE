package oop.Functional;

import java.util.List;
import java.util.stream.Collectors;

public class OneTen {

    /*
     Given a list of integers, return a list where each integer is added to 1 and the result is multiplied by 10.
     */
    public static List<Integer> oneTen(List<Integer> nums){
        return nums.stream().map(n -> n + 1).map(n -> n * 10).collect(Collectors.toList());

    }
}
