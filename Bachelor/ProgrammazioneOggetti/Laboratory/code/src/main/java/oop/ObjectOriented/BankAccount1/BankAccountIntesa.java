package oop.ObjectOriented.BankAccount1;

public class BankAccountIntesa extends BankAccount{

    static final double FeeDeposit = 0.0;
    static final double FeeWithdraw = 0.0;
    static final double AnnualInterest = 0.0;


    public BankAccountIntesa(String IBAN, double balance) {
        super(IBAN, balance);
    }

    @Override
    public void deposit(double amount) {
        balance += amount;
        balance -= amount * FeeDeposit;
    }

    @Override
    public double withdraw(double amount) {
        double trueAmount = Math.min(balance,amount);
        balance -= trueAmount;
        balance -= trueAmount * FeeWithdraw;
        return  trueAmount;

    }

    @Override
    public double addAnnualInterest() {
        double interest = balance * AnnualInterest;
        balance += interest;
        return interest;
    }

    @Override
    public double transfer(BankAccount b, double amount) {
        if(!b.getCountry().equals(getCountry())){
            return 0.0;
        }
        double trueAmount = withdraw(amount);
        b.deposit(trueAmount);
        return trueAmount;
    }

    @Override
    public String toString() {
        return "BankAccountIntesa{ " + "IBAN:" + IBAN + "\n" + "Balance:" + balance + "}";
    }
}
