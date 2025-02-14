package factoryPattern.vehicleFactoryMethod;

public class EUVehicleFactory extends VehicleFactory {

    @Override
    public Vehicle makeVehicle(String brand) {
        if(brand.equals("Fiat")){
            return new FiatTipo();
        }else if(brand.equals("Audi")){
            return new AudiTT();
        }else {
            return null;
        }

    }

}
