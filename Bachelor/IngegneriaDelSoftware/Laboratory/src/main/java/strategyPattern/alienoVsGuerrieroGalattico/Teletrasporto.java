package strategyPattern.alienoVsGuerrieroGalattico;

public class Teletrasporto implements MoveBehavior{

    @Override
    public void move() {
        System.out.println("Mi teletrasporto");
    }
}
