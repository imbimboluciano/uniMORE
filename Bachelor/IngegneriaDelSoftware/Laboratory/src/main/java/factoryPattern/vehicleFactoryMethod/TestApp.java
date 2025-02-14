package factoryPattern.vehicleFactoryMethod;

public class TestApp {

    public static void main(String[] args) {

        VehicleFactory euVehicleFactory = new EUVehicleFactory();
        System.out.println(euVehicleFactory.makeVehicle("Fiat").toString());

        Vehicle audi = euVehicleFactory.makeVehicle("Audi");
        System.out.println(audi.toString());

        VehicleFactory usaVehicleFactory = new USAVehicleFactory();
        System.out.println(usaVehicleFactory.makeVehicle("Ford").toString());

    }
}
