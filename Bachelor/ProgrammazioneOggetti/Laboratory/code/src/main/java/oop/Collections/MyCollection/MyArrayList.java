package oop.Collections.MyCollection;

public class MyArrayList extends MyAbstractList {
    static final int INITIAL_SIZE = 16;
    Object[] elements;

    public MyArrayList() {
        super();
        elements = new Object[INITIAL_SIZE];
    }

    @Override
    public void add(Object o, int index) {
        checkBoundaries(index, size);
        add(o);

        if (elements.length - 1 - index >= 0) {
            System.arraycopy(elements, index, elements, index + 1, elements.length - 1 - index); //spostiamo gli elementi dell'array per fare spazio all'elemento da inserire
        }
        elements[index] = o;
        elements[size] = null;
    }

    @Override
    public void add(Object o) {
        if (size >= elements.length - 1) {
            enlarge();
        }
        elements[size++] = o;
    }

    void enlarge() {
        Object[] tmp = new Object[elements.length * 2];
        System.arraycopy(elements, 0, tmp, 0, elements.length);
        elements = tmp;
    }

    @Override
    public void remove(Object o) {
        for (int i = 0; i < size; i++) {
            if (elements[i].equals(o)) {
                remove(i);
                return;
            }
        }
    }

    @Override
    public void remove(int index) {
        checkBoundaries(index, size - 1);

        System.arraycopy(elements, index + 1, elements, index, size - index); //spostiamo gli elementi portando l'elemento da eliminare alla fine
        elements[--size] = null;
    }

    @Override
    public Object get(int index) {
        checkBoundaries(index, size - 1);
        return elements[index];
    }
}
