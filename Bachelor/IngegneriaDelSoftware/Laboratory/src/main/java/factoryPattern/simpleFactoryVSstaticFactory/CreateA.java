package factoryPattern.simpleFactoryVSstaticFactory;


public class CreateA {
	public Pizza create(String tipo) { // se static non possiamo fare l'override ma abbiamo il vantaggio che non c'è bisogno di istanziare l'oggetto createA nel main
		Pizza pizza = null;
		if (tipo.equals("margherita")){
			pizza = new Margherita();
		}

		return pizza;
	}
public CreateA() {
	
}
}
