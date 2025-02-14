package oop.Collections;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class SortAccount {

    public static class Account {
        double amount;
        double interestRate;
        LocalDate duePayment;

        public Account(double amount, double interestRate, LocalDate duePayment) {
            this.amount = amount;
            this.interestRate = interestRate;
            this.duePayment = duePayment;
        }

        public double getAmount() {
            return amount;
        }

        public double getInterestRate() {
            return interestRate;
        }

        public LocalDate getDuePayment() {
            return duePayment;
        }

    }


    public static void sortByAmount(List<Account> accounts){

        Collections.sort(accounts, new Comparator<Account>() {
            @Override
            public int compare(Account o1, Account o2) {
                if(o1.getAmount() > o2.getAmount()){
                    return 1;
                }else if(o1.getAmount() < o2.getAmount()) {
                    return -1;
                }

                return 0;
            }
        });

    }
    public static void sortByInterestRate(List<Account> accounts){

        Collections.sort(accounts, new Comparator<Account>() {
            @Override
            public int compare(Account o1, Account o2) {
                if(o1.getInterestRate() > o2.getInterestRate()){
                    return 1;
                }else if(o1.getInterestRate() < o2.getInterestRate()){
                    return -1;
                }

                return 0;
            }
        });

    }
    public static void sortByDuePayment(List<Account> accounts){

        Collections.sort(accounts, new Comparator<Account>() {
            @Override
            public int compare(Account o1, Account o2) {
                if(o1.getDuePayment().isAfter(o2.getDuePayment())){
                    return 1;
                }else if(o1.getDuePayment().isBefore(o2.getDuePayment())){
                    return -1;
                }
                return 0;
            }
        });

    }

}
