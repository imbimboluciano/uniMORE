package factoryPattern.vehicleAbstractFactory;



public class USAVehicleFactory extends VehicleFactory {

    USAVehicleComponentFactory usaVehicleComponentFactory = new USAVehicleComponentFactory();

    @Override
    public Vehicle makeVehicle(String brand) {
        if(brand.equals("Ford")){
            return new FordFocus(usaVehicleComponentFactory);
        }else{
            return null;
        }

    }
}
