package decoratorPattern.pc;

public abstract class Pc {

    String description = "Unknown PC";

    public String getDescription() {
        return description;
    }

    public abstract double cost();
}
