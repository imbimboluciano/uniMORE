package strategyPattern.alienoVsGuerrieroGalattico;

/* Si vuole realizzare un videogioco  sparatutto. Il giocatore puó scegliere di impersonare un guerriero galattico o un alieno multiforma.
 Il guerriero puó colpire con un fucile al plasma o con una pistola laser
 Il guerriero puó pilotare una nave interstellare o una moto subsonica
 L'alieno colpisce con un blob velenoso
 L'alieno si muove teletrasportandosi

  Simulare un comportamento in cui il guerriero usa la pistola e pilota la nave interstellare. L'alieno si teletrasporta. A questo punto il guerriero usa la moto
  e il fucile ed inizia un combattimento con l'alieno
  */


public class TestApp {
    public static void main(String[] args) {
            Character guerriero = new Guerriero(new PistolaLaser(),new NaveInterstellare());
            Character alieno = new Alieno();

            System.out.println("Guerriero:");
            guerriero.performFight();
            guerriero.performMove();
            System.out.println("Alieno:");
            alieno.performMove();

    }
}
