package strategyPattern.gameFight;

public class TestApp {

    public static void main(String[] args) {
        Character king = new King(new KnifeBehavior());

        king.performFight();
        king.setFightBehavior(new AxeBehavior());
        king.performFight();
    }
}
