package oop.Generics.MyCollection;

import java.util.Arrays;

public class MyArrayList<T> extends MyAbstractList<T>{



    Object[] elements;
    final static int INITIAL_SIZE = 16;

    public MyArrayList() {
        super();
        elements = new Object[INITIAL_SIZE];
    }

    @Override
    public void add(T obj) {
        if(size >= elements.length - 1){
            enlarge();
        }
        elements[size++] = obj; // aggiunge elemento alla fine
    }

    @Override
    public void remove(T obj) {
        if(contains(obj)){
            for (int i = 0; i < size; i++) {
                if(elements[i].equals(obj)){
                    remove(i);
                    return;
                }
            }
        }

    }

    @Override
    public void remove(int index) {
        checkBoundaries(index,size - 1);

        System.arraycopy(elements,index + 1,elements,index,size - index);
        elements[--size] = null;
    }

    @Override
    public T get(int index) {
        checkBoundaries(index,size - 1);
        return  (T) elements[index];

    }

    @Override
    public void add(T obj, int index) {
        checkBoundaries(index, size - 1);
        add(obj);

        if( elements.length - 1 - index >= 0){
            System.arraycopy(elements,index,elements,index + 1,elements.length - 1 - index);
        }
        elements[index] = obj;
        elements[size] = null;

    }

    void enlarge(){
        Object[] tmp = new Object[elements.length * 2];
        System.arraycopy(elements,0,tmp,0,elements.length);
        elements = tmp;
    }
}
