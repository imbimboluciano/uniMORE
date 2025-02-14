package oop.Generics.MyCollection;

public abstract class MyAbstractSet<T> implements MySet<T>{

    Object[] table;
    final static int INITIAL_SIZE = 8;
    int size = 0;

    public MyAbstractSet() {
        table = new Object[INITIAL_SIZE];
    }

    abstract Object[] toArray();

    double capacityRatio(){
        return  size / (double) table.length;
    }

    @Override
    public int size() {
        return size;
    }

    @Override
    public String toString() {
        Object[] tmp = toArray();
        StringBuilder sb = new StringBuilder();
        sb.append("{ ");
        for (int i = 0; i < size; i++) {
            sb.append(String.format("[%s] ",tmp[i]));
        }
        sb.append("}");

        return sb.toString();
    }

    void enlarge(){
        Object[] tmp = new Object[table.length * 2];
        System.arraycopy(table,0,tmp,0,table.length);
        table = tmp;
    }

    public String showBuckets(){
        StringBuilder sb = new StringBuilder();
        sb.append("{ ");
        for (int i = 0; i < size; i++) {
            if(table[i] == null){
                sb.append(String.format("bucket %d - > null ",i));
            }else{
                sb.append(String.format("bucket %d - > %s ",i,table[i]));
            }

        }
        sb.append("}");

        return sb.toString();
    }
}
