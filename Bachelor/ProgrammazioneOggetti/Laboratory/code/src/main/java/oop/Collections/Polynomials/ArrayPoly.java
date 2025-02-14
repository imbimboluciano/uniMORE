package oop.Collections.Polynomials;

public class ArrayPoly extends AbstractPoly{

    double[] coefficients;

    public ArrayPoly(double[] coefficients) {
        this.coefficients = coefficients;
    }

    @Override
    public double[] coefficients() {
        return coefficients;
    }

    @Override
    public double coefficient(int value) {
        return coefficients[value];
    }

    @Override
    public int degree() {
        return coefficients.length - 1;
    }

    @Override
    public Poly derivative() {
        return new ArrayPoly(derive());
    }
}
