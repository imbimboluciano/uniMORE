package commandPattern.campane;

public class TestApp {

    public static void main(String[] args) {

        Scheduler scheduler = new Scheduler();

        CampanaCommand campanaIVento = new CampanaCommand(new Vento(new CampanaI()));
        CampanaCommand campanaOEco = new CampanaCommand(new Eco(new CampanaO()));
        scheduler.setCommand(campanaIVento);
        scheduler.suona();
        scheduler.setCommand(campanaOEco);
        scheduler.suona();




    }
}
