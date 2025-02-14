package oop.Generics.Shop;

import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Queue;

public class Shop<T>{

    final Queue<T> items;

    public Shop() {
        this.items = new LinkedList<>();
    }

    public T sell(){
        return items.remove();
    }

    public void sell(Collection<? super T> c, int index){
        for (int i = 0; i < index; i++) {
            c.add(sell());
        }
    }

    public Collection getItems(){
        return items;
    }

    public void buy(T obj){
        items.add(obj);
    }

    public void buy(Collection<? extends T> c){
        items.addAll(c);
    }
}
