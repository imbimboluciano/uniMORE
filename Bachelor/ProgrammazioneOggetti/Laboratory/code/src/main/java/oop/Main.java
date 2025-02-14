package oop;

public class Main {

    public static void main(String[] args) {
        String s = new String("Hello");
        System.out.println(s.charAt(0));
        System.out.println(s.compareTo("hello"));
        System.out.println(s.concat("World"));
        System.out.println(s.endsWith("lo"));
        System.out.println(s.startsWith("He"));
        System.out.println(s.isEmpty());
        System.out.println(s.length());
        System.out.println(s.substring(2,3));
        System.out.println(String.valueOf(5));
        System.out.println(s.replace('l','c'));
        System.out.println(s.contains("e")); //true

        String amici = "Mario,Luca,Claudio";
        if (amici.contains(",")) {
            String[] nomi = amici.split(",");
            for (int i = 0; i < nomi.length; i++) {
                System.out.println(nomi[i]);
            }
        }
    }
}
