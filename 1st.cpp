/* This is my 1st program in c++ which accepts the rollno and name of single studennt */
#include<iostream>
using namespace std;
class Student{
    int rollno;
    string name;
    public:
     void accept();
     void display();
}S;
void Student::accept() 
{
    cout<<"Enter the roll no: ";
    cin>>rollno;
    cout<<"Enter the name: ";
    cin>>name;
}
void Student::display()
{
    cout<<"\nName is :"<<name<<"\n"<<"Rollno of " <<name<<" is : "<<rollno;
}
int main()
{
    S.accept();
    S.display();
    return 0;
}