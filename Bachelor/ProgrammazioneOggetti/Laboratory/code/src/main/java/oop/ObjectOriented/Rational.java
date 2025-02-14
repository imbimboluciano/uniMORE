package oop.ObjectOriented;

/**
 * Implementare una classe Rational che rappresenta un numero razionale.
 *
 * Il costruttore accetta numeratore e denominatore. Se il denominatore eÌ€ uguale a 0, viene lanciata una eccezione.
 *
 * Il metodo plus() prende un altro Rational x come argomento e restituisce la somma.
 * Il metodo times() prende un altro Rational x come argomento e restituisce il prodotto.
 *
 * La classe Rational deve inoltre essere ordinabile implementando lâ€™interfaccia Comparable<Rational>
 *
 * @author Nicola Bicocchi
 */

public class Rational implements Comparable<Rational>{

    int numerator;
    int denominator;

    public Rational(int numeratore, int denominatore) {
        if(denominatore == 0){
            throw new IllegalArgumentException("Il denominatore deve essere diverso da 0");
        }else{
            this.numerator = numeratore;
            this.denominator = denominatore;
        }

    }

    public Rational plus(Rational x){
        int newNumerator = this.numerator * x.denominator + x.numerator * this.denominator;
        int newDenominator = this.denominator * x.denominator;
        return new Rational(newNumerator,newDenominator);
    }

    public Rational times(Rational x){
        int newNumerator = this.numerator * x.numerator;
        int newDenominator = this.denominator * x.denominator;
        return new Rational(newNumerator,newDenominator);
    }


    @Override
    public int compareTo(Rational o) {
        return Double.compare( numerator / (double)denominator, o.numerator / (double)o.denominator);
    }

    @Override
    public String toString() {
        return "Rational{" +
                "numerator=" + numerator +
                ", denominator=" + denominator +
                '}';
    }
}

