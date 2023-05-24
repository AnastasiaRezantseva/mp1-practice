#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "cars.h"
#include <stdlib.h>

#include <ifstream>
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

string* getPath()
{
   string* file_path;
    while (1) {
        cout <<"Enter the path to file : " << endl;
        getline(cin, *file_path);
        if (file_path != NULL)
            break;
    }
    return file_path;
}

Car ReadCarEntity(ifstream* file)
{
    char* car_brand = read_string(file);
    char* car_color = read_string(file);
    char* car_serial_number = (read_string(file));
    char* car_registration_number = (read_string(file));
    int car_count_door = atoi(read_string(file));
    int car_year = atoi(read_string(file));
    int car_price = atoi(read_string(file));

    Car new_car = { car_brand, car_color, car_serial_number, car_registration_number, car_count_door, car_year, car_price };
    return new_car;
}


Car* ReadCarFile(string* file_path, int* number_of_cars)
{
    ifstream* file;
    file.open(file_path);


   // FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        throw "Read file error ";
    }
    Car* cars = (Car*)malloc(sizeof(Car));
    *number_of_cars = 1;

    // we assume that the file contains information about at least one car
    while (1) {
        Car current_car = ReadCarEntity(file);
        cars[*number_of_cars - 1] = current_car;
        if (read_string(file) == NULL) {
            break;
        }
        else {
            cars = (Car*)realloc(cars, (*number_of_cars + 1) * sizeof(Car));
            *number_of_cars += 1;
        }
    }
    fclose(file);
    return cars;
}

Car FindOldestCar(Car* cars, int count_of_cars)
{
    Car oldest_car = cars[0];
    for (int i = 1; i < count_of_cars; ++i) {
        if (cars[i].year < oldest_car.year) {
            oldest_car = cars[i];
        }
    }
    return oldest_car;
}

void PrintCar(Car car)
{
    cout << "Brand: " << car.brand << endl;
    cout << "Color: " << car.color << endl;
    cout << "Serial number: " << car.serial_number << endl;
    cout << "Regestrarion number: " << car.registration_number << endl;
    cout << "Numbers of doors: " << car.count_door << endl;
    cout << "Year of car manufacture: " << car.year << endl;
    cout << "Price: " << car.price << endl;
}