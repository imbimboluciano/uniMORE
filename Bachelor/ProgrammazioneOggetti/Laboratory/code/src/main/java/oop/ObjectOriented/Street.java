package oop.ObjectOriented;

/**
 * Implementare una classe Street, che rappresenta una strada a senso unico. Il
 * costruttore accetta la lunghezza della strada in chilometri.
 *
 * insertCar() accetta un intero (km) come argomento ed aggiunge unâ€™automobile
 * al chilometro km. Lâ€™automobile inserita percorreraÌ€ la strada alla velocitaÌ€
 * di un chilometro al minuto, (60 km/h) fino alla fine della stessa.
 *
 * getCarsByPosition() riceve come parametro un intero (km) e restituisce il
 * numero di automobili presenti al chilometro km.
 *
 * progress() simula il passaggio di 1 minuto di tempo (cioeÌ€ fa avanzare tutte le automobili di un chilometro).
 *
 * @author Nicola Bicocchi
 */

public class Street {

    private int[] kmStreet;

    public Street(int length) {
        this.kmStreet = new int[length];
    }

    public int[] getCars() {
        return kmStreet;
    }

    public void insertCar(int km){
        kmStreet[km]++;
    }

    public int getCarsByPosition(int km){
        return kmStreet[km];
    }

    public void progress(){
        for (int i = kmStreet.length - 1; i > 0; i--) {
            kmStreet[i] = kmStreet[i - 1];
        }
        kmStreet[0] = 0;
    }

}
