//
// Created by rdast on 25.02.2024.
//

#ifndef C___CLASS2_H
#define C___CLASS2_H
#include "Models/Base_class/user.h"


class Human : User {
private:
    string name;
    string surname;
    int age;

public:

    Human(string nickname, string name, string surname, int age);

    virtual void CoutData();
};


#endif //C___CLASS2_H
