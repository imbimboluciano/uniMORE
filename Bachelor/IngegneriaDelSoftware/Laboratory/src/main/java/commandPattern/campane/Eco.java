package commandPattern.campane;

public class Eco extends EffectDecorator{

    Campana campana;
    public Eco(Campana campana) {
        this.campana = campana;
    }

    @Override
    String makeSound() {
        return campana.makeSound() + campana.makeSound();
    }
}
