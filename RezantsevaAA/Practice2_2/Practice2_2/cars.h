#ifndef _CARS_H
#define _CARS_H
#include <string>
using namespace std;
typedef struct
{
    char* brand;
    char* color;
    char* serial_number;
    char* registration_number;
    int count_door;
    int year;
    int price;
} Car;

string* read_string(ifstream* stream);
string* getPath();
Car ReadCarEntity(ifstream* file);
Car* ReadCarFile(string* file_path, int* number_of_cars);
Car FindOldestCar(Car* cars, int count_of_cars);
void PrintCar(Car car);

#endif _CARS_H#pragma once
