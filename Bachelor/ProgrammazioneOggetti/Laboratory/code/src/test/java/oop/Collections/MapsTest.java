package oop.Collections;

import org.junit.jupiter.api.Test;

import java.io.IOException;
import java.util.*;

import static org.junit.jupiter.api.Assertions.*;

public class MapsTest {
    @Test
    public void count() {
        Map<Integer, Integer> map = new HashMap<>(Map.of(1,1,2,2,3,3));
        assertEquals(3, Maps.count(map));
    }

    @Test
    public void empty() {
        Map<Integer, Integer> map = new HashMap<>(Map.of(1,1,2,2,3,3));
        Maps.empty(map);
        assertEquals(0, map.size());
    }

    @Test
    public void contains() {
        Map<Integer, Integer> map = new HashMap<>(Map.of(1,1,2,2,3,3));
        assertTrue(Maps.contains(map, 1));
        assertFalse(Maps.contains(map, 5));
    }

    @Test
    void containsKeyValue() {
        Map<Integer, Integer> map = new HashMap<>(Map.of(1,1,2,2,3,3));
        assertTrue(Maps.containsKeyValue(map, 1,1));
        assertFalse(Maps.containsKeyValue(map, 1,2));
        assertFalse(Maps.containsKeyValue(map, 7,2));
    }

    @Test
    public void keySet() {
        Map<Integer, Integer> map = new HashMap<>(Map.of(1,1,2,2,3,3));
        assertEquals(Set.of(1,2,3), Maps.keySet(map));
    }

    @Test
    public void values() {
        Map<Integer, Integer> map = new HashMap<>(Map.of(1,1,2,2,3,3));
        assertEquals(new ArrayList<>(List.of(1, 2, 3)), new ArrayList<>(Maps.values(map)));
    }

    @Test
    public void getColor() {
        assertEquals("black", Maps.getColor(0));
        assertEquals("white", Maps.getColor(1));
        assertEquals("red", Maps.getColor(2));
    }

    @Test
    void morseCode() {
        assertEquals(".... . ._.. ._.. ___", Maps.morseCode("hello"));
        assertEquals(".__ ___ ._. ._.. _..", Maps.morseCode("world"));
    }

    @Test
    void valuesKeys() {
        assertFalse(Maps.valuesKeys(Map.of("a", "1", "b", "2", "c", "3")));
        assertTrue(Maps.valuesKeys(Map.of("a", "1", "b", "2", "c", "a")));
    }

    @Test
    void invertMap() {
        assertEquals(Map.of("Hello", 1, "World", 3), Maps.invertMap(Map.of(1, "Hello", 3, "World")));
        assertEquals(Set.of("Hello"), Maps.invertMap(Map.of(1, "Hello", 3, "Hello")).keySet());
    }

    final String filename = "src/main/resources/james-joyce-ulysses.txt";

    @Test
    void wordFrequency() throws IOException {
        assertEquals(1, Maps.wordFrequency(filename).get("zulu"));
        assertEquals(2, Maps.wordFrequency(filename).get("velocipedes"));
        assertEquals(3, Maps.wordFrequency(filename).get("bachelor"));
    }

    @Test
    void mostFrequent() throws IOException {
        Map<String, Integer> wordFrequency = Maps.wordFrequency(filename);
        Map<String, Integer> topFifty = Maps.mostFrequent(wordFrequency, 50);
        assertEquals(704, topFifty.get("one"));
        assertEquals(701, topFifty.get("but"));
        assertEquals(698, topFifty.get("have"));
        Map<String, Integer> lessFifty = Maps.lessFrequent(wordFrequency, 50);
        assertEquals(1, lessFifty.get("zulus"));
        assertEquals(1, lessFifty.get("blasts"));
        assertEquals(1, lessFifty.get("guards"));
    }
}