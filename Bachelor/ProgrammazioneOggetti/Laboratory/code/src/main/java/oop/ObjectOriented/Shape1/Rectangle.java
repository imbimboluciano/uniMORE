package oop.ObjectOriented.Shape1;

import java.awt.*;

public class Rectangle extends Shape {

    Point upperLeft;
    Point bottomRight;

    public Rectangle(Color color, boolean filled, Point upperLeft, Point bottomRight) {
        super(color, filled);
        this.upperLeft = upperLeft;
        this.bottomRight = bottomRight;
    }

    @Override
    public void move(Point p) {
        upperLeft.translate(p.x, p.y);
        bottomRight.translate(p.x,p.y);
    }

    @Override
    public double getPerimeter() {
       double base = Point.distance(upperLeft.x,bottomRight.y,bottomRight.x,bottomRight.y);
       double height = Point.distance(upperLeft.x,upperLeft.y, upperLeft.x,bottomRight.y);
       return 2 * base + 2 * height;
    }

    @Override
    public double getArea() {
        double base = Point.distance(upperLeft.x,bottomRight.y,bottomRight.x,bottomRight.y);
        double height = Point.distance(upperLeft.x,upperLeft.y, upperLeft.x,bottomRight.y);
        return base * height;
    }

    @Override
    public void resize(double d) {
        bottomRight.x = (int) (upperLeft.x + ((bottomRight.y - upperLeft.x) * d));
        bottomRight.y = (int) (upperLeft.y - ((upperLeft.y - bottomRight.y) *d));
    }


    @Override
    public String toString() {
        return "Rectangle{" +
                "upperLeft=" + upperLeft +
                ", bottomRight=" + bottomRight +
                ", color=" + color +
                ", filled=" + filled +
                '}';
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
}
