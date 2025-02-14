package observerPattern.pluginDolly;

import java.util.ArrayList;
import java.util.List;

public class Studente implements Observer,NotifyElement{

    private List<String> materiale;

    private Subject professore;

    public Studente(Subject professore) {
        this.professore = professore;
        materiale = new ArrayList<>();
        professore.registerObserver(this);
    }

    @Override
    public void notification() {
        System.out.println("E' stato aggiunto il seguente materiale: " + materiale.get(materiale.size() - 1));

    }

    @Override
    public void update(List<String> materialeDidattico) {

        this.materiale = materialeDidattico;
        notification();

    }
}
