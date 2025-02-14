package oop.Generics.MyCollection;

import oop.Collections.MyCollection.MyLinkedList;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.assertEquals;

class MyLinkedListTest extends MyListTestBase {
    @BeforeEach
    void setUp() {
        l = new oop.Collections.MyCollection.MyLinkedList();
    }

    @Test
    void peek() {
        oop.Collections.MyCollection.MyLinkedList ll = new oop.Collections.MyCollection.MyLinkedList();
        ll.add("nicola");
        ll.add("marzia");
        assertEquals("nicola", ll.peek());
        assertEquals("nicola", ll.peek());
        assertEquals(2, ll.size());
    }

    @Test
    void poll() {
        oop.Collections.MyCollection.MyLinkedList ll = new MyLinkedList();
        ll.add("nicola");
        ll.add("marzia");
        assertEquals("nicola", ll.poll());
        assertEquals("marzia", ll.poll());
        assertEquals(0, ll.size());
    }
}