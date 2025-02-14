package oop.ObjectOriented.Reverser;

public class EngineSlow implements Reverser {


    public EngineSlow() {
    }

    @Override
    public String reverse(String s) {
        String rev = "";
        for (int i = s.length() - 1; i >= 0; i--) {
            rev += s.charAt(i);
        }
        return rev;
    }
}
