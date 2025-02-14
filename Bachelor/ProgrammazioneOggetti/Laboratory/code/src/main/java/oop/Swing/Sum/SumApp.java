package oop.Swing.Sum;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class SumApp extends JFrame{



    JTextField firstNumber;
    JTextField secondNumber;
    JButton plus;
    JTextField result;

    public SumApp() throws HeadlessException {

        super("Celsius Converter");
        firstNumber = new JTextField("primo numero");
        secondNumber = new JTextField("secondo numero");
        plus = new JButton("+");
        plus.setSize(40,40);
        result = new JTextField("Risultato");

        plus.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                    int x = Integer.parseInt(firstNumber.getText());
                    int y =  x + Integer.parseInt(secondNumber.getText());
                    result.setText(String.valueOf(y));
            }
        });


        JPanel mainPanel = new JPanel();
        mainPanel.add(firstNumber);
        mainPanel.add(plus);
        mainPanel.add(secondNumber);
        mainPanel.add(result);


        setContentPane(mainPanel);
        setSize(200,200);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setVisible(true);
    }


    public static void main(String[] args) {
        try {
            UIManager.setLookAndFeel("javax.swing.plaf.metal.MetalLookAndFeel");
        } catch(Exception ignored){}

        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new SumApp();
            }
        });
    }



}
