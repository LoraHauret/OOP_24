#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <vector>
using namespace std;


class Element
{
public:
    enum class Origin { UNDEFINED = 0, GREEK, INDIA, PERSIAN, LATIN };
    enum class PHASE { UNDEFINED = 0, GAS, SOLID, LIQUID };

    Element(string, string, unsigned short, unsigned short, float, size_t, size_t, Origin, PHASE, const  float* = nullptr, const  float* = nullptr, const  float*  = nullptr, const  float*  = nullptr, const  float*  = nullptr);
    ~Element();
    // demo functions:
    void printElement();
    void meltElement();
    void boilElement();
    void freezeElement();
    Element* loadElement(ifstream&);
    Element** loadElements(string path, size_t&);

private:
    Element();
    //block
    float atomic_weight;          // ������������� ������� �����
    float* density = nullptr;                // ���������
    float* melting_point = nullptr;          // ����������� ���������
    float* boiling_point = nullptr;          // ����������� �������
    float* specific_heat_capacity = nullptr; // �������� ������������
    float* electronegativity = nullptr;       // �������������������
    size_t atomic_number;          // ���������� ����� �������� � ���������� ��������
    size_t neutrons_number;        // ���������� ���������, ���� ���������� �� ���������, �� ������
    Origin name_origin;            // ������������� ��������
    PHASE phase;                   // ���������� ���������
    string name;                   // �������� ��������
    unsigned short group;          //  ������
    unsigned short period;         // ������
    string symbol;                 // ������ ��������
    
public:
    const float& get_atomic_weight();
    const float& get_density();
     const float& get_melting_point();
     const float& get_boiling_point();
     const float& get_specific_heat_capacity();
     const float& get_electronegativity();
     const size_t& get_atomic_number();
     const size_t& get_neutrons_number();
     Origin get_name_origin();
     PHASE get_phase();
     const string& get_name();
     const  unsigned short& get_group();
     const unsigned short& get_period();
     const string& get_symbol();

//private:
     void set_atomic_weight(const float& = 0);
     void set_density(const float& = 0);
     void set_melting_point(const float& = 0);
     void set_boiling_point(const float& = 0);
     void set_specific_heat_capacity(const float& = 0);
     void set_electronegativity(const float& = 0);
     void set_atomic_number(const size_t&);
     void set_neutrons_number(const size_t&);
     void set_name_origin(const Origin);
     void set_phase(const PHASE);
     void set_name(const string&);
     void set_group(const unsigned short&);
     void set_period(const unsigned short&);
     void set_symbol(const string&);


    friend ostream& operator<<(ostream& os, Element&);
};

// vector<Element*> elements_set;