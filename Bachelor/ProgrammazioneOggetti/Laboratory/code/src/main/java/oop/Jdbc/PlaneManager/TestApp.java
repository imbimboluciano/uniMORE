package oop.Jdbc.PlaneManager;

import com.formdev.flatlaf.FlatDarculaLaf;

import javax.swing.*;
import java.sql.SQLException;

public class TestApp {
    public static void main(String[] args) {
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                try {
                    UIManager.setLookAndFeel(new FlatDarculaLaf()); // Look and feel
                } catch (UnsupportedLookAndFeelException e) {
                    e.printStackTrace();
                }
                try{
                    new PlaneManagerUI();
                }catch (SQLException e){
                    e.printStackTrace();
                }
            }
        });
    }
}
