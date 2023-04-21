#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "book.h"

using namespace std;


BookList books;
int stop = 0;
void showMenu();
void wyburMenu();
void showMenuInFindBook();
void choiceMenuInFindBook();


int main()
{

    // utworzenie listy ksiazek



    books.readFromFile("bookList.txt");
    while(stop == 0)
    {
        showMenu();
        wyburMenu();
    }
    books.writeToFile("booklist.txt");








    return 0;

}





void showMenu()
{
    system("CLS");
    cout<<"----- Katalog tematyczny biblioteki -----"<<endl<<endl;
    cout<<"Aby wybrac opcje wwybierz odpowiedni numer"<<endl;
    cout<<"1. Dodaj ksiazke."<<endl;
    cout<<"2. Wyswietl wszystkie ksiazki."<<endl;
    cout<<"3. Szukaj ksiazke."<<endl;
    cout<<"4. Zakoncz program."<<endl;

}

void wyburMenu()
{
    int wybor;
    cin>>wybor;
    cin.ignore(5,'\n');

    switch(wybor)
    {
    case 1:
        {
            system("CLS");
            string title,author,top1,top2,top3;
            cout<<"Podaj tytul ksiazki:"<<endl; getline(cin,title);
            cout<<"Podaj autora:"<<endl; getline(cin,author);
            cout<<"Podaj pierszy temat ksiazki: "<<endl; getline(cin,top1);
            cout<<"Podaj drugi temat: "<<endl; getline(cin,top2);
            cout<<"Podaj trzeci temat: "<<endl; getline(cin,top3);
            books.addBook(title,author,top1,top2,top3);
            break;
        }
    case 2:
        {
            system("CLS");
            cout<<"All books in catalog:"<<endl;
            books.printBooks();
            break;
        }
    case 3:
        showMenuInFindBook();
        choiceMenuInFindBook();
        break;
    case 4:
        stop = 1;
        break;
    }
}

void showMenuInFindBook()
{
    system("CLS");
    cout<<"Znajdz ksziazke przez:"<<endl;
    cout<<"1. tytul"<<endl;
    cout<<"2. autora"<<endl;
    cout<<"3. temat"<<endl;
    cout<<"Nacisnij dowolny klawisz aby powrucic"<<endl;
}

void choiceMenuInFindBook()
{
    int choice;
    cin>>choice;
    cin.ignore(5,'\n');
    switch(choice)
    {
        case 1:
            {
                system("CLS");
                cout<<"Podaj tytul szukanej ksiazki: "<<endl;
                string t;
                getline(cin,t);
                books.findBookByTitle(t);
            }
            break;
        case 2:
            {
                system("CLS");
                cout<<"Podaj autora szukanej ksiazki: "<<endl;
                string a;
                getline(cin,a);
                books.findBookByAuthor(a);
            }
            break;
        case 3:
            {
                system("CLS");
                cout<<"Podaj temat szukanej ksiazki: "<<endl;
                string t;
                getline(cin,t);
                books.findBookByTopic(t);
            }
            break;
        default:
            break;
    }
}
