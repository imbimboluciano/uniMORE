package oop.Collections.Polynomials;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ListPoly extends AbstractPoly{

    List<Double> coefficients;

    public ListPoly(double[] coefficients) {
        this.coefficients = new ArrayList<>();
        for (int i = 0; i < coefficients.length; i++) {
            this.coefficients.add(coefficients[i]);
        }
    }

    @Override
    public double[] coefficients() {
        double[] tmp = new double[coefficients.size()];
        for (int i = 0; i < tmp.length; i++) {
            tmp[i] = coefficients.get(i);
        }
        return tmp;
    }

    @Override
    public double coefficient(int value) {
        return coefficients.get(value);
    }

    public int degree(){
        return coefficients.size() - 1;
    }

    @Override
    public Poly derivative() {
        return new ListPoly(derive());
    }


}
