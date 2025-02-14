package factoryPattern.vehicleAbstractFactory;

public class EUVehicleComponentFactory implements VehicleComponentFactory {
    @Override
    public Carrozzeria makeCarrozzeria() {
        return new FiatCarrozzeria();
    }

    @Override
    public Motore makeMotore() {
        return new FiatMotore();
    }

    @Override
    public Interni makeInterni() {
        return new FiatInterni();
    }
}
