package observerPattern.pluginDolly;

/*Si vuole implementare un plugin di Dolly per il quale ogni studente viene avvisato quando il docente inserisce del nuovo materiale didattico*/

public class TestApp {
    public static void main(String[] args) {

        Professore guerra = new Professore();
        Studente luciano = new Studente(guerra);

        guerra.setMaterialeDidattico("Clean Code");
        guerra.setMaterialeDidattico("IS-11");
        guerra.setMaterialeDidattico("Head First Design Patterns");

    }
}
