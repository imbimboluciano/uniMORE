package oop.ObjectOriented.Polynomials;

import java.util.ArrayList;
import java.util.Arrays;

public class ListPoly extends AbstractPoly{


    ArrayList<Double> coefficients;

    public ListPoly(double[] coefficients) {
        this.coefficients = new ArrayList<>();
        for (int i = 0; i < coefficients.length; i++) {
            this.coefficients.add(coefficients[i]);
        }
    }


    @Override
    public double coefficient(int degree) {
        return coefficients.get(degree);
    }

    @Override
    public double[] coefficients() {
        double[] ret = new double[coefficients.size()];
        for (int i = 0; i < coefficients.size(); i++) {
            ret[i] = coefficients.get(i);
        }

        return ret;
    }

    @Override
    public int degree() {
        return coefficients.size() - 1;
    }

    @Override
    public Poly derivative() {
        return new ListPoly(derive());
    }
}
