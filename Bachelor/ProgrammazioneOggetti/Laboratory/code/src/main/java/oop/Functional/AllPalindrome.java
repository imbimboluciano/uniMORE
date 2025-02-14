package oop.Functional;


import oop.Basics.Strings;

import java.util.List;
import java.util.stream.Collectors;

public class AllPalindrome {

    /*
    Given a list of strings, return true if all strings are palindrome.
     */

    public static boolean allPalindrome(List<String> strings){

        return strings.stream().filter(Strings::isPalindrome).toList().size() == strings.size();
    }

}
