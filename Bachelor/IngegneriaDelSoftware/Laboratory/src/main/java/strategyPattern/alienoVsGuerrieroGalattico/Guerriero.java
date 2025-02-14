package strategyPattern.alienoVsGuerrieroGalattico;

public class Guerriero extends Character{


    public Guerriero(FightBehavior fb,MoveBehavior mb) {
        setFightBehavior(fb);
        setMoveBehavior(mb);
    }

    @Override
    public void performMove() {
        moveBehavior.move();
    }

    @Override
    public void performFight() {
        fightBehavior.fight();
    }
}
