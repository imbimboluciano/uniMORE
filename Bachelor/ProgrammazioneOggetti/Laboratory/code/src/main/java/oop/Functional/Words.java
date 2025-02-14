package oop.Functional;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Words {

    /*
    Download the [Ulysses, by James Joyce](https://github.com/laumann/ds/blob/master/hashing/books/) book.
Write two methods, reading all the lines of the file and returning respectively:
(a) how many lines contain a specific substring, (b) how many times a specific word appears in an isolated form (not as
a substring).
     */

    public static long howManyLines(String filename, String subString){
        try {
            return getLines(filename).stream().filter(s -> s.contains(subString)).count();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public static long howManyTimes(String filename, String word){
        List<String> words = new ArrayList<>();
        try {
            for (String tmp: getLines(filename)) {
                words.addAll(lineToWords(tmp));
            }

            return words.stream().filter(s -> s.equals(word)).count();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }

    }




    public static List<String> getLines(String filename) throws IOException {
        return Files.readAllLines(Path.of(filename));
    }

    public static List<String> lineToWords(String line) {
        return Arrays.asList(line.replaceAll("[^a-zA-Z ]", "").toLowerCase().split("\\s+"));
    }
}
