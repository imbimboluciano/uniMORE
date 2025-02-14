package commandPattern.campane;

public class Vento extends EffectDecorator{

    Campana campana;
    public Vento(Campana campana) {
        this.campana = campana;
    }

    @Override
    String makeSound() {
        return campana.makeSound() + "ffff";
    }
}
