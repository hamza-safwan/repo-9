#include <iostream>
using namespace std;

class ATM {
private:
    double balance;

public:
    // Constructor to initialize balance
    ATM(double initial_balance) {
        balance = initial_balance;
    }

    // Function to check balance
    void checkBalance() {
        cout << "Your current balance is: $" << balance << endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. Your new balance is: $" << balance << endl;
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal failed." << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. Your new balance is: $" << balance << endl;
        }
    }
};

int main() {
    // Create an instance of the ATM with an initial balance of $1000
    ATM myATM(1000.0);

    // Main menu
    cout << "Welcome to the ATM system" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;

    int choice;
    double amount;

    // Main loop
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myATM.checkBalance();
                break;
            case 2:
                cout << "Enter the amount to deposit: $";
                cin >> amount;
                myATM.deposit(amount);
                break;
            case 3:
                cout << "Enter the amount to withdraw: $";
                cin >> amount;
                myATM.withdraw(amount);
                break;
            case 4:
                cout << "Exiting ATM system. Goodbye!";
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
