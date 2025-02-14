package oop.ObjectOriented.Shape2;

import java.awt.*;

public class Circle implements Shape {

    Color color;
    boolean filled;
    Point center;
    double radius;

    public Circle(Color color, boolean filled, Point center, double radius) {
        this.color = color;
        this.filled = filled;
        this.center = center;
        this.radius = radius;
    }

    public Point getCenter() {
        return center;
    }

    public void setCenter(Point center) {
        this.center = center;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public double getRadius() {
        return radius;
    }

    public void setRadius(double radius) {
        this.radius = radius;
    }



    @Override
    public void resize(double d) {
        radius *= d;
    }

    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }

    @Override
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }

    @Override
    public void move(Point p) {
        this.center = p;
    }

    @Override
    public String toString() {
        return "Circle{" +
                "center=" + center +
                ", filled=" + filled +
                ", color=" + color +
                ", radius=" + radius +
                '}';
    }
}
