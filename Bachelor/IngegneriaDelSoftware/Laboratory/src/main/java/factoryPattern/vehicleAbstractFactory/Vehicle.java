package factoryPattern.vehicleAbstractFactory;

public abstract class Vehicle {

    VehicleComponentFactory vehicleComponentFactory;
    Motore motore;

    Interni interni;

    Carrozzeria carrozzeria;

    public abstract void assemble();

    @Override
    public String toString() {
        return "Vehicle{" +
                "motore=" + motore.getDescrizione() +
                ", interni=" + interni.getDescrizione() +
                ", carrozzeria=" + carrozzeria.getDescrizione() +
                '}';
    }
}
