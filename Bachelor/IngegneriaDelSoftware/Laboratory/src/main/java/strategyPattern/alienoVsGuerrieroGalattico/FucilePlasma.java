package strategyPattern.alienoVsGuerrieroGalattico;

public class FucilePlasma implements FightBehavior{

    @Override
    public void fight() {
        System.out.println("Combatto con il fucile al plasma");
    }
}
