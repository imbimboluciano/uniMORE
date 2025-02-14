package oop.ObjectOriented;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.awt.Polygon;
import java.awt.*;

import static org.junit.jupiter.api.Assertions.assertEquals;

class PolygonTest {
    public static final double DELTA = 1e-06;
    oop.ObjectOriented.Polygon square;
    oop.ObjectOriented.Polygon triangle;
    @BeforeEach
    void setUp() {
        square = new oop.ObjectOriented.Polygon(new Point[]{new Point(0,0), new Point(0, 10), new Point(10,10), new Point(10, 0)});
        triangle = new oop.ObjectOriented.Polygon(new Point[]{new Point(0,0), new Point(10, 0), new Point(5,10)});
    }

    @Test
    void getVerticesCount() {
        assertEquals(4, square.getVerticesCount());
        assertEquals(3, triangle.getVerticesCount());
    }

    @Test
    void getPerimeter() {
        assertEquals(40, square.getPerimeter(), DELTA);
        assertEquals(32.3606797749979, triangle.getPerimeter(), DELTA);
    }

    @Test
    void getArea() {
        assertEquals(100, square.getArea(), DELTA);
        assertEquals(50, triangle.getArea(), DELTA);
    }
}