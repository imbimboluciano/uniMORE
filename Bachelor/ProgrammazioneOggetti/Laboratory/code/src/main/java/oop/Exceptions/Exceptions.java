package oop.Exceptions;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeParseException;
import java.util.*;

/**
 * You can find many more here:
 *
 *
 * Preferences -> Editor -> General -> Code folding -> One-line methods (uncheck)
 * Code -> Folding -> Collapse All
 * Code -> Folding -> Expand Doc Comments
 */
public class Exceptions {
    /**
     * Write a function to check if a String is an alternating sequence of letters and numbers (for example,
     * a0b3h4z1r4). The function delegates ParseException for notifying the caller about eventual malformations.
     * Note: Use can use Character.isDigit() and Character.isLetter() methods
     */
    public static void checkString(String s) throws ParseException{
        for (int i = 0; i < s.length() - 1; i++) {
            if(Character.isDigit(s.charAt(i))){
                if(!Character.isLetter(s.charAt(i + 1))){
                    throw new ParseException(s,i);
                }
            } else if (Character.isLetter(s.charAt(i))) {
                if(!Character.isDigit(s.charAt(i + 1))){
                    throw new ParseException(s,i);
                }
            }
        }
    }

    /**
     * Write a function to remove from a List<String> all the strings which are not an alternating sequence of letters
     * and numbers (for example, a0b3h4z1r4).
     */
    public static void removeItems(List<String> strings) {
        for (ListIterator<String> l = strings.listIterator();l.hasNext();){
            try {
                checkString(l.next());
            } catch (ParseException e) {
                l.remove();
            }
        }
    }

    /**
     * Write a function receiving two strings as parameters and returning true if the first date is before the second
     * date. The function uses the SimpleDateFormat and java.util.Date classes. Eventual exceptions are delegated to
     * the caller.
     */
    public static boolean checkInterval(String begin, String end) throws ParseException {
        SimpleDateFormat reader = new SimpleDateFormat("dd/MM/yyyy",Locale.ENGLISH);
        Date b = reader.parse(begin);
        Date e = reader.parse(end);
        return b.before(e);
    }

    /**
     * Write a function receiving two strings as parameters and returning true if the first date is before the second
     * date. The function uses the SimpleDateFormat and java.util.Date class. Eventual exceptions are managed locally
     * and false is returned.
     */
    public static boolean checkInterval_alternative(String begin, String end) {
        SimpleDateFormat reader = new SimpleDateFormat("dd/MM/yyyy",Locale.ENGLISH);
        try {
            Date b = reader.parse(begin);
            Date e = reader.parse(end);
            return b.before(e);
        }catch (ParseException e){
            return false;
        }
    }

    /**
     * Write a function receiving two double numbers (a, b) and returning their division. If b == 0, the function throws
     * IllegalArgumentException
     */
    public static double divide(double a, double b) {
        if(b == 0){
            throw new IllegalArgumentException("b deve essere diverso da 0");
        }else{
            return a / b;
        }
    }

    /**
     * Write a function receiving two double numbers (a, b) and returning their division squared (i.e., (a/b)^2). If
     * b == 0, the function returns 0.0
     */
    public static double divideSquared(double a, double b) {
        try {
            return Math.pow(divide(a,b),2);
        }catch (IllegalArgumentException e){
            return 0.0;
        }
    }

    /**
     * Write a function reading the first line of a given file. In case of errors (IOException), the function applies
     * a complete delegation model.
     * Note: for reading a line from a text file, use readline() from the BufferedReader class
     */
    public static String completeDelegation(String filename) throws IOException {
        BufferedReader r = new BufferedReader(new FileReader(filename));
        String line = r.readLine();
        r.close();
        return line;
    }

    /**
     * Write a function reading the first line of a given file. In case of errors (IOException), the function applies
     * a no-delegation model returning null.
     * Note: for reading a line from a text file, use readline() from the BufferedReader class
     */
    public static String noDelegation(String filename)  {
        try(BufferedReader r = new BufferedReader(new FileReader(filename))){
            return r.readLine();
        }catch (IOException e){
            return null;
        }
    }

    /**
     * Write a function reading the first line of a given file. In case of errors (IOException), the function applies
     * a partial delegation model throwing RunTimeException
     * Note: for reading a line from a text file, use readline() from the BufferedReader class
     */
    public static String partialDelegation(String filename) {
        try(BufferedReader r = new BufferedReader(new FileReader(filename))){
            return r.readLine();
        }catch (IOException e){
            throw new RuntimeException();
        }
    }

    /**
     * Write a function for filtering a List<String>. The function returns a List<String> comprising only those strings
     * which are an alternating sequence of letters and numbers (for example a0b3h4z1r4). The original List should
     * not be modified.
     * Note: Use the check() method above
     */
    public static List<String> checkItems(List<String> src) {
        List<String> tmp = new ArrayList<>();
        for(ListIterator<String> l = src.listIterator();l.hasNext();){
            String s = l.next();
            try {
                checkString(s);
                tmp.add(s);
            }catch (ParseException e){

            }
        }
        return tmp;

    }

