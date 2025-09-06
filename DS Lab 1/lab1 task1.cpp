#include <iostream>
using namespace std;
//BankAccount
class BankAccount {
private:
    double balance;

public:
//constructor
BankAccount() {
    balance = 0.0;
}

//parameterized constructor
BankAccount(double inibal) {
    balance = inibal;
}

//Copy constructor
BankAccount(const BankAccount& other) {
    balance = other.balance;
}

//balance function for current
double getBalance() const {
    return balance;
}

//withdraw function
void withdraw(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        cout << "Amount not found" << endl;
    }    }
};

int main() {
    BankAccount account1;
    BankAccount account2(1000.0);
    BankAccount account3(account2);
    account3.withdraw(200.0);
    cout << "Balance account1 : " << account1.getBalance() << endl;

    cout << "Balance account2: " << account2.getBalance() << endl;

    cout << "Balance account3 after withdrawing: $" << account3.getBalance() << endl;

    cout << "Balance account2 : " << account2.getBalance() << endl;

    return 0;
}
