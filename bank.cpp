//THIS IS MY CODE TO NO OF CUSTOMER OF BANK ACC AND DETAILS
#include<iostream>
using namespace std;

int n; // Number of customers

class Bank {
    string depositorname;
    int balance = 0;

public:
    int accountnumber;

    void assign();
    void deposit();
    void withdraw();
    void display();
};

void Bank::assign() {
    cout << "Create bank account :)\nEnter the depositor name :";
    cin >> depositorname;
    cout << "Enter the account number: ";
    cin >> accountnumber;
    cout << "Enter the initial balance: ";
    cin >> balance;
}

void Bank::deposit() {
    int amount;
    cout << "Enter the amount to deposit: ";
    cin >> amount;
    if (amount > 0) {
        balance += amount;
        cout << "Deposited: " << amount << "\n";
    } else {
        cout << "Invalid deposit amount.\n";
    }
}

void Bank::withdraw() {
    int amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    if (amount > balance) {
        cout << "Not having sufficient balance.\n";
    } else if (amount <= 0) {
        cout << "Invalid withdrawal amount.\n";
    } else {
        balance -= amount;
        cout << "Withdrawn: " << amount << "\n";
    }
}

void Bank::display() {
    cout << "Name of depositor: " << depositorname << "\n";
    cout << "Account number: " << accountnumber << "\n";
    cout << "Current balance: " << balance << "\n";
}

int main() {
    Bank B[100];
    int choice, accno;

    while (1) {
        int f = 0;
        cout << "\nBank Menu :)\n"
             << "1. Assign\n"
             << "2. Deposit\n"
             << "3. Withdraw\n"
             << "4. Display All Accounts\n"
             << "5. EXIT\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number of customers: ";
                cin >> n;
                for (int i = 0; i < n; i++) {
                    cout << "\nCustomer " << i + 1 << ":\n";
                    B[i].assign();
                }
                break;

            case 2:
                cout << "\nEnter the account number: ";
                cin >> accno;
                for (int i = 0; i < n; i++) {
                    if (B[i].accountnumber == accno) {
                        B[i].deposit();
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    cout << "\nAccount not found.\n";
                }
                break;

            case 3:
                cout << "\nEnter the account number: ";
                cin >> accno;
                for (int i = 0; i < n; i++) {
                    if (B[i].accountnumber == accno) {
                        B[i].withdraw();
                        f = 1;
                        break;
                    }
                }
                if (f == 0) {
                    cout << "\nAccount not found.\n";
                }
                break;

            case 4:
                if (n == 0) {
                    cout << "\nNo accounts to display.\n";
                } else {
                    for (int i = 0; i < n; i++) {
                        cout << "\nAccount " << i + 1 << ":\n";
                        B[i].display();
                    }
                }
                break;

            case 5:
                cout << "Exiting program. Bye!!\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}
