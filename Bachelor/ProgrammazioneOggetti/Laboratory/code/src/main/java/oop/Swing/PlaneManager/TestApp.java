package oop.Swing.PlaneManager;

import com.formdev.flatlaf.FlatDarculaLaf;

import javax.swing.*;

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
                new PlaneManagerUI();
            }
        });
    }
}
