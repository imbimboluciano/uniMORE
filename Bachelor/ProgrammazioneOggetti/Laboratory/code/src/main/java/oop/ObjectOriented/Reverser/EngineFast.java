package oop.ObjectOriented.Reverser;

public class EngineFast implements Reverser {


    public EngineFast() {
    }

    @Override
    public String reverse(String s) {
        StringBuilder rev = new StringBuilder();
        for (int i = s.length() - 1; i >= 0; i--) {
            rev.append(s.charAt(i));
        }

        return rev.toString();
    }
}
