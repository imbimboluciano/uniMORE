package oop.Generics.MyCollection;

import oop.Collections.MyCollection.MyHashSet;
import org.junit.jupiter.api.BeforeEach;

class MyHashSetTest extends MySetTestBase {
    @BeforeEach
    void setUp() {
        s = new MyHashSet();
    }
}