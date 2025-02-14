package decoratorPattern.pc;

public class Desktop extends Pc{

    public Desktop(){
        description = "Pc Desktop";
    }

    @Override
    public double cost() {
        return 300;
    }
}
