package oop.ObjectOriented.Shape3;

import java.awt.*;

public class Rectangle extends AbstractShape{

    Point upperLeft;
    Point bottomRight;

    public Rectangle(Color color, boolean filled, Point upperLeft, Point bottomRight) {
        super(color, filled);
        this.upperLeft = upperLeft;
        this.bottomRight = bottomRight;
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

    @Override
    public String toString() {
        return "Rectangle{" +
                "color=" + color +
                ", filled=" + filled +
                ", upperLeft=" + upperLeft +
                ", bottomRight=" + bottomRight +
                '}';
    }
}
