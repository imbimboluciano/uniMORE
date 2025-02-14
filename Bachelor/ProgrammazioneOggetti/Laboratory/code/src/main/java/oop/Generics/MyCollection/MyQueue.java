package oop.Generics.MyCollection;

public interface MyQueue<T> extends MyCollection<T>{

    T poll();
    T peek();
}
