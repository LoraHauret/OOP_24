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
    size_t print_run; // �����
    size_t count;

public:
    Book();
    Book(string, string, size_t, string, string, string, string, size_t, size_t);
    void PrintBook();	    // ����������� �����
    void RunBookOut(int);  // ������ �����
    void WritePages(int);  // �������� ����������� �������
    void SellBook(int count = 1);  // ������� �����
    void ReadBook();      // ��������� �����


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

    friend ostream& operator<<(ostream& os, Book b);
};