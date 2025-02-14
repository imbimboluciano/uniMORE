package oop.Basics;

import java.util.Arrays;
import java.util.Scanner;

/**
 * You can find many more here:
 * https://www.w3resource.com/java-exercises/string/index.php
 *
 * Preferences -> Editor -> General -> Code folding -> One-line methods (uncheck)
 * Code -> Folding -> Collapse All
 * Code -> Folding -> Expand Doc Comments
 */
public class Strings {
    /**
     * Write a function accepting a string[]
     * returning a single String representing the concatenation of all Strings of the array
     * see StringBuilder
     */
    public static String concatenate(String[] strings) {

        // with StringBuilder
        StringBuilder sb = new StringBuilder();
        for (String tmp: strings) {
            sb.append(tmp);
        }
        return sb.toString();

        //with StringBuffer (old)
        /* StringBuffer sb = new StringBuffer();
        for (String tmp: strings) {
            sb.append(tmp);
        }
        return sb.toString(); */

        // with String
        /*String ret = new String();
        for (String tmp : strings) {
            for (Character c:
                 tmp.toCharArray()) {
                ret += c;
            }
        }
        return ret;*/


    }

    /**
     * Write a function accepting a string
     * returning the same string but reversed
     */
    public static String reverse(String s) {
        //return  new StringBuilder(s).reverse().toString();

        StringBuilder sb = new StringBuilder();
        for (int i = s.length() - 1; i >= 0 ; i--) {
            sb.append(s.charAt(i));
        }
        return sb.toString();
    }

    /**
     * Write a method accepting a string and returning the same string without the first two
     * characters
     */
    public static String removeFirstTwoChars(String s) {
        return new StringBuilder(s).delete(0,2).toString();
    }

    /**
     * Write a function accepting a string
     * returning the string without the first two characters.
     * Keep the first character if it is 'H' and
     * keep the second character if it is 'e'.
     */
    public static String removeFirstTwoCharsIf(String s) {
        StringBuilder sb = new StringBuilder(s);
        int start = 0;
        int end = 2;

        if(sb.charAt(0) == 'H'){
            start = 1;
        }
        if(sb.charAt(1) == 'e'){
            end = 1;
        }

        return sb.delete(start,end).toString();
    }

    /**
     * Write a function accepting a string
     * returning true if "good" appears at the beginning of the string
     */
    public static boolean goodAtTheBeginning(String s) {
        // return s.charAt(0) == 'g' && s.charAt(1) == 'o' && s.charAt(2) == 'o' && s.charAt(3) == 'd';

        return s.startsWith("good");
    }

    /**
     * Write a function accepting a string
     * returning true if "good" appears
     * starting at index 0 or 1 in the given string.
     * see substring() method
     */
    public static boolean goodAroundTheBeginning(String s) {
        return s.startsWith("good",0) || s.startsWith("good",1);
    }

    /**
     * Write a function accepting a string
     * returning the same string (trimmed of the first and last characters) if the first or last characters are equal
     * or returning the same string (without trimming anything) otherwise
     * see substring(), charAt() methods
     */
    public static String removeFirstLast(String s) {
       StringBuilder sb = new StringBuilder(s);
       if(sb.charAt(0) == sb.charAt(sb.length() - 1)) {
            sb.deleteCharAt(0);
            sb.deleteCharAt(sb.length() - 1);
       }
       return sb.toString();
    }

    /**
     * Write a function accepting a string
     * returning all recurring characters contained into the string as a char[]
     */
    public static char[] duplicateChars(String input) {
        StringBuilder reccuring = new StringBuilder();

        for (int i = 0; i < input.length(); i++) {
            for (int j = i + 1; j < input.length(); j++) {
                if(input.charAt(i) == input.charAt(j)){
                    reccuring.append(input.charAt(j));
                    break;
                }
            }
        }

        char[] ret = reccuring.toString().toCharArray();
        Arrays.sort(ret);
        return ret;

    }


    /**
     * Write a function accepting a string
     * returning true if the string is a palindrome.
     * see StringBuilder methods
     */
    public static boolean isPalindrome(String s) {
        if(s.length() <= 1){
            return false;
        } else {
            String sRev = new StringBuilder(s).reverse().toString();
            return sRev.equalsIgnoreCase(s);
        }
    }


    /*
    Write a method accepting a string, and counting the number of words ending in 'y' or 'z' so the 'y'
    in "heavy" and the 'z' in "fez" count, but not the 'y' in "yellow" (not case sensitive) (see Scanner class).
     */

    public static int countYZ(String string){
        int count = 0;
        String[] words = string.split(" ");
        for (String tmp : words) {
            if(tmp.toLowerCase().endsWith("y") || tmp.toLowerCase().endsWith("z")){
                count++;
            }
        }
        return count;
    }

    /*
    Write a method accepting a string, and returning true if the number of appearances of "is"
     anywhere in the string is equal to the number of appearances of "not" anywhere in the string (case sensitive) (See
    String.indexOf()).
     */

    public static boolean  equalIsNot(String string){
        int countIs = 0;
        for (int i = 0; i < string.length() - 1; i++) {
            if(string.charAt(i) == 'i' && string.charAt(i + 1) == 's'){
                countIs++;
            }
        }
        int countNot = 0;
        for (int i = 0; i < string.length() - 2; i++) {
            if(string.charAt(i) == 'n' && string.charAt(i + 1) == 'o' && string.charAt(i + 2) == 't'){
                countNot++;
            }
        }

        if (countNot == countIs){
            return true;
        }

        return false;

    }

    /*
    Given a string, return the sum of the digits 0-9 that appear in the string, ignoring all other
    characters. Return 0 if there are no digits in the string. (see Character class)
     */

    public static int sumDigits(String string){
        int sum = 0;

        for (int i = 0; i < string.length(); i++) {
            if(Character.isDigit(string.charAt(i))){
                sum += Character.getNumericValue(string.charAt(i));
            }
        }
        return sum;

    }
}
