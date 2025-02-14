package decoratorPattern.pizza;

public abstract class CondimentDecorator extends Pizza{
    Pizza pizza;
    public abstract String getDescription();
}
