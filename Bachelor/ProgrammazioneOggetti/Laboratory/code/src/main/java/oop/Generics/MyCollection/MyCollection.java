package oop.Generics.MyCollection;

public interface MyCollection<T> {
    void add(T obj);
    void remove(T obj);
    boolean contains(T obj);
    int size();
}
