package factoryPattern.vehicleAbstractFactory;

public class FordFocus extends Vehicle{

    public FordFocus(VehicleComponentFactory factory) {
        vehicleComponentFactory = factory;
    }

    @Override
    public void assemble() {
        motore = vehicleComponentFactory.makeMotore();
        interni = vehicleComponentFactory.makeInterni();
        carrozzeria = vehicleComponentFactory.makeCarrozzeria();
    }
}
