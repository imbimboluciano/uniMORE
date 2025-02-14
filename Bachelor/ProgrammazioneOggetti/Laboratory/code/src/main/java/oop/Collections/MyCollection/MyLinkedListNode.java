package oop.Collections.MyCollection;


public class MyLinkedListNode {
    Object value;
    MyLinkedListNode next;

    public MyLinkedListNode(Object value) {
        this.value = value;
        this.next = null;
    }

    public MyLinkedListNode(Object value, MyLinkedListNode next) {
        this.value = value;
        this.next = next;
    }

    public Object getValue() {
        return value;
    }

    public void setValue(Object dataValue) {
        value = dataValue;
    }

    public MyLinkedListNode getNext() {
        return next;
    }

    public void setNext(MyLinkedListNode nextValue) {
        next = nextValue;
    }
}
