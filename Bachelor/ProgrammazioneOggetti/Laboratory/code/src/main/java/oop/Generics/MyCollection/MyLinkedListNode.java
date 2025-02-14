package oop.Generics.MyCollection;


public class MyLinkedListNode<T> {
    T value;
    MyLinkedListNode<T> next;

    public MyLinkedListNode(T value) {
        this.value = value;
        this.next = null;
    }

    public MyLinkedListNode(T value, MyLinkedListNode<T> next) {
        this.value = value;
        this.next = next;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T dataValue) {
        value = dataValue;
    }

    public MyLinkedListNode<T> getNext() {
        return next;
    }

    public void setNext(MyLinkedListNode<T> nextValue) {
        next = nextValue;
    }
}
