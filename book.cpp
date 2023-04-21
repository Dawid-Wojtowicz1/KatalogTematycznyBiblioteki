#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include "book.h"
using namespace std;


// Book
Book::Book(string t, string a,string top1,string top2,string top3)
{
    title = t;
    author = a;
    topics[0] = top1;
    topics[1] = top2;
    topics[2] = top3;
}

BookList::BookList()
{
    head = nullptr;
}

// BookList
void BookList::addBook(string t,string a,string top1,string top2,string top3)
{
    Book* newBook = new Book(t, a,top1,top2,top3);
    newBook->next = this->head;
    this->head = newBook;
}

void BookList::printBooks()
{
    Book* current = this->head;
    while(current != nullptr)
    {
        cout << current->title << " - "<<current->author
        <<" Topics["<<current->topics[0]<<", "<<current->topics[1]
        <<", "<<current->topics[2]<<"]"<<endl;
        current = current->next;
    }
    cout<<"Aby wrocic do menu wcisnij enter"<<endl;
    getchar();
}

void BookList::writeToFile(string filename)
{
    ofstream file(filename);
    if(file.is_open())
    {
        Book* current = this->head;
        while(current != nullptr)
        {
            file << current->title<<","<<current->author<<","<<current->topics[0]<<","<<current->topics[1]<<","<<current->topics[2]<<endl;
            current = current->next;
        }
        file.close();
    } else
    {
        cout << "Error opening file "<< filename << endl;
    }
}

void BookList::readFromFile(string filename)
{
    ifstream file(filename);
    if(file.is_open())
    {
        string line;
        while(getline(file,line))
        {
            stringstream ss(line);
            string title, author, top1,top2,top3;
            getline(ss, title, ',');
            getline(ss, author, ',');
            getline(ss, top1, ',');
            getline(ss, top2, ',');
            getline(ss, top3, ',');
            addBook(title,author,top1,top2,top3);
        }
        file.close();
    } else
    {
        cout<<"Error opening file " << filename << endl;
    }
}

void BookList::findBookByTitle(string title)
{
    system("CLS");
    Book* current = this->head;
    bool found = false;
    while(current != nullptr)
    {
        if(current->title == title)
        {
            found = true;
            cout<<"Znaleziona ksiazka: " << endl;
            cout<<"Tytul: "<<current->title<<endl;
            cout<<"Autor: "<<current->author<<endl;
            cout<<"Tematy: "<<current->topics[0]<<", "<<current->topics[1]<<", "<<current->topics[2]<<endl;
            break;
        }
        current = current->next;
    }
    if(!found){
        cout<<"Nie znalezion ksiazki z tytulem '"<<title<<"'."<<endl;
    }
    getchar();
}

void BookList::findBookByAuthor(string author)
{
    system("CLS");
    Book* current = this->head;
    bool found = false;
    while(current != nullptr)
    {
        if(current->author == author)
        {
            found = true;
            cout<<"Znaleziona ksiazka: " << endl;
            cout<<"Tytul: "<<current->title<<endl;
            cout<<"Autor: "<<current->author<<endl;
            cout<<"Tematy: "<<current->topics[0]<<", "<<current->topics[1]<<", "<<current->topics[2]<<endl<<endl;

        }
        current = current->next;
    }
    if(!found){
        cout<<"Nie znalezion ksiazki autora: "<<author<<"."<<endl;
    }
    getchar();
}

void BookList::findBookByTopic(string topic)
{
    system("CLS");
    Book* current = this->head;
    bool found = false;
    while(current != nullptr)
    {
        if(current->topics[0]==topic ||
           current->topics[1]== topic ||
           current->topics[3]==topic)
        {
            found = true;
            cout<<"Znaleziona ksiazka: " << endl;
            cout<<"Tytul: "<<current->title<<endl;
            cout<<"Autor: "<<current->author<<endl;
            cout<<"Tematy: "<<current->topics[0]<<", "<<current->topics[1]<<", "<<current->topics[2]<<endl<<endl;
        }
        current = current->next;
    }
    if(!found){
        cout<<"Nie znalezion ksiazek o temacie: "<<topic<<"."<<endl;
    }
    getchar();
}
