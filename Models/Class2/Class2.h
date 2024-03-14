//
// Created by rdast on 25.02.2024.
//

#ifndef C___CLASS2_H
#define C___CLASS2_H
#include "Models/Base_class/user.h"
#include <string>

using namespace std;


class Human : User {
private:
    string name;
    string surname;
    int age;

public:
    // загнать все сеттеры с параметрами внутрь самих функций как в photo


    Human(string login, string name, string surname, int age);

    void CoutData();

    void setName(string);

    void setSurname(string);

    void setAge(int);

    string getName();

    string getSurname();

    int getAge();


};


#endif //C___CLASS2_H
