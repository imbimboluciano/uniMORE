package oop.ObjectOriented;

import java.util.Arrays;

/**
 * Implementare una classe StringProcessor per effettuare operazioni su array di stringhe.
 * Metodi:
 *
 * public StringProcessor(String[] v): Costruttore
 * public int findShortest(): ritorna l'indice della stringa piÃ¹ corta
 * public int search(String key): ritorna l'indice dell'elemento key. -1 se non trovato.
 * public void reverse(): capovolge l'ordine delle stringhe
 * public boolean equals(Object obj)
 *
 * @author Nicola Bicocchi
 */
public class StringProcessor {

    String[] v;

    public StringProcessor(String[] v) {
        this.v = v;
    }

    public int findShortest(){
        if (v.length == 0) {
            return -1;
        }
        int min = v[0].length();
        int iMin = 0;
        for (int i = 1; i < v.length; i++) {
            if(v[i].length() < min){
                min = v[i].length();
                iMin = i;
            }
        }
        return iMin;
    }


    public int search(String key){
        for (int i = 1; i < v.length; i++) {
            if(key.equals(v[i])){
                return i;
            }
        }
        return -1;
    }
    public void reverse(){
        for (int i = 0; i < v.length / 2; i++) {
            String tmp = v[i];
            v[i] = v[v.length - 1 - i];
            v[v.length - 1 - i] = tmp;
        }
    }

    @Override
    public boolean equals(Object obj){
        if(this == obj){
            return true;
        }
        if (!(obj instanceof StringProcessor))
            return false;
        StringProcessor that = (StringProcessor) obj;
        return Arrays.equals(v, that.v);
    }
}

