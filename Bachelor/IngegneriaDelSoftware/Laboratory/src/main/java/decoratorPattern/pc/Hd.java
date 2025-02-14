package decoratorPattern.pc;

public class Hd extends HardwareDecorator{

    Pc pc;
    int dim;
    public Hd(Pc pc,int dim){
        this.pc = pc;
        this.dim = dim;
    }

    @Override
    public String getDescription() {
        return pc.getDescription() + "Hard Disk";
    }

    @Override
    public double cost() {
        double hcost = dim * 0.1;
        return (pc.cost() + hcost);
    }
}
