package strategyPattern.gameFight;

public class King extends Character{

    public King(FightBehavior fightBehavior) {
        setFightBehavior(fightBehavior);
    }

    @Override
    public void performFight() {
        fightBehavior.fight();
    }
}
