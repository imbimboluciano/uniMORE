package observerPattern.wheaterStationPull;

public class TestApp {

    public static void main(String[] args) {
        WheaterData weatherData = new WheaterData();
        Display1 display1 = new Display1(weatherData);
        Display2 display2 = new Display2(weatherData);


        weatherData.setMeasurements(80, 65, 30.4f);
        weatherData.setMeasurements(82, 70, 29.2f);
    }
}
