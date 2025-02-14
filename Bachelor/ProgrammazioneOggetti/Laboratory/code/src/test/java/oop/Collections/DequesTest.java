package oop.Collections;

import org.junit.jupiter.api.Test;

import java.util.List;

import static org.junit.jupiter.api.Assertions.assertEquals;

public class DequesTest {


    @Test
    void reverse() {
        assertEquals(List.of("am", "I"), Deques.reverse(List.of("I", "am")));
        assertEquals(List.of("1", "2", "3"), Deques.reverse(List.of("3", "2", "1")));
    }
}
