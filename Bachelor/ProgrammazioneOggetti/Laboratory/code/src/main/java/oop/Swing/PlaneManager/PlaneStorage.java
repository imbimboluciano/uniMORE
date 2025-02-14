package oop.Swing.PlaneManager;


import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class PlaneStorage {

    public static List<Plane> load(Path path) throws IOException{
        List<Plane> planes = new ArrayList<>();
        Scanner sc = new Scanner(path); // The Scanner class is used to get user input
        while(sc.hasNextLine()){ //controllo che il file contenga un'altra linea
            String[] fields = sc.nextLine().split(";"); // essendpo un CSV i campi sono divisi da ;
            planes.add(new Plane(fields[0],fields[1],
                    Double.parseDouble(fields[2]),
                    Double.parseDouble(fields[3]),
                    Double.parseDouble(fields[4]),
                    fields[5])); //aggiungo alla lista un nuovo aereo
        }
        sc.close();
        return planes;
    }


    public static void save(List<Plane> planes,Path path) throws IOException{
        List<String> lines = new ArrayList<>();
        for (Plane p:
             planes) {
            lines.add(p.toCSV());
        }
        Files.write(path,lines); //con path intendiamo l'indirizzo in cui salvare il file
    }



}
