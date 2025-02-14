package factoryPattern.vehicleAbstractFactory;

public class USAVehicleComponentFactory implements VehicleComponentFactory {

    @Override
    public Carrozzeria makeCarrozzeria() {
        return new FordCarrozzeria();
    }

    @Override
    public Motore makeMotore() {
        return new FordMotore();
    }

    @Override
    public Interni makeInterni() {
        return new FordInterni();
    }
}
