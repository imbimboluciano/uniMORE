package decoratorPattern.pc;

public class Ram extends HardwareDecorator{
    Pc pc;
    int dim;

    public Ram(Pc pc,int dim){
        this.pc = pc;
        this.dim = dim;
    }

    @Override
    public String getDescription() {
        return pc.getDescription() + dim + "Ram";
    }

    @Override
    public double cost() {
        double rCost = dim * 10;
        return pc.cost() + rCost;
    }
}
