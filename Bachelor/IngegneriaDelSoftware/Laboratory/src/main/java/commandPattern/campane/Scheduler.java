package commandPattern.campane;

public class Scheduler {
    Command command;

    public Scheduler() {
    }

    public void setCommand(Command command) {
        this.command = command;
    }

    public void suona(){
        command.execute();
    }
}
