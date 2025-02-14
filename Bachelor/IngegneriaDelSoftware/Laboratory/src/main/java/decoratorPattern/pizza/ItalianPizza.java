package decoratorPattern.pizza;

public class ItalianPizza extends Pizza{

    public ItalianPizza() {
        description = "Italian base";
    }

    public double cost() {
        return 4.50;
    }
}
