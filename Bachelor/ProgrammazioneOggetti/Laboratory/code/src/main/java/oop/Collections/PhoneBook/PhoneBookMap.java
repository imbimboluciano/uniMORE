package oop.Collections.PhoneBook;

import oop.Utils.Student;

import java.util.HashMap;
import java.util.ListIterator;

public class PhoneBookMap implements PhoneBook{

    HashMap<String,Student> phoneBook;

    public PhoneBookMap() {
        this.phoneBook = new HashMap<>();
    }

    @Override
    public Student searchByLastname(String lastname) {
        for (Student s : phoneBook.values()) {
            if(s.getLastname().equals(lastname)){
                return s;
            }
        }
        return null;
    }

    @Override
    public Student searchByNumber(String number) {
        if(phoneBook.containsKey(number)){
            return phoneBook.get(number);
        }
        return null;
    }

    @Override
    public void addPerson(Student s) {
        phoneBook.put(s.getPhone(),s);
    }

    @Override
    public Student searchByName(String name) {
        for (Student s : phoneBook.values()) {
            if(s.getName().equals(name)){
                return s;
            }
        }
        return null;
    }

    @Override
    public void deleteByNumber(String number) {
        if(phoneBook.containsKey(number)){
            phoneBook.remove(number);
        }
    }
}
