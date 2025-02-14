package commandPattern.campane;

public class CampanaCommand implements Command {

    Campana campana;

    public CampanaCommand(Campana campana) {
        this.campana = campana;
    }

    @Override
    public void execute() {
        System.out.println(campana.makeSound());
    }
}
