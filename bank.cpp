/* This is my 2nd program releted to bank detail */
#include<iostream>
using namespace std;
class Bank{
    string depositorname;
    int accountnumber,balance;
    public:
     void assign();
     void deposit();
     void withdraw();
     void display();
    }B;
void Bank::assign() 
{
    cout<<"Create bank account:)\nEnter the depositer name : ";
    cin>>depositorname;
    cout<<"Enter the account no: ";
    cin>>accountnumber;
    cout<<"Enter the initial balance:";
    cin>>balance;
}
void Bank::deposit()
{
    int amount;
    cout<<"Enter the amount to deposite:";
    cin>>amount;
    balance+=amount;
    cout<<"Deposited:"<<amount<<"\n";
}
void Bank::withdraw()
{
    int amount;
    cout<<"Enter the amount to withdraw:";
    cin>>amount;
    if(amount>balance){
        cout<<"NOT having sufficient balance";
    }else{
        balance-=amount;
        cout<<"Withdrawn:"<<amount<<"\n";
    }
}
void Bank:: display()
{
    cout<<"Name of depositor:"<<depositorname<<"\n";
    cout<<"Account number:"<<accountnumber<<"\n";
    cout<<"Current balance:"<<balance<<"\n";
}    

int main()
{
 Bank B;
 int choice;   
    B.assign();
    do{ 
        cout<<"\nBank menu:)"<< "\n1. Deposit"<< "\n2. Withdraw"<<"\n3. Display"<< "\n4. Exit"<< "\nEnter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            B.deposit();
            break;
            case 2:
            B.withdraw();
            break;
            case 3:
            B.display();
            break;
            case 4:
            cout<<"EXITING THE PROGRAM !!\n";
            break;
            default:
            cout<<"invalide choice\n";
        }
    }while(choice!=4);
    return 0;
}