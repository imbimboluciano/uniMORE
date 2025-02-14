package oop.Swing.PlaneManager;

import com.formdev.flatlaf.FlatDarculaLaf;

import javax.swing.*;
import java.io.IOException;
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

    private List<Plane> planes;
    private int selectedObject;

    public PlaneManagerUI(){
        super();







        initData();
        generateMenu();
        showItem();
        buttonBehaviours();


        setTitle("Plane Manager");
        setContentPane(MainPanel);
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setSize(420,300);
        setResizable(false);
        setVisible(true);

    }

    void generateMenu(){ //funzione per generare un menu
        //si parte dagli item del menu

        JMenuItem open = new JMenuItem("Open...");
        JMenuItem save = new JMenuItem("Save...");
        JMenuItem close = new JMenuItem("Close");

        //creiamo gli eventi
        open.addActionListener(e -> {
            //dialogo con il file system
            JFileChooser chooser = new JFileChooser();
            int option = chooser.showSaveDialog(null); //facciamo selezionare il file all'utente
            if(option == JFileChooser.APPROVE_OPTION){
                try {
                    planes = PlaneStorage.load(chooser.getSelectedFile().toPath());
                    showItem();
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(null,"Qualcosa é andato storto!!");
                }
            }

        });

        close.addActionListener(e -> {
            dispose(); // metodo del Jframe che chiude la finestra
        });

        save.addActionListener(e -> {
            JFileChooser chooser = new JFileChooser();
            int option = chooser.showSaveDialog(null); //facciamo selezionare il file all'utente
            if(option == JFileChooser.APPROVE_OPTION){
                try {
                    PlaneStorage.save(planes,chooser.getSelectedFile().toPath());
                } catch (IOException ex) {
                    JOptionPane.showMessageDialog(null,"Qualcosa é andato storto!!");
                }
            }
        });

        //attacchiamo gli item al menu
        JMenu file = new JMenu("File");
        file.add(open);
        file.add(save);
        file.add(close);

        //attacchiamo il menu alla barra del menu
        JMenuBar bar = new JMenuBar();
        bar.add(file);

        //attachiamo la barra al frame

        setJMenuBar(bar);
    }

    void initData(){ // inizializziamo la lista

        planes = new ArrayList<>();
        /*planes.add(new Plane("Ita","Airways",10.2,3.4,10.2,"TGDF"));
        planes.add(new Plane("France","Airline",15.2,3.9,15.2,"HYTR"));
        planes.add(new Plane("Dubai","Airline",30.5,8.9,30.5,"DTRY"));*/

        selectedObject = 0;
    }

    void showItem(){ //visualizza l'aereo sull'interfaccia grafica
        try {
            Plane p = planes.get(selectedObject);
            tfName.setText(p.getNomeAereo());
            tfCompany.setText(p.getCompagnia());
            tfWidth.setText(Double.toString(p.getWidth()));
            tfHeight.setText(Double.toString(p.getHeight()));
            tfWingSpan.setText(Double.toString(p.getWingSpan()));
            tfCode.setText(p.getIdCode());
        }catch (IndexOutOfBoundsException e){
            tfName.setText("");
            tfCompany.setText("");
            tfWidth.setText("");
            tfHeight.setText("");
            tfWingSpan.setText("");
            tfCode.setText("");
        }


    }

    void buttonBehaviours(){
        btNext.addActionListener(e -> {
            //selectedObject = Math.min(planes.size() - 1,selectedObject++);
            if(selectedObject < planes.size() - 1) {
                selectedObject = selectedObject + 1;
                showItem();
            }

        });

        btPrevious.addActionListener(e -> {
            if(selectedObject > 0){
                selectedObject = selectedObject - 1;
                showItem();
            }
        });

        btRemove.addActionListener(e -> {
            Plane p = planes.get(selectedObject);
            planes.remove(p); //per questa remove dobbiamo implementare hasdcode e equals
            selectedObject -= 1;
            showItem();
        });

        btInsert.addActionListener(e -> {
            String[] planeStr = JOptionPane.showInputDialog("Inserire un nuovo aereo (Nome;Compagnia;Width;Height;WingSpan;IDCode):").split(";");
            planes.add(new Plane(
                    planeStr[0],
                    planeStr[1],
                    Double.parseDouble(planeStr[2]),
                    Double.parseDouble(planeStr[3]),
                    Double.parseDouble(planeStr[4]),
                    planeStr[5]
                    ));
            selectedObject += planes.size() - 1;
            showItem();
        });



    }
}
