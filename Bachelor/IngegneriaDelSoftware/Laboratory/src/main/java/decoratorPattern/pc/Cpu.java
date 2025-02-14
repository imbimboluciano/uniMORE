package decoratorPattern.pc;

public class Cpu extends HardwareDecorator{
    Pc pc;

    public Cpu(Pc pc){
        this.pc = pc;
    }


    @Override
    public String getDescription() {
        return pc.getDescription() +  "Cpu";
    }

    @Override
    public double cost() {
        return pc.cost() + 100;
    }
}
