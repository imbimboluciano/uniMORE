package oop.ObjectOriented.Reverser;

public class EngineBest implements Reverser {

    public EngineBest() {
    }

    @Override
    public String reverse(String s) {
        StringBuilder sb = new StringBuilder(s);
        return sb.reverse().toString();
    }
}
