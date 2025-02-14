package oop.Generics.MyCollection;

public abstract class MyAbstractList<T> implements MyList<T>{

    int size;

    public MyAbstractList() {
        size = 0;
    }

    @Override
    public int size() {
        return size;
    }

    void checkBoundaries(int i,int j){
        if(i < 0 || i > j){
            throw new ArrayIndexOutOfBoundsException();
        }
    }

    @Override
    public boolean contains(T obj) {
        for (int i = 0; i < size; i++) {
            if(obj.equals(get(i))){
                return true;
            }
        }
        return false;
    }


    @Override
    public String toString() {
      StringBuilder sb = new StringBuilder();
      sb.append("{ ");
        for (int i = 0; i < size; i++) {
            sb.append(String.format("[%s] ",get(i)));
        }
        sb.append("}");

        return sb.toString();
    }
}
