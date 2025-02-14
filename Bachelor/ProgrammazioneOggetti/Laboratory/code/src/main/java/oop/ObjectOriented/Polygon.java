package oop.ObjectOriented;

import java.awt.*;
import java.util.Arrays;

/**
 * Write a class named Polygon representing an irregular polygon.
 * Internally, the class uses a Point[] for representing the vertices of the polygon.
 * The class provides the following methods:
 * * public Polygon(Point[] vertices) creating the polygon.
 * * public int getVerticesCount() returning the number of vertices.
 * * public double getPerimeter() returning the perimeter of the polygon.
 * * public double getArea() returning the area of the polygon.
 * * public String toString().
 */

public class Polygon {

    Point[] vertices;

    public Polygon(Point[] vertices) {
        this.vertices = vertices;
    }

    public int getVerticesCount(){
        return vertices.length;
    }

    // https://arachnoid.com/area_irregular_polygon/index.html
    public double getPerimeter(){
        double p = 0.0;
        int next;

        for (int i = 0; i < vertices.length; i++) {
            if(i == vertices.length - 1){
                next = 0;
            }else{
                next = i + 1;
            }
            p += Math.sqrt(Math.pow(vertices[i].x - vertices[next].x,2)+Math.pow(vertices[i].y - vertices[next].y,2));
        }
        return p;
    }

    // https://arachnoid.com/area_irregular_polygon/index.html
    public double getArea(){
        double area = 0.0;
        int next;

        for (int i = 0; i < vertices.length; i++) {
            if(i == vertices.length - 1){
                next = 0;
            }else{
                next = i + 1;
            }
            area += vertices[next].x * vertices[i].y - vertices[i].x * vertices[next].y;
        }

        return Math.abs(area / 2.0);

    }

    @Override
    public String toString() {
        return "Polygon{" +
                "vertices=" + Arrays.toString(vertices) +
                '}';
    }
}
