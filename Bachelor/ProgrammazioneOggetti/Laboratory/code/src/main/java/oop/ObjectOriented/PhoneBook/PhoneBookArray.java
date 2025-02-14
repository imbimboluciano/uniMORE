package oop.ObjectOriented.PhoneBook;

public class PhoneBookArray  implements PhoneBook{

    public static final int MAX_PERSON = 256;

    final Person[] phoneBook;

    public PhoneBookArray() {
        phoneBook = new Person[MAX_PERSON];
    }

    @Override
    public void addPerson(Person p) {
        for (int i = 0; i < MAX_PERSON; i++) {
            if(phoneBook[i] == null){
                phoneBook[i] = p;
                return;
            }
        }
        throw new IllegalArgumentException("Phonebook is full");
    }

    @Override
    public void removePerson(Person p) {
        for (int i = 0; i < MAX_PERSON; i++) {
            if(phoneBook[i] != null){
                if(phoneBook[i].equals(p)){
                    phoneBook[i] = null;
                    break;
                }
            }

        }

    }

    @Override
    public Person searchByLastname(String s) {
        for (int i = 0; i < MAX_PERSON; i++) {
            if(phoneBook[i] != null) {
                if (phoneBook[i].getLastname().equals(s)) {
                    return phoneBook[i];
                }
            }
        }
        return null;
    }

    @Override
    public Person searchByName(String s) {
        for (int i = 0; i < MAX_PERSON; i++) {
            if(phoneBook[i] != null) {
                if (phoneBook[i].getName().equals(s)) {
                    return phoneBook[i];
                }
            }
        }
        return null;
    }

    @Override
    public Person searchByNumber(String s) {
        for (int i = 0; i < MAX_PERSON; i++) {
            if(phoneBook[i] != null) {
                if (phoneBook[i].getPhone().equals(s)) {
                    return phoneBook[i];
                }
            }
        }
        return null;
    }


    public static void main(String[] args) {

        PhoneBookArray pb = new PhoneBookArray();

        pb.addPerson(new Person("Mario", "Rossi", "12345"));

        for (Person p:
                pb.phoneBook) {
            System.out.println(p.toString());
        }
        //System.out.println(pb.searchByLastname("Rossi").toString());

    }
}
