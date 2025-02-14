package oop.Collections.Polynomials;

public interface Poly {

    double[] coefficients();
    double coefficient(int value);
    int degree();
    Poly derivative();
}
