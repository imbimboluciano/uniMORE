package oop.ObjectOriented.Shape2;

import java.awt.*;

public interface Shape {
    public abstract void resize(double d);
    public abstract double getArea();
    public abstract double getPerimeter();
    public abstract void move(Point p);
}
