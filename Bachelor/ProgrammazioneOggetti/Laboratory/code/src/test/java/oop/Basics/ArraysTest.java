package oop.Basics;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static org.junit.jupiter.api.Assertions.assertFalse;

public class ArraysTest {
    private static final double DELTA = 1e-09;
    final String[] words = {"car", "boat", "bike", "plane"};
    @Test
    public void divideArray() {
        assertArrayEquals(new double[]{0.5, 0.5, 0.5}, Arrays.divideArray(new double[]{1, 1, 1}, 2.0), DELTA);
        assertArrayEquals(new double[]{2.0, 1.0, 1.0}, Arrays.divideArray(new double[]{2, 1, 1}, 1.0), DELTA);
        assertArrayEquals(new double[]{1.0, 1.0}, Arrays.divideArray(new double[]{10, 10}, 10.0), DELTA);
    }

    @Test
    public void divideArrays() {
        double[] v1 = {5.0, 4.0, 6.0, 2.0};
        double[] v2 = {10.0, 2.0, 3.0, 8.0};
        assertArrayEquals(new double[]{0.5, 2.0, 2.0, 0.25}, Arrays.divideArrays(v1, v2), 0.01);
    }

    @Test
    public void bubbleSort() {
        int[] input = {5, 4, 6, 2, 3, 4};
        assertArrayEquals(new int[]{2, 3, 4, 4, 5, 6}, Arrays.bubbleSort(input));
    }

    @Test
    public void fibonacci() {
        assertArrayEquals(new long[]{0}, Arrays.fibonacci(1));
        assertArrayEquals(new long[]{0, 1}, Arrays.fibonacci(2));
        assertArrayEquals(new long[]{0, 1, 1, 2, 3}, Arrays.fibonacci(5));
        assertArrayEquals(new long[]{0, 1, 1, 2, 3, 5, 8}, Arrays.fibonacci(7));
    }

    @Test
    public void moveZerosEnd() {
        assertArrayEquals(new int[]{1, 2, 3, 0, 0}, Arrays.moveZerosEnd(new int[]{1, 2, 0, 0, 3}));
        assertArrayEquals(new int[]{1, 2, 3}, Arrays.moveZerosEnd(new int[]{1, 2, 3}));
        assertArrayEquals(new int[]{1, 2, 3, 0}, Arrays.moveZerosEnd(new int[]{0, 1, 2, 3}));
        assertArrayEquals(new int[]{4, 2, 0, 0}, Arrays.moveZerosEnd(new int[]{0, 0, 4, 2}));
        assertArrayEquals(new int[]{9, 4, 0, 0}, Arrays.moveZerosEnd(new int[]{9, 0, 0, 4}));
        assertArrayEquals(new int[]{1, 0, 0, 0}, Arrays.moveZerosEnd(new int[]{1, 0, 0, 0}));
    }

    @Test
    public void splitter() {
        assertArrayEquals(new int[]{2, 3, 4, 4, 5, 6}, Arrays.splitter(234456));
    }


    @Test
    void copyArray() {
        assertArrayEquals(new double[]{1, 1, 1}, Arrays.copyArray(new double[]{1, 1, 1}));
        assertArrayEquals(new double[]{5, 4, 3, 1}, Arrays.copyArray(new double[]{5, 4, 3, 1}));
    }

    @Test
    void fillArray() {
        assertArrayEquals(new double[]{1, 1, 1}, Arrays.fillArray(3, 1, false));
        assertArrayEquals(new double[]{5, 5, 5, 5}, Arrays.fillArray(4, 5, false));
        Arrays.fillArray(4,5,true);
    }

    @Test
    void isEveryWhere() {
        assertTrue(Arrays.isEveryWhere(new int[]{1, 2, 1, 3}, 1));
        assertFalse(Arrays.isEveryWhere(new int[]{1, 2, 1, 3}, 2));
        assertFalse(Arrays.isEveryWhere(new int[]{1, 2, 1, 3, 4}, 1));
    }

    @Test
    void tenRun() {
        assertArrayEquals(new int[]{2, 10, 10, 10, 20, 20}, Arrays.tenRun(new int[]{2, 10, 3, 4, 20, 5}));
        assertArrayEquals(new int[]{10, 10, 20, 20}, Arrays.tenRun(new int[]{10, 1, 20, 2}));
        assertArrayEquals(new int[]{10, 10, 10, 20}, Arrays.tenRun(new int[]{10, 1, 9, 20}));
    }

    @Test
    void fizzBuzz() {
        assertArrayEquals(new String[]{"1", "2", "Fizz", "4", "Buzz"}, Arrays.fizzBuzz(1, 6));
        assertArrayEquals(new String[]{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7"}, Arrays.fizzBuzz(1, 8));
        assertArrayEquals(new String[]{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz"}, Arrays.fizzBuzz(1, 11));
        assertArrayEquals(new String[]{"1", "2", "Fizz", "4", "Buzz", "Fizz", "7", "8", "Fizz", "Buzz","11","Fizz","13","14","FizzBuzz"}, Arrays.fizzBuzz(1, 16));
    }

    @Test
    void matchUp() {
        assertEquals(2, Arrays.matchUp(new int[]{1, 2, 3}, new int[]{2, 3, 10}));
        assertEquals(3, Arrays.matchUp(new int[]{1, 2, 3}, new int[]{2, 3, 5}));
        assertEquals(2, Arrays.matchUp(new int[]{1, 2, 3}, new int[]{2, 3, 3}));
    }



    @Test
    void deepCopy() {
        int[][] matrix = {{1, 2, 3}, {4, 5, 6}};
        int[][] deepCopy = Arrays.deepCopy(matrix);
        assertTrue(deepCopy[0] != matrix[0]);
        assertTrue(deepCopy[1] != matrix[1]);
    }

    @Test
    void searchBruteForce() {
        assertTrue(Arrays.containsBruteForce(words, "bike"));
        assertFalse(Arrays.containsBruteForce(words, "helicopter"));
    }

    @Test
    void searchBinary() {
        assertTrue(Arrays.containsBinary(words, "bike"));
        assertFalse(Arrays.containsBinary(words, "helicopter"));
    }

    @Test
    void canBalance() {
        assertTrue(Arrays.canBalance(new int[]{1, 1, 1, 2, 1}));
        assertFalse(Arrays.canBalance(new int[]{2, 1, 1, 2, 1}));
        assertTrue(Arrays.canBalance(new int[]{10, 10}));
    }

}