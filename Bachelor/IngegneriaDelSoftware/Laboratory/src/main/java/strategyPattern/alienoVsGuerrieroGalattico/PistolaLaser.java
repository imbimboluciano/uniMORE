package strategyPattern.alienoVsGuerrieroGalattico;

public class PistolaLaser implements FightBehavior{

    @Override
    public void fight() {
        System.out.println("Combatto con una pistola laser");
    }
}
