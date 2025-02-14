package decoratorPattern.pizza;

public class TestApp {
    public static void main(String args[]) {
        Pizza pizza = new ItalianPizza();
        System.out.println(pizza.getDescription()
                + " euro: " +pizza.cost());
        Pizza pizza2 = new ItalianPizza();
        pizza2 = new Mozzarella(pizza2);
        pizza2 = new Mozzarella(pizza2);
        pizza2 = new Tomato(pizza2);
        System.out.println(pizza2.getDescription()
                + " euro: " + pizza2.cost());
    }
}
