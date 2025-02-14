package factoryPattern.vehicleAbstractFactory;

public class TestApp {

    public static void main(String[] args) {

        VehicleFactory euVehichleFactory = new EUVehicleFactory();

        Vehicle Fiat = euVehichleFactory.makeVehicle("Fiat");
        Fiat.assemble();
        System.out.println(Fiat.toString());
    }
}
