#include <bits/stdc++.h>
using namespace std;

class Library 
{
    vector <string> v;
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
            string n; 
            cout <<"Enter name of book which you want to add "; cin>>n;
            v.push_back(n);
            return "your book is added\n";   
        }

        string Remove_book()
        {
            string n;
            cout<<"Enter your book which you want to remove "; cin>>n;
            for (int i=0; i<v.size(); i++)
            {
                if (v[i] == n)
                { 
                    v.erase(v.begin() + i);  // دي طريق ع احذف حاجه ف مكن معين
                    return "your book is removed\n";
                }
            } 
            return "your book not founded\n";
        }

        string search_book()
        {
            string n;
            cout <<"Enter your book which you want to search "; cin>>n;
            for (const string &s : v)
            {
                if (s == n) return "the book which you ask is founded\n";
            }
            return "the book is not founded\n";
        }

        void Display_all_book()
        {
            cout <<"your books are\n";
            for (string s : v)
            cout <<s<<endl;
        }
};

int main()
{
    
    int number=0; 
    Library l1;
    while(number != 7)
    {
        l1.show_menu();
        cout <<"Enter number from 1 to 7 "; cin>>number; 
        
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
    }
}

