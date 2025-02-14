package strategyPattern.alienoVsGuerrieroGalattico;

public class BlobVelenoso implements FightBehavior{

    @Override
    public void fight() {
        System.out.println("Lancio un blob velenoso");
    }
}
