package factoryPattern.vehicleFactoryMethod;

public class USAVehicleFactory extends VehicleFactory {

    @Override
    public Vehicle makeVehicle(String brand) {
        if(brand.equals("Ford")){
            return new FordFocus();
        }else{
            return null;
        }

    }
}
