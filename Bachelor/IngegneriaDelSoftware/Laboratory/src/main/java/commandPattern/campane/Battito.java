package commandPattern.campane;

public class Battito extends EffectDecorator{

    Campana campana;

    public Battito(Campana campana) {
        this.campana = campana;
    }

    @Override
    String makeSound() {
        return campana.makeSound() + "tic";
    }
}
