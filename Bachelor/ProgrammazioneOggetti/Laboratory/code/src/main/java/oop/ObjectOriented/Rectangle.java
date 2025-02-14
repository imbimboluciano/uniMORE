package oop.ObjectOriented;

/**
 * Write a class representing a Rectangle
 * Methods:
 * double getArea()
 * double getPerimeter()
 *
 * @author Nicola Bicocchi
 */
public class Rectangle {

    private double height;
    private double length;

    public Rectangle(double length,double height){
        this.height = height;
        this.length = length;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    public double getLength() {
        return length;
    }

    public void setLength(double length) {
        this.length = length;
    }

    public double getArea(){
        return height * length;
    }

    public double getPerimeter(){
        return (height + length) * 2;
    }

    @Override
    public String toString() {
        return "Rectangle{" +
                "height=" + height +
                ", length=" + length +
                '}';
    }
}
