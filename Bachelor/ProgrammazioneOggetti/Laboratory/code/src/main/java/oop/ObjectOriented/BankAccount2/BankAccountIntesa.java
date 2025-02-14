package oop.ObjectOriented.BankAccount2;

public class BankAccountIntesa implements BankAccount{

    public String IBAN;
    public double balance;
    static final double AnnualInterest = 0.0;
    static final double FeeWithdraw = 0.0;
    static final double FeeDeposit = 0.0;

    public BankAccountIntesa(String IBAN, double balance) {
        this.IBAN = IBAN;
        this.balance = balance;
    }

    @Override
    public double addAnnualInterest() {
        return AnnualInterest;
    }

    @Override
    public String getIBAN() {
        return IBAN;
    }

    @Override
    public double transfer(BankAccount b, double amount) {
       if(!b.getCountry().equals(getCountry())){
           return 0.0;
       }
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
        double amountActual = Math.min(amount,balance);
        balance -= amountActual;
        balance -= amountActual * FeeWithdraw;
        return  amountActual;
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        balance -= balance * FeeDeposit;
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
    public String toString() {
        return "BankAccountIntesa{" +
                "IBAN='" + IBAN + '\'' +
                ", balance=" + balance +
                '}';
    }
}
