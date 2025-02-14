package strategyPattern.alienoVsGuerrieroGalattico;

public class MotoSubsonica implements MoveBehavior{

    @Override
    public void move() {
        System.out.println("Mi muovo con la moto subsonica\n");
    }
}
