package oop.ObjectOriented.BankAccount3;

public interface BankAccount {
    public abstract double addAnnualInterest();
    public abstract String getIBAN();
    public abstract double transfer(BankAccount b,double amount);
    public abstract String getCountry();
    public abstract double withdraw(double amount);
    public abstract void deposit(double amount);
}
