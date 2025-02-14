package oop.Generics.MyCollection;

public class MyArraySet<T> extends MyAbstractSet<T>{


    public MyArraySet() {
        super();
    }

    @Override
    T[] toArray() {
        return (T[]) table;
    }

    @Override
    public void add(T obj) {
        if(capacityRatio() > 0.6){
            enlarge();
        }
        table[size++] = obj;
    }

    @Override
    public void remove(T obj) {
        int index = getIndex(obj);
        if(index == -1) return;
        System.arraycopy(table,index + 1,table,index,size - index);
        table[--size] = null;
    }

    @Override
    public boolean contains(T obj) {
        int index = getIndex(obj);
        return  index != -1;
    }

    int getIndex(T obj){
        for (int i = 0; i < size; i++) {
            if(table[i].hashCode() == obj.hashCode()){
                return i;
            }
        }
        return -1;
    }
}
