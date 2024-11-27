#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student
{
    string name = "noname";
    string surname = "nosurname";
    size_t age = 0;    
    size_t group = 0;
    int* marks = nullptr;
    size_t marks_count = 0;
    size_t capacity = 20;
    const int ENLARGEMENT = 10;
public:
    Student();
    Student(string name, string surname, size_t group, size_t age);
    Student(const Student& other);    
    Student& operator=(const Student& other);
    ~Student();
    string GetName();
    string GetSurname();
    size_t GetAge();
    size_t GetGroup();
    void SetName();
    void SetName(string name);
    void SetSurname();
    void SetSurname(string surname);
    void SetGroup();
    void SetGroup(size_t group);
    void SetAge();
    void SetAge(size_t age);
    void Mark(int m);
    bool EnsureCapacity();
    bool operator==(const Student& other) const;
    bool operator!=(const Student& other) const;
    Student operator+(const Student& other) const;
    operator string() const;
    friend std::ostream& operator<<(std::ostream& out, const Student& st);
};