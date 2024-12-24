#include <iostream>
#include <memory>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {}
    virtual ~Account() {}

    virtual void calculateInterest() = 0;
    void displayBalance() const {
        cout << "Final Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
    double rate;
    int time;

public:
    SavingsAccount(double initialBalance, double interestRate, int timeYears)
        : Account(initialBalance), rate(interestRate / 100), time(timeYears) {}

    void calculateInterest() override {
        double interest = balance * rate * time;
        balance += interest;
        cout << "Savings Account Interest: " << interest << endl;
    }
};

class CurrentAccount : public Account {
    double maintenanceFee;

public:
    CurrentAccount(double initialBalance, double monthlyFee)
        : Account(initialBalance), maintenanceFee(monthlyFee) {}

    void calculateInterest() override {
        double totalFee = maintenanceFee * 12; // Assuming annual fee deduction
        balance -= totalFee;
        cout << "Current Account Maintenance Fee Deducted: " << totalFee << endl;
    }
};

int main() {
    int accountType;
    cout << "Enter Account Type (1 for Savings, 2 for Current): ";
    cin >> accountType;

    double balance;
    cout << "Enter Account Balance: ";
    cin >> balance;

    if (accountType == 1) {
        double rate;
        int time;
        cout << "Enter Interest Rate (in %): ";
        cin >> rate;
        cout << "Enter Time (in years): ";
        cin >> time;

        unique_ptr<Account> account = make_unique<SavingsAccount>(balance, rate, time);
        account->calculateInterest();
        account->displayBalance();

    } else if (accountType == 2) {
        double maintenanceFee;
        cout << "Enter Monthly Maintenance Fee: ";
        cin >> maintenanceFee;

        unique_ptr<Account> account = make_unique<CurrentAccount>(balance, maintenanceFee);
        account->calculateInterest();
        account->displayBalance();

    } else {
        cout << "Invalid account type!" << endl;
    }

    return 0;
}