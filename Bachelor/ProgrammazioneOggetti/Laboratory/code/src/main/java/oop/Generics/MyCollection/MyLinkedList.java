package oop.Generics.MyCollection;

public class MyLinkedList<T> extends MyAbstractList<T> implements MyQueue<T>{

    MyLinkedListNode<T> head;

    public MyLinkedList() {
        super();
        head = null;
    }

    @Override
    public void add(T obj) {
        add(obj,size);
    }

    @Override
    public void remove(T obj) {
        for (int i = 0; i < size; i++) {
            MyLinkedListNode<T> node = getNodeByIndex(i);
            if (node.getValue().equals(obj)) {
                remove(i);
                return;
            }
        }
    }

    @Override
    public void remove(int index) {
        checkBoundaries(index, size - 1);
        if (index == 0) {
            head = head.getNext();
        } else {
            MyLinkedListNode<T> current = getNodeByIndex(index - 1);
            current.setNext(current.getNext().getNext());
        }
        size--;
    }

    @Override
    public T get(int index) {
        checkBoundaries(index,size - 1);
        return getNodeByIndex(index).getValue();
    }

    @Override
    public void add(T obj, int index) {
        checkBoundaries(index, size);
        if (index == 0) {
            head = new MyLinkedListNode<T>(obj, head);
        } else {
            MyLinkedListNode<T> current = getNodeByIndex(index - 1);
            current.setNext(new MyLinkedListNode<T>(obj, current.getNext()));
        }
        size++;
    }

    @Override
    public T poll() {
        return head.getValue();
    }

    @Override
    public T peek() {
        T tmp = head.getValue();
        remove(0);
        return tmp;

    }

    MyLinkedListNode<T> getNodeByIndex(int index){
        MyLinkedListNode<T> current = head;
        for (int i = 0; i < index; i++) {
            current = current.getNext();
        }
        return current;
    }

}
