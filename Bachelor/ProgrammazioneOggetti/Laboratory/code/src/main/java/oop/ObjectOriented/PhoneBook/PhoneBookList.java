package oop.ObjectOriented.PhoneBook;

import java.util.ArrayList;

public class PhoneBookList implements PhoneBook{

    public static final int MAX_PERSON = 256;
    final ArrayList<Person> phoneBook;

    public PhoneBookList() {
        phoneBook = new ArrayList<>();
    }

    @Override
    public void addPerson(Person p) {
        if(phoneBook.size() < MAX_PERSON){
            phoneBook.add(p);
            return;
        }
        throw new IllegalArgumentException("Phonebook is full");

    }

    @Override
    public void removePerson(Person p) {
        phoneBook.remove(p);
    }

    @Override
    public Person searchByLastname(String s) {
        for (Person p: phoneBook) {
                if (p.getLastname().equals(s)) {
                    return p;
                }

        }
        return null;
    }

    @Override
    public Person searchByName(String s) {
        for (Person p:
        phoneBook) {
                if (p.getName().equals(s)) {
                    return p;
                }
        }
        return null;
    }

    @Override
    public Person searchByNumber(String s) {
        for (Person p:
        phoneBook) {
                if (p.getPhone().equals(s)) {
                    return p;
                }
        }
        return null;
    }

    public void showPhoneBook(){
        for (Person p:
             phoneBook) {
            System.out.println(p.toString());
        }
    }


    public static void main(String[] args) {


        PhoneBookList phoneBookList = new PhoneBookList();

        phoneBookList.addPerson(new Person("Ciao","coglione","12345"));

        System.out.println(phoneBookList.searchByLastname("Ciao").toString());

        phoneBookList.showPhoneBook();


    }
}
