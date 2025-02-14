package oop.ObjectOriented.Polynomials;

import org.junit.jupiter.api.BeforeEach;

class ListPolyTest extends PolyTestBase {
    @BeforeEach
    void setUp() {
        p = new ListPoly(new double[]{1, 2, 3, 4});
    }
}