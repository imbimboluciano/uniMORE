package oop.Collections.Polynomials;

import java.util.Objects;

public abstract class AbstractPoly implements Poly{


    public AbstractPoly() {
    }

    public double[] derive(){
        double[] tmp = new double[Math.max(1,degree())];
        for (int i = 1; i <= degree(); i++) {
            tmp[i - 1] = coefficient(i) * i;
        }
        return tmp;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for(int i = degree(); i >= 1;i--){
            sb.append(coefficient(i));
            sb.append("x^");
            sb.append(i);
            sb.append(" + ");
        }
        sb.append(coefficient(0));
        return sb.toString();
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(coefficients());
    }

    @Override
    public boolean equals(Object obj) {
       if(obj == null){
           return false;
       }
       if(!(obj instanceof Poly p)){
           return false;
       }

       if(degree() != p.degree()){
           return false;
       }
        for (int i = 0; i <= degree(); i++) {
            if(coefficient(i) != p.coefficient(i)){
                return false;
            }
        }
    return true;
    }
}
