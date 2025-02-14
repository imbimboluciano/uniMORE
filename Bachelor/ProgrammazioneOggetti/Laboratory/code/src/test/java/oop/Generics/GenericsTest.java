package oop.Generics;

import oop.Generics.Measurer;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import static org.junit.jupiter.api.Assertions.assertEquals;

class GenericsTest {
    @Test
    void fill() {
        List<Integer> src = new ArrayList<>(List.of(1, 2, 3, 4));
        Generics.fill(src, 7);
        assertEquals(List.of(7, 7, 7, 7), src);
    }

    @Test
    void copy() {
        List<Integer> src = new ArrayList<>(List.of(1, 2, 3, 4));
        List<Number> dst = new ArrayList<>(List.of(2.0, 1, 4.4, 11.54));
        Generics.copy(dst, src);
        assertEquals(List.of(1, 2, 3, 4), dst);
    }

    @Test
    void swap() {
        List<Integer> src = new ArrayList<>(List.of(1, 2, 3, 4));
        Generics.swap(src, 0, 1);
        assertEquals(List.of(2, 1, 3, 4), src);
        Generics.swap(src, 0, 3);
        assertEquals(List.of(4, 1, 3, 2), src);
    }

    @Test
    void reverse() {
        List<Integer> src = new ArrayList<>(List.of(1, 2, 3, 4));
        Generics.reverse(src);
        assertEquals(List.of(4, 3, 2, 1), src);
    }

    @Test
    void min() {
        List<Integer> src = new ArrayList<>(List.of(100, 20, 30, 40));
        assertEquals(20, Generics.min(src));
    }

    @Test
    void max() {
        List<Integer> src = new ArrayList<>(List.of(100, 20, 30, 40));
        assertEquals(100, Generics.max(src));
    }

    @Test
    void sort() {
        List<Integer> src = new ArrayList<>(List.of(100, 20, 30, 40));
        Generics.sort(src);
        assertEquals(List.of(20, 30, 40, 100), src);
    }

    @Test
    void divide() {
        assertEquals(0.5, Generics.divide((Integer) 1, 2.0), 0.0001);
        assertEquals(0.5, Generics.divide((Integer)1, (Integer)2), 0.0001);
        assertEquals(0.5, Generics.divide(1.0, 2.0), 0.0001);
    }

    @Test
    void countOccurrences() {
        Integer[] src;
        src = new Integer[]{1,1,2,3,45,1,1};
        assertEquals(4, Generics.countOccurrences(src, 1));
        src = new Integer[]{1,1,2,3,null,1,1};
        assertEquals(1, Generics.countOccurrences(src, null));

        assertEquals(1, Generics.countOccurrences(new Integer[]{1, 2, 3}, 3));
        assertEquals(3, Generics.countOccurrences(new Integer[]{1, 2, 3, 3, 3}, 3));
        assertEquals(2, Generics.countOccurrences(new Integer[]{null, 2, null}, null));
    }

    @Test
    void shuffle(){
        List<Integer> src = new ArrayList<>(List.of(1, 2, 3, 4,5,6,7,9));
        Generics.shuffle(src);
        System.out.println(src);
    }

    @Test
    void printIterable() {
        assertEquals("5, 4, 3, ", Generics.printIterable(List.of(5, 4, 3)));
        assertEquals("1, 2, 3, ", Generics.printIterable(new LinkedList<>(List.of(1, 2, 3))));
    }

    @Test
    void append() {
        List<Integer> a = new ArrayList<>(List.of(1, 2, 3));
        List<Integer> b = new ArrayList<>(List.of(4, 5));
        Generics.append(a, b);
        assertEquals(List.of(1, 2, 3, 4, 5), a);
    }

    @Test
    void appendBounded() {
        List<Number> a = new ArrayList<>(List.of(1, 2, 3));
        List<Integer> b = new ArrayList<>(List.of(4, 5));
        Generics.appendBounded(a, b);
        assertEquals(List.of(1, 2, 3, 4, 5), a);

        // Integer is a subclass of Number, so the following line does not compile
        // AppendBounded.append(b, a);
    }

    @Test
    void mapToPairs() {
        Map<Integer, String> map = Map.of(0, "nicola", 1, "darma", 2, "agata");
        List<Pair<Integer, String>> list = Generics.mapToPairs(map);
        for (Pair<Integer, String> pair : list) {
            switch (pair.getFirst()) {
                case 0 -> assertEquals("nicola", pair.getSecond());
                case 1 -> assertEquals("darma", pair.getSecond());
                case 2 -> assertEquals("agata", pair.getSecond());
            }
        }
    }

    @Test
    void max2() {
        Measurer<String> measurer = new Measurer<>() {
            @Override
            public double measure(String item) {
                return item.length();
            }
        };
        assertEquals("hard disk", Generics.max(new String[]{"cpu", "memory", "hard disk", "case"}, measurer));
        assertEquals("cpu", Generics.min(new String[]{"cpu", "memory", "hard disk", "case"}, measurer));
    }




}