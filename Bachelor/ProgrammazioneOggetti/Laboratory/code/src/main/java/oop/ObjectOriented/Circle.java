package oop.ObjectOriented;

import java.awt.*;
import java.security.cert.PolicyNode;

/**
 Write a class named Circle representing a Circle on a 2D plane.
 Internally, the class uses a Point object and a double value for representing the center and the radius of the Circle, respectively.
 The class provides the following methods:
 * public Circle(Point center, int radius) creating the circle.
 * getters and setters.
 * public double getPerimeter() returning the perimeter of the circle.
 * public double getArea() returning the area of the circle.
 * public boolean contains(Point point) returning true if point is contained within the circle.
 * public void translate(int dx, int dy) moving the circle on the 2D plane. dx and dy are the x and y components of the translation vector.
 * public String toString().
 */

public class Circle {

    private Point center;
    private double radius;

    public Circle(Point center, double radius) {
        this.center = center;
        this.radius = radius;
    }

    public Point getCenter() {
        return center;
    }

    public void setCenter(Point center) {
        this.center = center;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }


    public double getPerimeter(){
        return 2 * Math.PI * getRadius();
    }

    public double getArea(){
        return Math.PI * getRadius() * getRadius();
    }

    public boolean contains(Point point){
        return getCenter().distance(point) < getRadius();
    }

    public void translate(int dx, int dy){
        getCenter().translate(dx,dy);
    }

    @Override
    public String toString() {
        return "Circle{" +
                "center=" + center +
                ", radius=" + radius +
                '}';
    }
}

