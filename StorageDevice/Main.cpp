#pragma once
#include "PortableHD.h"
#include "SmartPh.h"
#include "Tablet.h"
#include "Store.h"

int main()
{
    setlocale(0, "");
    Store computer_store;
    computer_store.AddDevice(new Tablet("Tablet", "iPad", "seagate", 256, 7, ""));
    computer_store.AddDevice(new Tablet("Tablet", "iPad", "Samsung Galaxy", 128, 17, ""));
    computer_store.AddDevice(new Tablet("Tablet", "Tab V11", "Lenovo Tab", 128, 10, ""));
    computer_store.AddDevice(new SmartPh("Mobile", "Samsung Galaxy", "Samsung", 128, 15, ""));
    computer_store.AddDevice(new SmartPh("Smartphone", "Xiaomi Redmi Note", "Xiaony", 512, 5, ""));
    computer_store.AddDevice(new PortableHD("HD", "Toshiba Canvio Basics", "Toshiba", 1000, 15, ""));
    computer_store.AddDevice(new PortableHD("HD", "Transcend Store Jet", "Transcend", 1000, 17, ""));

    Tablet* t = new Tablet("test", "test", "test", 256, 7, "");
    t->CreateFile("test file.txt");
    t->CreateFile("just a file.txt");
    t->CreateFile("file.txt");

    computer_store.AddDevice(t);
    computer_store.Print();

    
    computer_store.LoadDevice(8);

    computer_store.SearchByCapacity(128);
    computer_store.SearchByCount(10);
    computer_store.SearchByName("Tablet");
    computer_store.SearchByManufacture("Samsung");
    computer_store.RemoveDevice(3);
    computer_store.Print();
}
