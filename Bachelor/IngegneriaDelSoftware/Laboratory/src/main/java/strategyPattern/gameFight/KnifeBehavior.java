package strategyPattern.gameFight;

public class KnifeBehavior implements FightBehavior{

    @Override
    public void fight() {
        System.out.println("I'm fighting with a knife!!");
    }
}
