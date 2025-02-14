package oop.Jdbc.SimpleDB;

import java.sql.SQLException;

public class TestApp {
    public static void main(String[] args) {
        try {
            new OperationDB();
        }catch (SQLException e){
            e.printStackTrace();
        }
    }
}
