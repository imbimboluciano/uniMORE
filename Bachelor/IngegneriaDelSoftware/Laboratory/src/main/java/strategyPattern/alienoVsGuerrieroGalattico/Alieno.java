package strategyPattern.alienoVsGuerrieroGalattico;

public class Alieno extends Character{

    public Alieno() {
        setFightBehavior(new BlobVelenoso());
        setMoveBehavior(new Teletrasporto());
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
