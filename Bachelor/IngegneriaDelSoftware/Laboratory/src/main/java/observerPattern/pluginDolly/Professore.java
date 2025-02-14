package observerPattern.pluginDolly;


import java.util.ArrayList;
import java.util.List;

public class Professore implements Subject{

    private List<Observer> observers;
    private List<String> materialeDidattico;

    public Professore() {
        observers = new ArrayList<>();
        materialeDidattico = new ArrayList<>();
    }

    @Override
    public void registerObserver(Observer o) {
        observers.add(o);
    }

    @Override
    public void removeObserver(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o:
             observers) {
            o.update(materialeDidattico);
        }
    }

    public void setMaterialeDidattico(String materialeDidattico) {
        this.materialeDidattico.add(materialeDidattico);
        notifyObservers();
    }
}
