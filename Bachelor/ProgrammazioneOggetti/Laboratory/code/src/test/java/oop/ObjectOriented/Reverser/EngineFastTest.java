package oop.ObjectOriented.Reverser;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class EngineFastTest {
    @Test
    void reverse() {
        Reverser r = new EngineFast();
        assertEquals("!dlroW olleH", r.reverse("Hello World!"));
    }
}