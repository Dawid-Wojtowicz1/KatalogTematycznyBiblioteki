#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Book
{
    public:
    string title;
    string author;
    int id;
    string topics[3];
    // wskaznik na nastepna ksiazke
    Book* next;

    Book(string t, string a,string top1,string top2,string top3);

};

class BookList
{
public:
    Book* head;

    // konstruktor
    BookList();

    // dodaje ksiazke do listy
    void addBook(string,string,string,string,string);
    // wyswietla wszystkie ksiazki w liscie
    void printBooks();

    void writeToFile(string);

    void readFromFile(string);

    void findBookByTitle(string title);

    void findBookByAuthor(string author);

    void findBookByTopic(string topic);


};
