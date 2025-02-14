
package factoryPattern.simpleFactoryVSstaticFactory;

//simple factory is not a Factory Design Pattern

public class TestCreate {
	public static void main(String[] args){
         CreateA pizzeriaA = new CreateA();
         Pizza marghe = pizzeriaA.create("margherita");

         CreateB pizzeriaB = new CreateB();
         Pizza marghe1 = pizzeriaB.create("margherita");
         Pizza napoli = pizzeriaB.create("napoli");
         marghe1.stampa();
         napoli.stampa();
	}
}
