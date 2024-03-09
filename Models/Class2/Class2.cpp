//
// Created by rdast on 25.02.2024.
//

#include "iostream"
#include "Class2.h"


using namespace std;

Human::Human() {}

void Human::CoutData() {
    User::CoutData();
    cout<<" name: "<<this->name<<" surname: "<<this->surname<<" age: "<< this->age<<endl;
}