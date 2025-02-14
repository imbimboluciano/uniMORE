package oop.Functional;

import java.util.List;
import java.util.stream.Collectors;

public class SquareFive {

    /*
    Given a list of integers, square those numbers, add 10, omit any of the resulting numbers that end
in 5, and return their number.

     */

    public static long squareFive(List<Integer> nums){
        return nums.stream().map(n -> n * n).map(n -> n + 10).filter(n -> n % 10 != 5).count();
    }
}
