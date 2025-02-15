package oop.Collections.PhoneBook;


import oop.Utils.Student;
import org.junit.jupiter.api.BeforeEach;

class PhoneBookMapTest extends PhoneBookTestBase {
    @BeforeEach
    void setUp() {
        pb = new PhoneBookMap();
        pb.addPerson(new Student("Nicola", "Bicocchi", "34567"));
        pb.addPerson(new Student("Marco", "Rizzo", "45243"));
        pb.addPerson(new Student("Luisa", "Poppi", "24564"));
    }
}