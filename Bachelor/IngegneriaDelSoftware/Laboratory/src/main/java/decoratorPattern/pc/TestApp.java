package decoratorPattern.pc;

public class TestApp {
    public static void main(String[] args) {

        Pc pc1 = new Notebook();
        System.out.println("Pc notebook cost: " + pc1.cost());

        Pc pc2 = new Desktop();
        pc2 = new Hd(pc2,500);
        pc2= new Cpu(pc2);
        pc2 = new Ram(pc2,8);

        System.out.println("Pc desktop cost: " + pc2.cost());

    }
}
