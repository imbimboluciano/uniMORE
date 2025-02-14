package factoryPattern.vehicleFactoryMethod;

public abstract class Vehicle {
    String carrozzeria;
    String motore;
    String interni;

    @Override
    public String toString() {
        return "Vehicle{" +
                "carrozzeria='" + carrozzeria + '\'' +
                ", motore='" + motore + '\'' +
                ", interni='" + interni + '\'' +
                '}';
    }
}
