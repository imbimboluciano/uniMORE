package oop.ObjectOriented.Polynomials;

import oop.ObjectOriented.PhoneBook.Person;

import java.util.Objects;

public abstract class AbstractPoly implements Poly{

    public AbstractPoly() {
    }

    double[] derive(){
        double[] derive = new double[degree()];
        for (int i = 1; i <= derive.length; i++) {
            derive[i - 1] = coefficient(i) * i;
        }
        return derive;
    }

    public boolean equals(Object o){
       if (o == null){
           return false;
       }

       if(! (o instanceof Poly p)){
           return false;
       }

       if(degree() != p.degree()){
           return false;
       }

        for (int i = 0; i <= p.degree(); i++) {
            if(coefficient(i) != p.coefficient(i)){
                return false;
            }
        }

        return true;
    }

    public  int hashCode(){
        return Objects.hashCode(coefficients());
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        for (int i = 0; i < degree(); i++) {
            sb.append(coefficient(i)).append("x^").append(i).append(" + ");
        }
        sb.append(coefficient(degree())).append("x^").append(degree());

        return sb.toString();

    }


}
