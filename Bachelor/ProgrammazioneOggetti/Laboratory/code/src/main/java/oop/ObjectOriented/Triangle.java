package oop.ObjectOriented;

/**
 * Write a class representing a Triangle
 * Methods:
 * double getArea()
 * double getPerimeter()
 *
 * @author Nicola Bicocchi
 */
public class Triangle {

    private double length;
    private double height;

    public Triangle(int length, int height) {
        this.length = length;
        this.height = height;
    }

    public double getArea(){
        return (length * height) / 2;
    }

    public double getPerimeter(){
        //return height * Math.sqrt(12);
        return length + 2 * Math.hypot(height, length / 2);
    }

    @Override
    public String toString() {
        return "Triangle{" +
                "length=" + length +
                ", height=" + height +
                '}';
    }
}