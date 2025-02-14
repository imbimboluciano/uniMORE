package oop.ObjectOriented;

import java.util.ArrayList;

/*
Write a class for authoring a simple letter.
 */

public class Letter {

    String from;
    String to;

    ArrayList<String> lines;


    public Letter(String from, String to) {
        this.from = from;
        this.to = to;
        lines = new ArrayList<>();
    }


    public void addLine(String line){
        lines.add(line);
    }

    public String getText(){
        StringBuilder sb = new StringBuilder();

        sb.append("Dear ").append(to).append(":\n").append("\n");
        for (String line :
             lines) {
            sb.append(line).append("\n");
        }
        sb.append("\n").append("Sincerely,\n").append("\n").append(from);

        return sb.toString();

    }
}
