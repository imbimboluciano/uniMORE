package oop.ObjectOriented;

/**
 * Scrivere una classe Table per rappresentare tavole pitagoriche.
 * Metodi:
 *
 * Table()      costruttore senza parametri che configura una tavola 10x10
 * Table(a, b)  costruttore che configura una tavola axb
 * toString()   ritorna una stringa che rappresenta la tavola
 * double sum() ritorna la somma di tutti i numeri presenti nella tavola
 * double avg() ritorna la media di tutti i numeri presenti nella tavola
 */

public class Table {
    private int height;
    private int length;

    public Table() {
        this.height = 10;
        this.length = 10;
    }

    public Table(int a, int b) {
        this.height = b;
        this.length = a;
    }

    public double sum(){
        double sum = 0;
        for (int i = 1; i <=length; i++) {
            for (int j = 1; j <= height ; j++) {
                sum += i * j;
            }
        }
        return sum;
    }

    public double avg(){
        return sum()/ (length * height);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <=length; i++) {
            for (int j = 1; j <= height ; j++) {
                sb.append(i*j);
                sb.append("\t");
            }
            sb.append("\n");
        }
        return sb.toString();
    }
}
