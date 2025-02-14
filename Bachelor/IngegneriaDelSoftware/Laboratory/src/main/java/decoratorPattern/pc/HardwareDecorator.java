package decoratorPattern.pc;

public abstract class HardwareDecorator extends Pc{
    protected Pc pc;

    public abstract String getDescription();
}
