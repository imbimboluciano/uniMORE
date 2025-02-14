package strategyPattern.gameFight;

public class AxeBehavior implements FightBehavior{


    @Override
    public void fight() {
        System.out.println("I'm fighting with an axe!!");
    }
}
