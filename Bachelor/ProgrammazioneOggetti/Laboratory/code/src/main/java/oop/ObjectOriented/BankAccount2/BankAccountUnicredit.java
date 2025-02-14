package oop.ObjectOriented.BankAccount2;

public class BankAccountUnicredit implements BankAccount{

    public String IBAN;
    public double balance;
    static final double AnnualInterest = 0.02;
    static final double FeeWithdraw = 0.01;
    static final double FeeDeposit = 0.01;

    public BankAccountUnicredit(String IBAN, double balance) {
        this.IBAN = IBAN;
        this.balance = balance;
    }

    public void setIBAN(String IBAN) {
        this.IBAN = IBAN;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    @Override
    public double addAnnualInterest() {
        double interest = balance * AnnualInterest;
        balance += interest;
        return interest;
    }

    @Override
    public String getIBAN() {
        return IBAN;
    }

    @Override
    public double transfer(BankAccount b, double amount) {
        double amountActual = withdraw(amount);
        b.deposit(amountActual);
        return amountActual;
    }

    @Override
    public String getCountry() {
        return IBAN.substring(0,2);
    }

    @Override
    public double withdraw(double amount) {
        balance -= amount;
        balance -= amount * FeeWithdraw;
        return amount;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        balance -= balance * FeeDeposit;
    }

    @Override
    public String toString() {
        return "BankAccountUnicredit{" +
                "IBAN='" + IBAN + '\'' +
                ", balance=" + balance +
                '}';
    }
}
