package oop.ObjectOriented.PhoneBook;

public interface PhoneBook {


    void addPerson(Person p);
    void removePerson(Person p);
    Person searchByLastname(String s);

    Person searchByName(String s);

    Person searchByNumber(String s);
}
