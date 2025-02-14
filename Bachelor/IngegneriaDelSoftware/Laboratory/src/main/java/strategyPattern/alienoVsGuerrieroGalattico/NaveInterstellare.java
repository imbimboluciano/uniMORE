package strategyPattern.alienoVsGuerrieroGalattico;

public class NaveInterstellare implements MoveBehavior{

    @Override
    public void move() {
        System.out.println("Mi muovo con la nave interstellare\n");
    }
}
