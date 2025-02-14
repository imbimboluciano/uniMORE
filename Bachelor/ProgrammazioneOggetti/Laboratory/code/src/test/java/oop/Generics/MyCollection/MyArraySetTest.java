package oop.Generics.MyCollection;

import oop.Collections.MyCollection.MyArraySet;
import org.junit.jupiter.api.BeforeEach;

class MyArraySetTest extends MySetTestBase {
    @BeforeEach
    void setUp() {
        s = new MyArraySet();
    }
}