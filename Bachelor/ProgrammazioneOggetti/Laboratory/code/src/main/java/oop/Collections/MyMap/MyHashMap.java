package oop.Collections.MyMap;

import java.util.Calendar;
import java.util.HashMap;

public class MyHashMap implements MyMap{

    MyHashMapEntry[] table;
    static final int INITIAL_SIZE = 8;
    int size;

    public MyHashMap() {
        this.table = new MyHashMapEntry[INITIAL_SIZE];
    }

    @Override
    public int size() {
       return size;
    }

    public double capacityRatio(){
        return size / (double)table.length;
    }

    @Override
    public void put(Object key, Object value) {
        if(capacityRatio() > 0.6){
            enlarge();
        }
        int bucket = getBucket(key);
        if(table[bucket] == null){
            table[bucket] = new MyHashMapEntry(key,value);
            size++;
        }
    }

    @Override
    public void remove(Object key) {
        int bucket = getBucket(key);
        if(table[bucket] != null){
            table[bucket] = null;
            size--;
        }


    }

    @Override
    public boolean contains(Object o) {
        int bucket = getBucket(o);
        return table[bucket] != null;
    }

    @Override
    public Object get(Object key) {
        int bucket = getBucket(key);
        if(table[bucket] != null){
            return table[bucket].getValue();
        }

        return -1;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < table.length; i++) {
            if(table[i] == null){
                sb.append(String.format("Bucket %d - > null",i));
            }else{
                sb.append(String.format("Bucket %d - > key:%s value:%s",i,table[i].getKey(),table[i].getValue()));
            }
        }
        return sb.toString();
    }

    // funzione per raddoppiare la dimensione
    void enlarge(){
        MyHashMapEntry[] tmp = new MyHashMapEntry[table.length * 2];
        System.arraycopy(table,0,tmp,0,tmp.length);
        table = tmp;
    }

    // funzione per capire in che posizione inserire l'elemento
    int getBucket(Object key) {
        int bucket = (Math.abs(key.hashCode()) % table.length); //funzione di hash
        while (table[bucket] != null && table[bucket].getKey() != key) { //cerca la codifca corrispondente
            bucket = (bucket + 1) % table.length;
        }
        return bucket;
    }
}
