package oop.Jdbc.PlaneManager;

import java.io.IOException;
import java.nio.file.Path;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PlaneStorage {

    public static List<Plane> loadFromDB(Connection connection) throws SQLException {
        List<Plane> planes = new ArrayList<>();
        try (PreparedStatement getPlanes = connection.prepareStatement("SELECT * from planes")) {
            try (ResultSet rs = getPlanes.executeQuery()) {
                while (rs.next()) {
                    planes.add(new Plane(rs.getString(1),
                            rs.getString(2),
                            rs.getDouble(3),
                            rs.getDouble(4),
                            rs.getDouble(5),
                            rs.getString(6)));
                }
            }
        }
        return planes;
    }


    public static void saveToDB(List<Plane> planes,Connection connection) throws SQLException{

        try(PreparedStatement dropTable = connection.prepareStatement("DROP TABLE IF EXISTS planes")){
            dropTable.executeUpdate(); // executeQuery() serve per produrre il resultset
        }

        try(PreparedStatement createTable = connection.prepareStatement("CREATE TABLE planes (name VARCHAR(50), " +
            "company VARCHAR(50), width DOUBLE, height DOUBLE, wingspan DOUBLE, IDCode VARCHAR(50) PRIMARY KEY)")){
            createTable.executeUpdate();
        }

        try(PreparedStatement insertPlane = connection.prepareStatement("INSERT INTO planes (name, company, width, height, wingspan, IDCode) VALUES (?, ?, ?, ?, ?, ?)")){
            for (Plane p:
                 planes) {
                insertPlane.setString(1,p.getNomeAereo());
                insertPlane.setString(2,p.getCompagnia());
                insertPlane.setDouble(3,p.getWidth());
                insertPlane.setDouble(4,p.getHeight());
                insertPlane.setDouble(5,p.getWingSpan());
                insertPlane.setString(6,p.getIdCode());
                insertPlane.executeUpdate();
            }
        }
    }

    public static List<Plane> loadFromFile(Path path) throws IOException{
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
}
