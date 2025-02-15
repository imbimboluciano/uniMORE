package oop.ObjectOriented.Shape2;

import java.awt.*;

public class Rectangle implements Shape {

    Color color;
    boolean filled;
    Point upperLeft;
    Point bottomRight;

    public Rectangle(Color color, boolean filled, Point upperLeft, Point bottomRight) {
        this.color = color;
        this.filled = filled;
        this.upperLeft = upperLeft;
        this.bottomRight = bottomRight;
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public boolean isFilled() {
        return filled;
    }

    public void setFilled(boolean filled) {
        this.filled = filled;
    }

    public Point getUpperLeft() {
        return upperLeft;
    }

    public void setUpperLeft(Point upperLeft) {
        this.upperLeft = upperLeft;
    }

    public Point getBottomRight() {
        return bottomRight;
    }

    public void setBottomRight(Point bottomRight) {
        this.bottomRight = bottomRight;
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "color=" + color +
                ", filled=" + filled +
                ", upperLeft=" + upperLeft +
                ", bottomRight=" + bottomRight +
                '}';
    }

    @Override
    public void resize(double d) {
        bottomRight.x = (int) (upperLeft.x + ((bottomRight.x - upperLeft.x) * d));
        bottomRight.y = (int) (upperLeft.y - ((upperLeft.y - bottomRight.y) * d));
    }

    @Override
    public double getArea() {
        return (bottomRight.x - upperLeft.x) * (upperLeft.y - bottomRight.y);
    }

    @Override
    public double getPerimeter() {
        return 2 * (bottomRight.x - upperLeft.x) + 2* (upperLeft.y - bottomRight.y);
    }

    @Override
    public void move(Point p) {
        bottomRight.translate(p.x, p.y);
        upperLeft.translate(p.x, p.y);
    }
}
