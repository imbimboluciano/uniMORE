package strategyPattern.gameFight;

public abstract class Character {

    FightBehavior fightBehavior;

    public abstract void performFight();

    public void setFightBehavior(FightBehavior fightBehavior) {
        this.fightBehavior = fightBehavior;
    }
}
