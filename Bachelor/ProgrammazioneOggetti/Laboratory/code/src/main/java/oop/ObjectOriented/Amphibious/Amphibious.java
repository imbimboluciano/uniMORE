package oop.ObjectOriented.Amphibious;

public class Amphibious implements LandVehicle, WaterVehicle {

    public Amphibious() {
    }

    @Override
    public String run() {
        return "Amphibious running...";
    }

    @Override
    public String sail() {
        return "Amphibious sailing...";
    }
}
