package oop.ObjectOriented;

/*
    Write a class named RationalNumber representing a rational number.
RationalNumbers are immutable objects, indeed they cannot be changed after creation.
Internally, the class represents numerator and denominator as int values. RationalNumbers must support equality with other RationalNumbers (see Object.equals(), Object.hashCode())
The class provides the following methods:
* public RationalNumber(int numerator, int denominator) creating the rational number.
* public getNumerator() returning the numerator.
* public getDenominator() returning the denominator.
* public RationalNumber add(RationalNumber o) for adding another number to the current number.
* public RationalNumber multiply(RationalNumber o) for multiplying another number with the current number.
* public String toString().

 */

import java.util.Objects;

public class RationalNumber {

    private int numerator;
    private int denominator;

    public RationalNumber(int numerator, int denominator) {
        this.numerator = numerator;
        this.denominator = denominator;
    }


    public RationalNumber add(RationalNumber o){

        this.numerator = (this.numerator * o.denominator) + (o.numerator * this.denominator);
        this.denominator *= denominator;

        return this;
    }

    public RationalNumber multiply(RationalNumber o){

        this.numerator *= o.numerator;
        this.denominator *= o.denominator;

        return this;
    }


    public int getNumerator() {
        return numerator;
    }

    public int getDenominator() {
        return denominator;
    }


    @Override
    public String toString() {
        return "RationalNumber{" +
                "numerator=" + numerator +
                ", denominator=" + denominator +
                '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        RationalNumber that = (RationalNumber) o;
        return numerator == that.numerator && denominator == that.denominator;
    }

    @Override
    public int hashCode() {
        return Objects.hash(numerator, denominator);
    }
}
