package factoryPattern.vehicleAbstractFactory;

public class FiatTipo extends Vehicle{

    public FiatTipo(VehicleComponentFactory factory) {
        vehicleComponentFactory = factory;
    }

    @Override
    public void assemble() {
        motore = vehicleComponentFactory.makeMotore();
        interni = vehicleComponentFactory.makeInterni();
        carrozzeria = vehicleComponentFactory.makeCarrozzeria();
    }
}
