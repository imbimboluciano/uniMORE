package observerPattern.wheaterStationPull;

public class Display1 implements Observer, DisplayElement {
    private float temperature;
    private float humidity;
    public Display1(Subject weatherData) {
        weatherData.registerObserver(this);
    }
    public void update(WheaterData wheaterData) {
        this.temperature = wheaterData.getTemperature();
        this.humidity = wheaterData.getHumidity();
        display();
    }
    public void display() {
        System.out.println("Current conditions: " + temperature
                + "F degrees and " + humidity + "% humidity");
    }
}
