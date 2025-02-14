package oop.Jdbc.PlaneManager;

import oop.Utils.DBManager;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
public class PlaneManagerUI extends JFrame{
    private JPanel MainPanel;
    private JPanel TextPanel;
    private JTextField tfName;
    private JTextField tfCompany;
    private JTextField tfWidth;
    private JTextField tfHeight;
    private JTextField tfWingSpan;
    private JTextField tfCode;
    private JPanel ButtonPanel;
    private JButton btNext;
    private JButton btPrevious;
    private JButton btInsert;
    private JButton btRemove;

    private ResultSet planes;

    public PlaneManagerUI() throws SQLException{
        super();


        generateMenu();



        buttonBehaviours();
        tfBehaviours();


        setTitle("Plane Manager");
        setContentPane(MainPanel);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(420,300);
        setResizable(false);
        setVisible(true);

        try {
            initData();
            showItem();
        }catch (SQLException e){
            JOptionPane.showMessageDialog(null, e.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
        }

    }

    void generateMenu(){ //funzione per generare un menu
        //si parte dagli item del menu

        JMenuItem fillDB = new JMenuItem("Fill DB...");
        JMenuItem close = new JMenuItem("Close");

        //creiamo gli eventi

        fillDB.addActionListener(e ->{
            JFileChooser chooser = new JFileChooser();
            int option = chooser.showSaveDialog(null);
            if(option == JFileChooser.APPROVE_OPTION){
                try{
                    List<Plane> planes = PlaneStorage.loadFromFile(chooser.getSelectedFile().toPath());
                    PlaneStorage.saveToDB(planes,DBManager.getConnection());
                    initData();
                    showItem();
                }catch (IOException | SQLException ex){
                    JOptionPane.showMessageDialog(null, ex.getMessage(), "Error", JOptionPane.ERROR_MESSAGE);
                }
            }
        });

        close.addActionListener(e -> {
            dispose(); // metodo del Jframe che chiude la finestra
        });



        //attacchiamo gli item al menu
        JMenu file = new JMenu("File");
        file.add(fillDB);
        file.add(close);

        //attacchiamo il menu alla barra del menu
        JMenuBar bar = new JMenuBar();
        bar.add(file);

        //attachiamo la barra al frame

        setJMenuBar(bar);
    }

    void initData() throws SQLException { // inizializziamo la lista

        DBManager.setConnection(DBManager.JDBC_Driver_MySQL,DBManager.JDBC_URL_MySQL);
        PreparedStatement statement = DBManager.getConnection().prepareStatement(
                "SELECT * FROM planes",ResultSet.TYPE_SCROLL_SENSITIVE,ResultSet.CONCUR_UPDATABLE);
        planes = statement.executeQuery();
        planes.first(); // mi posiziono sul primo

    }

    void showItem() { //visualizza l'aereo sull'interfaccia grafica

        Plane p = getSelected();
        if(p == null){
            tfName.setText("");
            tfCompany.setText("");
            tfWidth.setText("");
            tfHeight.setText("");
            tfWingSpan.setText("");
            tfCode.setText("");
        }else{
            tfName.setText(p.getNomeAereo());
            tfCompany.setText(p.getCompagnia());
            tfWidth.setText(Double.toString(p.getWidth()));
            tfHeight.setText(Double.toString(p.getHeight()));
            tfWingSpan.setText(Double.toString(p.getWingSpan()));
            tfCode.setText(p.getIdCode());
        }

    }
    Plane getSelected() {

        Plane p = null;
        try {
            p = new Plane(planes.getString(1),
                    planes.getString(2),
                    planes.getDouble(3),
                    planes.getDouble(4),
                    planes.getDouble(5),
                    planes.getString(6));
        } catch (SQLException e) {}

        return p;
    }

    void buttonBehaviours() {
        btNext.addActionListener(e -> {
            try {
                if(!planes.isLast()){
                    planes.next();
                }
            } catch (SQLException ignored) {}
            showItem();
        });

        btPrevious.addActionListener(e -> {
            try{
                if(!planes.isFirst()){
                    planes.previous();
                }
            }catch (SQLException ignored){}
            showItem();
        });

        btRemove.addActionListener(e -> {
            try {
                planes.deleteRow();
            }catch (SQLException ignored){}
            showItem();
        });

        btInsert.addActionListener(e -> {
            String[] planeStr = JOptionPane.showInputDialog("Inserire un nuovo aereo (Nome;Compagnia;Width;Height;WingSpan;IDCode):").split(";");
            try{
                planes.moveToInsertRow();
                planes.updateString("name", planeStr[0]);
                planes.updateString(2,planeStr[1]);
                planes.updateDouble(3,Double.parseDouble(planeStr[2]));
                planes.updateDouble(4, Double.parseDouble(planeStr[3]));
                planes.updateDouble(5,Double.parseDouble(planeStr[4]));
                planes.updateString(6,planeStr[5]);
                planes.insertRow();
                planes.last();
            }catch (SQLException ignored){}
            showItem();
        });


    }

    void tfBehaviours(){

        tfName.addActionListener(e -> {
            try {
                planes.updateString(1,tfName.getText());
                planes.updateRow();
            } catch (SQLException ex) {}
        });

        tfCompany.addActionListener(e ->{
            try {
                planes.updateString(2,tfCompany.getText());
                planes.updateRow();
            } catch (SQLException ex) {}
        });

        tfWidth.addActionListener(e -> {
            try {
                planes.updateDouble(3,Double.parseDouble(tfWidth.getText()));
                planes.updateRow();
            } catch (SQLException ex) {}
        });

        tfHeight.addActionListener(e ->{
            try {
                planes.updateDouble(4,Double.parseDouble(tfHeight.getText()));
                planes.updateRow();
            } catch (SQLException ex) {}
        });

        tfWingSpan.addActionListener(e -> {
            try {
                planes.updateDouble(5,Double.parseDouble(tfWingSpan.getText()));
                planes.updateRow();
            } catch (SQLException ex) {}
        });


        tfCode.addActionListener(e -> {
            try {
                planes.updateString(6,tfCode.getText());
                planes.updateRow();
            } catch (SQLException ex) {}
        });
    }
}
