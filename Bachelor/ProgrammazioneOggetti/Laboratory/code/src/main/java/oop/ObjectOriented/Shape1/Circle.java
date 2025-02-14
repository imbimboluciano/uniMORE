package oop.ObjectOriented.Shape1;

import java.awt.*;

public class Circle extends Shape {

    Point center;
    double radius;

    public Circle(Color color, boolean filled, Point center, double radius) {
        super(color, filled);
        this.center = center;
        this.radius = radius;
    }

    @Override
    public void move(Point p) {
        this.center = p;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public void resize(double d) {
        radius = radius * d;
    }

    @Override
    public String toString() {
        return "Circle{" +
                "center=" + center +
                ", radius=" + radius +
                ", color=" + color +
                ", filled=" + filled +
                '}';
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
}
