package oop.Basics;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

public class StringsTest {
    @Test
    public void concatenate() {
        assertEquals("Hello World!", Strings.concatenate(new String[]{"Hello", " ", "World", "!"}));
    }

    @Test
    public void duplicateChars() {
        assertArrayEquals(new char[]{'e', 'l', 'w'}, Strings.duplicateChars("whistleblower"));
        assertArrayEquals(new char[]{'s'}, Strings.duplicateChars("ss"));
        assertArrayEquals(new char[]{}, Strings.duplicateChars("s"));
        assertArrayEquals(new char[]{}, Strings.duplicateChars(""));
    }

    @Test
    public void reverse() {
        assertEquals("tset gnirtS", Strings.reverse("String test"));
        assertEquals("eoD nhoJ", Strings.reverse("John Doe"));
        assertEquals("!dlroW olleH", Strings.reverse("Hello World!"));
    }

    @Test
    public void removeFirstTwoChars() {
        assertEquals("llo World!", Strings.removeFirstTwoChars("Hello World!"));
        assertEquals("me Sweet Home", Strings.removeFirstTwoChars("Home Sweet Home"));
    }

    @Test
    public void removeFirstTwoCharsIf() {
        assertEquals("Hello World!", Strings.removeFirstTwoCharsIf("Hello World!"));
        assertEquals("Hme Sweet Home", Strings.removeFirstTwoCharsIf("Home Sweet Home"));
        assertEquals("ex", Strings.removeFirstTwoCharsIf("Sex"));
    }

    @Test
    public void goodAtTheBeginning() {
        assertTrue(Strings.goodAtTheBeginning("good Sweet Home"));
        assertFalse(Strings.goodAtTheBeginning(" good Sweet Home"));
        assertFalse(Strings.goodAtTheBeginning("No good Sweet Home"));
    }

    @Test
    public void goodAroundTheBeginning() {
        assertTrue(Strings.goodAroundTheBeginning("good Sweet Home"));
        assertTrue(Strings.goodAroundTheBeginning(" good Sweet Home"));
        assertFalse(Strings.goodAroundTheBeginning("No good Sweet Home"));
    }

    @Test
    public void removeFirstLast() {
        assertEquals("Google", Strings.removeFirstLast("Google"));
        assertEquals("oogle", Strings.removeFirstLast("GoogleG"));
    }

    @Test
    public void isPalindrome() {
        assertFalse(Strings.isPalindrome("Google"));
        assertTrue(Strings.isPalindrome("radar"));
    }

    @Test
    void sumDigits() {
        assertEquals(6, Strings.sumDigits("aa1bc2d3"));
        assertEquals(8, Strings.sumDigits("aa11b33"));
        assertEquals(0, Strings.sumDigits("Chocolate"));
    }

    @Test
    void equalIsNot() {
        assertFalse(Strings.equalIsNot("This is not"));
        assertTrue(Strings.equalIsNot("This is notnot"));
        assertTrue(Strings.equalIsNot("noisxxnotyynotxisi"));
    }

    @Test
    void countYZ() {
        assertEquals(2, Strings.countYZ("fez day"));
        assertEquals(2, Strings.countYZ("day fez"));
        assertEquals(2, Strings.countYZ("day fyyyz"));
        assertEquals(2, Strings.countYZ("daY fyyYZ"));
    }
}
