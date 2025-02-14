package oop.ObjectOriented.BankAccount3;

public class BankAccountUnicredit extends AbstractBankAccount{

    static final double AnnualInterest = 0.02;
    static final double FeeWithdraw = 0.01;
    static final double FeeDeposit = 0.01;

    public BankAccountUnicredit(String IBAN, double balance) {
        super(IBAN, balance);
    }

    @Override
    public double addAnnualInterest() {
        double interest = balance * AnnualInterest;
        balance += interest;
        return interest;
    }

    @Override
    public double transfer(BankAccount b, double amount) {
        double amountActual = withdraw(amount);
        b.deposit(amountActual);
        return amountActual;
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
