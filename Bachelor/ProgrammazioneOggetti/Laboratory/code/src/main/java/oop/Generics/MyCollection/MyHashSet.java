package oop.Generics.MyCollection;

public class MyHashSet<T> extends MyAbstractSet<T>{
    @Override
    T[] toArray() {
        return (T[]) table;
    }

    @Override
    public void add(T obj) {
        if(capacityRatio() > 0.6){
            enlarge();
        }
        int bucket = getBucket(obj);
        if(table[bucket] == null){
            table[bucket] = obj;
            size++;
        }
    }

    @Override
    public void remove(T obj) {
        int bucket = getBucket(obj);
        table[bucket] = null;
        size--;
    }

    @Override
    public boolean contains(T obj) {
        int bucket = getBucket(obj);
        return table[bucket] != null;
    }

    int getBucket(T obj){
        int bucket = Math.abs(obj.hashCode()) % table.length;
        while (table[bucket] != null && table[bucket].hashCode() != obj.hashCode()) {
            bucket = (bucket + 1) % table.length;
        }
        return bucket;
    }
}
