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
    cout<<"Enter the depositer name : ";
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
    cout<<"\nName of depositor:"<<depositorname<<"\n";
    cout<<"Account number:"<<accountnumber<<"\n";
    cout<<"balance:"<<balance<<"\n";
}    

int main()
{
    B.assign();
    B.deposit();
    B.withdraw();
    B.display();
    return 0;
}