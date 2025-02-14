package oop.Collections.PhoneBook;

import oop.Utils.Student;

import java.util.ArrayList;
import java.util.ListIterator;
import java.util.Objects;

public class PhoneBookList implements PhoneBook{

    ArrayList<Student> phoneBook;

    public PhoneBookList() {
        this.phoneBook = new ArrayList<>();
    }

    @Override
    public Student searchByLastname(String lastname) {
        for (Student s : phoneBook) {
            if(s.getLastname().equals(lastname)){
                return s;
            }
        }
        return null;
    }

    @Override
    public Student searchByNumber(String number) {
        for (Student s : phoneBook) {
            if(s.getPhone().equals(number)){
                return s;
            }
        }
        return null;
    }

    @Override
    public void addPerson(Student s) {
        phoneBook.add(s);
    }

    @Override
    public Student searchByName(String name) {
        for (Student s : phoneBook) {
            if(s.getName().equals(name)){
                return s;
            }
        }
        return null;
    }

    @Override
    public void deleteByNumber(String number) {

        for(ListIterator<Student> l = phoneBook.listIterator();l.hasNext();){
            if(l.next().getPhone().equals(number)){
                l.remove();
            }
        }
    }
}
