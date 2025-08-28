/*this code is for book store*/
#include <iostream>
#include <string>
#include<iomanip>
using namespace std;

class Book
{
public:
    int *price, *copy;
    string *Author_name, *book_name;

    // Parameterized constructor
    Book(int p, int c, string A, string B)
    {
        price = new int(p);
        copy = new int(c);
        Author_name = new string(A);
        book_name = new string(B);
    }

    // Destructor to free memory
    ~Book()
    {
        delete price;
        delete copy;
        delete Author_name;
        delete book_name;
    }

    // Display book details
    void display()
    {
        cout <<left << setw(20) << *book_name << setw(20) <<  *Author_name << setw(10) << *price  << *copy << endl;
    }

    // Search and bill
    void search_bill()
    {
        int ch, Cpy;
        cout << "\nBook Found!";
        cout << "\nDo you want to buy it? Type 1 for Yes: ";
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter number of copies you want = ";
            cin >> Cpy;
            if (Cpy <= *copy)
            {
                cout << "Total bill = " << (*price) * Cpy << endl;
                *copy -= Cpy; // reduce available copies
            }
            else
            {
                cout << "This many copies are not available!" << endl;
            }
        }
    }
};

int main()
{
    int price, copies;
    string author, title;
    string search_author, search_title;
    int choice, found = 0, num;

    cout << "Enter number of books: ";
    cin >> num;

    // Dynamic array of pointers to Book
    Book **books = new Book *[num];

    while (true)
    {
        cout << "\n1. Accept\n2. Display\n3. Search\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Accept
            for (int i = 0; i < num; i++)
            {
                cout << "Enter Book name, Author name, Price, Copies: ";
                cin >> title >> author >> price >> copies;
                books[i] = new Book(price, copies, author, title);
            }
            break;

        case 2: // Display
           cout <<"\n"<<left<<setw(20)<<"Book" << setw(20) <<"Author" << setw(10) << "Price" << setw(10) <<"Copies"<<endl;
           cout << "--------------------------------------------------------"<<endl;
            for (int i = 0; i < num; i++)
            {
                if (books[i] != nullptr)
                    books[i]->display();
            }
            break;

        case 3: // Search
            cout << "Enter Book name and Author name : ";
            cin >> search_title >> search_author;
            found = 0;
            for (int i = 0; i < num; i++)
            {
                if (books[i] != nullptr &&
                    search_author == *books[i]->Author_name &&
                    search_title == *books[i]->book_name)
                {
                    books[i]->search_bill();
                    found = 1;
                    break;
                }
            }
            if (found == 0)
            {
                cout << "Not found!" << endl;
            }
            break;

        case 4: // Exit
            for (int i = 0; i < num; i++)
            {
                delete books[i];
            }
            delete[] books;
            return 0;

        default:
            cout << "Invalid choice!" << endl;
        }
    }
}
// design a c++ class complex with datamenber for real and imaginary partto ....Write aprogram yto perform add 
//of two complex no  using operator overloading member function or frnd functiomn 