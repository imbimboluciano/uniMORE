package decoratorPattern.pc;

public class Notebook extends Pc{

    public Notebook(){
        description = "Notebook";
    }

    @Override
    public double cost() {
        return 250;
    }
}
