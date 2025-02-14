package oop.ObjectOriented.Reverser;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class EngineSlowTest {
    @Test
    void reverse() {
        Reverser r = new EngineSlow();
        assertEquals("!dlroW olleH", r.reverse("Hello World!"));
    }
}