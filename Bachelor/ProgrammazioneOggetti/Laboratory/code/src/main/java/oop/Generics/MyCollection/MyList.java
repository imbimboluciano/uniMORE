package oop.Generics.MyCollection;

public interface MyList<T> extends MyCollection<T>{

    void remove(int index);
    T get(int index);
    void add(T obj,int index);
}