    /**
     * Write a function for filtering a List<List<String>> (a list of lists of strings). The function returns a List<List<String>>
     * comprising only those List<String> containing ONLY alternating sequences of letters and numbers (for example
     * a0b3h4z1r4). The original List should not be modified.
     * Note: Use the check() method above
     */
    public static List<List<String>> checkLists(List<List<String>> src) {
        boolean ok = false;
        List<List<String>> tmp = new ArrayList<>();
        for(List<String> list : src){
            for(String s : list){
                try{
                    checkString(s);
                    ok = true;
                }catch (ParseException e){
                    ok = false;
                    break;
                }
            }
            if(ok){
                tmp.add(list);
                ok = false;
            }
        }
        return tmp;

    }

    public static double division(double a, double b){
        if(b == 0){
            throw new IllegalArgumentException();
        }else{
            return a / b;
        }
    }


    /*
    Write a method receiving two integers (a, b) and returning their integer division squared (
    i.e., (a / b) ^ 2). If b == 0, the method returns 0, instead of an exception. The implementation of this method must avoid the
    use of the *if* statement. The method has the following prototype:
     */

    public static int divisionSquared(int a, int b){

        try{
            return (int) Math.pow(division(a,b),2);
        }catch (IllegalArgumentException e){
            return 0;
        }
    }


    public static boolean checkIntervalBetweenDates(String begin, String end) throws ParseException{
        return LocalDate.parse(begin).isBefore(LocalDate.parse(end));
    }


    /*
    Write a method receiving two strings representing dates (i.e., yyyy-mm-dd) and
    returning true if the first date is before the second date (see java.time.LocalDate).
    Eventual exceptions must be locally intercepted and false is returned in case of errors. The method has the following
    prototype:
     */

    public static boolean checkIntervalBetweenDatesAlt(String begin, String end){

        try {
            return LocalDate.parse(begin).isBefore(LocalDate.parse(end));
        }catch (DateTimeParseException e){
            return false;
        }

    }

    /*
    Write a method to check if a string representing a car licence plate respects
    the italian format (i.e., LLDDDLL where L represents a letter while D a digit). If the string does not respect the
    format, the method throws IllegalArgumentException (see Character.isDigit() and Character.isLetter() methods).
     */
    public static void checkLicencePlate(String licence){
        if(licence.length() != 7){
            throw new IllegalArgumentException();
        }

        String first = licence.substring(0,2);
        String middle = licence.substring(2,5);
        String end = licence.substring(5,7);

        for (Character c: first.toCharArray()) {
            if(!Character.isLetter(c)){
                throw new IllegalArgumentException();
            }
        }

        for (Character c: middle.toCharArray()) {
            if(!Character.isDigit(c)){
                throw new IllegalArgumentException();
            }
        }

        for (Character c: end.toCharArray()) {
            if(!Character.isLetter(c)){
                throw new IllegalArgumentException();
            }
        }


    }

    /*
    Using the checkString() method, write another method for filtering a List<String>. The method returns
    a different List<String> comprising only those strings which are an alternating sequence of letters and numbers (for
    example a0b3h4z1r4). The original list is not modified.
     */

    public static List<String> filterItems(List<String> strings){
        List<String> ret = new ArrayList<>();

        for (String tmp: strings) {
            try {
                checkString(tmp);
                ret.add(tmp);
            } catch (ParseException e) {

            }
        }
        return ret;
    }



    /*
     Using the checkString() method, write another method for filtering a List<List> (a list of lists of strings).
     The method returns a List<List> comprising only those List containing ONLY alternating sequences of letters and numbers (for example a0b3h4z1r4).
      The original List should not be modified.
     */

    public static List<List<String>> filterLists(List<List<String>> lists){
        List<List<String>> ret = new ArrayList<>();

        for (List<String> tmp: lists) {
            try {
                for (String s: tmp) {
                    checkString(s);
                }
                ret.add(tmp);
            } catch (ParseException e) {

            }

        }
        return ret;
    }



    /*
    Write a method for reading the first line of a given file (see java.io.BufferedReader class). In case of errors (IOException),
    the method applies a complete delegation model. Use the syntax try-with-resources for guaranteeing the
    proper closing of the file under any circumstance.
     */

    public static String readLineCompleteDelegation(String filename) throws IOException{
        BufferedReader bufferedReader = new BufferedReader(new FileReader(filename));
        return  bufferedReader.readLine();
    }

    /*
    Write a method for reading the first line of a given file (see java.io.BufferedReader class). In case of errors (IOException),
    the method applies a partial delegation model throwing an unchecked exception (RunTimeException) instead
of IOException
     */

    public static String readLinePartialDelegation(String filename){
        BufferedReader bufferedReader;
        try {
            bufferedReader = new BufferedReader(new FileReader(filename));
            return bufferedReader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }

    /*
    Write a method reading the first line of a given file (see java.io.BufferedReader class). In case of errors (IOException),
    the method applies a no-delegation model and returns null
     */

    public static String readLineNoDelegation(String filename){
        BufferedReader bufferedReader;
        String s;

        try {
            bufferedReader = new BufferedReader(new FileReader(filename));
            s = bufferedReader.readLine();
        } catch (IOException e) {
            return null;
        }

        return s;
    }



}
