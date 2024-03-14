//
// Created by rdast on 25.02.2024.
//

#include "iostream"
#include "./Class2.h"


using namespace std;

Human::Human(string login, string name, string surname, int age) {
    this->login=login;
    this->name=name;
    this->surname=surname;
    this->age=age;
}

void Human::CoutData() {
    User::CoutData();
    cout<<" name: "<<this->name<<" surname: "<<this->surname<<" age: "<< this->age<<endl;
}

void Human::setName(string name) {
    this->name=name;
}

void Human::setSurname(string surname) {
    this->surname=surname;
}

void Human::setAge(int age) {
    this->age=age;
}

string Human::getName() {
    return this->name;
}

string Human::getSurname() {
    return this->surname;
}

int Human::getAge() {
    return this->age;
}

