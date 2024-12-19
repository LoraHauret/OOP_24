#pragma once
#include <iostream>
#include "Figure.h"
//#include "Command.h"
//#include "Line.h"
//#include "CubicBezier.h"x
//#include "QuadraticBezier.h"
//#include "ArcF.h"
#include "drawingSVG.h"
using namespace std;

class Book {
    string name;
    string author;
    size_t publish_year;
    string publisher;
    string genre; // fiction, non-fiction, romance, detective, poetry
    string plot;
    string language;
    size_t number_pages;
    size_t print_run; // тираж
    size_t count;
    int* store_ind = nullptr;
    static int count_stores_books;
public:
    Book();
    Book(string, string, size_t, string, string, string, string, size_t, size_t, int = -1);
    Book(const Book& other);
    Book(Book&& other);
    ~Book();
    void PrintBook();	    // распечатать книгу
    void RunBookOut(int);  // издать книгу
    void WritePages(int);  // написать продолжение истории
    void SellBook(int count = 1);  // продать книгу
    void ReadBook();      // Прочитать книгу


    const string& get_name();
    const string& get_author();
    const size_t& get_publish_year();
    const string& get_publisher();
    const string& get_genre();
    const string& get_plot();
    const string& get_language();
    const size_t& get_number_pages();
    const size_t& get_print_run();
    const size_t& get_count();
    int GetCountClassBooks()
    {
	return Book::count;
    }

    void set_name(const string&);
    void set_author(const string&);
    void set_publish_year(const size_t&);
    void set_publisher(const string&);
    void set_genre(const string&);
    void set_plot(const string&);
    void set_language(const string&);
    void set_number_pages(const size_t&);
    void set_print_run(const size_t&);
    void set_count(const size_t&);
    void set_store(int);
    friend ostream& operator<<(ostream& os, Book b);
};