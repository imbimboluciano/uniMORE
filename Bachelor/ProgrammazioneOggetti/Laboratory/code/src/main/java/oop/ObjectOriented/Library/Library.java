package oop.ObjectOriented.Library;

public class Library {

    Rent[] rents;

    public Library(Rent[] rents) {
        this.rents = rents;
    }

    public Rent getLongestRent(){
        Rent tmp = rents[0];
        for(Rent i:
             rents) {
                if((tmp.getEnd().getTime() - tmp.getBegin().getTime()) < (i.getEnd().getTime() - i.getBegin().getTime())){
                    tmp=i;
                }
        }
        return tmp;
    }
}
