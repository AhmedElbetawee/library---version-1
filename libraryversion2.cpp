#include <bits/stdc++.h>
using namespace std;

class Book
{
    string name_book;
    int id;
    string author;
    bool borrowed = false; // available   

    public:
        Book(string n, int i, string auth)
        {
            name_book = n;
            id = i;
            author = auth;
        }

        string get_name()
        {
            return name_book;
        }
        
        int get_id()
        {
            return id;
        }
        
        string get_author()
        {
            return author;
        }
        
        bool isBorrowed()
        {
            return borrowed;
        }

        void borrow()
        {
            borrowed = true;
        }
        void return_book()
        {
            borrowed = false;
        }

};

class Library 
{
    // vector <string> v;
    vector <Book> books;
    public:
        void show_menu() 
        {
            cout <<"1- Add book\n";
            cout <<"2- Remove book\n";
            cout <<"3- search book\n";
            cout <<"4- Display book\n";
            cout <<"5- Borrow book\n";
            cout <<"6- return book\n";
            cout <<"7- Exit\n";
        }
        string add_book()
        {
            string name_book,author;
            int id;
            cout <<"Enter name of book without space "; cin>>name_book;
            cout <<"Enter id of book "; cin>>id;
            cout <<"Enter name of auhtor book "; cin>>author;;
            Book b(name_book, id, author);
            books.push_back(b);
            return "your book is added\n\n";
        }

        string Remove_book()
        {
            int id;
            cout <<"Enter id of book "; cin>>id;
            for (int i=0; i<books.size(); i++)
            {
                if (books[i].get_id() == id)
                {
                    books.erase(books.begin() + i);
                    return "your book is removed\n\n";
                }
            }
            return "your is not founded\n\n";
        }

        string search_book()
        {
            int id; 
            cout <<"Enter id of book "; cin>>id;
            for (int i=0; i<books.size(); i++)
            {
                if (books[i].get_id() == id)
                {
                    cout<<"the name of book is "<<books[i].get_name()<<endl;
                    cout<<"the id of book is "<<books[i].get_id()<<endl;
                    cout<<"the author of book is "<<books[i].get_author()<<endl;
                    return "the book is founded\n\n"; 
                }
            }
            return "the book is not founded\n\n";
        }

        void Display_all_book()
        {
            for (int i=0; i<books.size(); i++)
            {
                cout<<"the name of book is "<<books[i].get_name()<<endl;
                cout<<"the id of book is "<<books[i].get_id()<<endl;
                cout<<"the author of book is "<<books[i].get_author()<<endl;

            }
            cout <<"\n\n";
        }

        string Borrow_book()
        {
            int id;
            cout <<"Enter id of book "; cin>>id;
            for (int i=0; i<books.size(); i++)
            {
                if (books[i].get_id() == id)
                {
                    if (books[i].isBorrowed())
                    {
                        return "Fail, the book is borrowedsuccessfully\n\n";
                    }
                    else 
                    {    
                        books[i].borrow();
                        return "success, the book is available\n\n";
                    }
                }
            }
            return "the book is not founded\n\n";   
        }

        string Return_book()
        {
            int id;
            cout <<"Enter id of book "; cin>>id;
            for (int i=0; i<books.size(); i++)
            {
                if (books[i].get_id() == id)
                {
                    if (!books[i].isBorrowed())
                    {
                        return "the book is available\n\n";
                    }
                    else 
                    {    
                        books[i].return_book();
                        return "the book return successfully\n\n";
                    }
                }
            }
            return "the book is not founded\n\n"; 
        }

};

int main()
{
    cout <<"This is library system\n";
    cout <<"-------------------------------------\n\n";
    Library l1; 
    int number = 0;
    while(number != 7)
    {
        l1.show_menu();
        cout <<"Enter number from 1 to 7 : "; cin>>number;
        
        if (number == 1)
        {
            cout <<l1.add_book();
        }

        else if (number == 2)
        {
            cout <<l1.Remove_book();
        }

        else if (number == 3)
        {
            cout <<l1.search_book();
        }

        else if (number == 4)
        {
            l1.Display_all_book();
        }

        else if (number == 5)
        {
            cout <<l1.Borrow_book();
        }

        else if (number == 6)
        {
            cout <<l1.Return_book();
        }
    }
}