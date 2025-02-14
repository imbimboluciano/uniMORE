package observerPattern.wheaterStationPush;

public class TestApp {

    public static void main(String[] args) {
        WheaterData weatherData = new WheaterData();
        Display1 currentDisplay = new Display1(weatherData);
        weatherData.setMeasurements(80, 65, 30.4f);
        weatherData.setMeasurements(82, 70, 29.2f);
        weatherData.setMeasurements(78, 90, 29.2f);
    }
}
