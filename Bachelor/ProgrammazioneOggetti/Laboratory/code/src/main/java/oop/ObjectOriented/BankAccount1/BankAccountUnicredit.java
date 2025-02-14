package oop.ObjectOriented.BankAccount1;

public class BankAccountUnicredit extends BankAccount{

    static final double FeeWithdraw = 0.01;
    static final double FeeDeposit = 0.01;
    static final double AnnualInterest = 0.02;

    public BankAccountUnicredit(String IBAN, double balance) {
        super(IBAN, balance);
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        balance -= amount * FeeDeposit;
    }

    @Override
    public double withdraw(double amount) {
        balance -= amount;
        balance -= amount * FeeWithdraw;
        return amount;
    }

    @Override
    public double addAnnualInterest() {
        double amountTrue = balance * AnnualInterest;
        balance += amountTrue;
        return amountTrue;
    }

    @Override
    public double transfer(BankAccount b, double amount) {
        double amountTrue = withdraw(amount);
        b.deposit(amountTrue);
        return amountTrue;
    }



    @Override
    public String toString() {
        return "BankAccountUnicredit{ " + "IBAN:" + IBAN + "\n" + "Balance:" + balance + "}";
    }
}
