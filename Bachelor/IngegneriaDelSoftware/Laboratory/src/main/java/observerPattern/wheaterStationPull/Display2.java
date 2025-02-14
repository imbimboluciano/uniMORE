package observerPattern.wheaterStationPull;

public class Display2 implements Observer,DisplayElement{

    private float temperature;
    private float humidity;

    public Display2(Subject weatherData) {
        weatherData.registerObserver(this);
    }

    @Override
    public void display() {
        System.out.println("Current conditions: " + humidity
                + "% humidity and " + temperature + "F degrees");
    }

    @Override
    public void update(WheaterData wheaterData) {
        this.temperature = wheaterData.getTemperature();
        this.humidity = wheaterData.getHumidity();
        display();

    }
}
