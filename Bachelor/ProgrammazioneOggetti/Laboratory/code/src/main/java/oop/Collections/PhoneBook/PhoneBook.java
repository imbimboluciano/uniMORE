package oop.Collections.PhoneBook;

import oop.Utils.Student;

public interface PhoneBook {

    Student searchByLastname(String lastname);
    Student searchByNumber(String number);
    void addPerson(Student s);
    Student searchByName(String name);
    void deleteByNumber(String number);
}
