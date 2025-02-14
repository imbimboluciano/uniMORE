package strategyPattern.alienoVsGuerrieroGalattico;

public abstract class Character {

    FightBehavior fightBehavior;
    MoveBehavior moveBehavior;

    public void setFightBehavior(FightBehavior fightBehavior) {
        this.fightBehavior = fightBehavior;
    }

    public void setMoveBehavior(MoveBehavior moveBehavior) {
        this.moveBehavior = moveBehavior;
    }

    public abstract void performMove();
    public abstract void performFight();





}
