package factoryPattern.vehicleAbstractFactory;


public class EUVehicleFactory extends VehicleFactory {

    VehicleComponentFactory euVehicleComponentFactory = new EUVehicleComponentFactory();
    @Override
    public Vehicle makeVehicle(String brand) {
        if(brand.equals("Fiat")){
            return new FiatTipo(euVehicleComponentFactory);
        }else {
            return null;
        }

    }

}
