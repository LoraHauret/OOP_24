#pragma once
#include "Book.h"



Book::Book() :Book("no name", "no author", 0, "no publisher", "no genre", "no plot", "no language", 0, 0) {}

Book::Book(string name, string author, size_t publish_year, string publisher = "unknown", string genre = "not known", string plot = "not known", string language = "undefined", size_t number_pages = 0, size_t print_run = 1)
{
    this->name = name;
    this->author = author;
    this->publish_year = publish_year;
    this->publisher = publisher;
    this->genre = genre;
    this->plot = plot;
    this->language = language;
    this->number_pages = number_pages;
    this->print_run = print_run;
    this->count = print_run;
}

void Book::PrintBook()
{
    cout << "\n*************\n";
    cout << "name:\t\t" << name << "\n";
    cout << "author:\t\t" << author << "\n";
    cout << "publish_year:\t" << publish_year << "\n";
    cout << "publisher:\t" << publisher << "\n";
    cout << "genre:\t\t" << genre << "\n";
    cout << "plot:\t\t" << plot << "\n";
    cout << "language:\t" << language << "\n";
    cout << "number_pages:\t" << number_pages << "\n";
    cout << "print_run:\t" << print_run << "\n";
    cout << "avaliable count: " << count << "\n";
}
ostream& operator<<(ostream& os, Book b)
{
    os << "\n*************\n";
    os << "name:\t\t" << b.name << "\n";
    os << "author:\t\t" << b.author << "\n";
    os << "publish_year:\t" << b.publish_year << "\n";
    os << "publisher:\t" << b.publisher << "\n";
    os << "genre:\t\t" << b.genre << "\n";
    os << "plot:\t\t" << b.plot << "\n";
    os << "language:\t" << b.language << "\n";
    os << "number_pages:\t" << b.number_pages << "\n";
    os << "print_run:\t" << b.print_run << "\n";
    os << "avaliable count: " << b.count << "\n";
    return os;
}

void Book::RunBookOut(int count)
{
    cout << "the book copies are printings...\n";
    this->print_run += count;
    this->count += count;
}

void Book::WritePages(int count)
{
    cout << "writer is writting continuation of the story....\n";
    this->number_pages += count;
}

void Book::SellBook(int count)
{
    if (this->count >= count)
    {
	this->count -= count;
	cout << "selling....\n";
    }

    else
    {
	cout << "Sorry. Only " << this->count << " books can be sold. ";
	this->count = 0;
    }
}

void Book::ReadBook()
{
    cout << "The book is being read aloud...." << "\n";
}

const string& Book::get_name()
{
    return name;
}
const string& Book::get_author()
{
    return author;
}
const size_t& Book::get_publish_year()
{
    return publish_year;
}
const string& Book::get_publisher()
{
    return publisher;
}
const string& Book::get_genre()
{
    return genre;
}
const string& Book::get_plot()
{
    return plot;
}
const string& Book::get_language()
{
    return language;
}
const size_t& Book::get_number_pages()
{
    return number_pages;
}
const size_t& Book::get_print_run()
{
    return print_run;
}
const size_t& Book::get_count()
{
    return count;
}

void Book::set_name(const string& val)
{
    this->name = name;
}
void Book::set_author(const string& val)
{
    this->author = val;
}
void Book::set_publish_year(const size_t& val)
{
    this->publish_year = val;
}
void Book::set_publisher(const string& val)
{
    this->publisher = val;
}
void Book::set_genre(const string& val)
{
    this->genre = val;
}
void Book::set_plot(const string& val)
{
    this->plot = val;
}
void Book::set_language(const string& val)
{
    this->language = val;
}
void Book::set_number_pages(const size_t& val)
{
    this->number_pages = val;
}
void Book::set_print_run(const size_t& val)
{
    this->print_run = val;
}
void Book::set_count(const size_t& val)
{
    this->count = val;
}