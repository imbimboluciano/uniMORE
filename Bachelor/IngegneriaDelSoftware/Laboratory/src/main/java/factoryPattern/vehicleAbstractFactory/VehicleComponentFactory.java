package factoryPattern.vehicleAbstractFactory;

public interface VehicleComponentFactory {

     Carrozzeria makeCarrozzeria();
     Motore makeMotore();
     Interni makeInterni();
}
