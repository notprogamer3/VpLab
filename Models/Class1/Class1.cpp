//
// Created by rdast on 25.02.2024.
//


#include "Class1.h"


Account::Account(string login, string password) {
    this->login = login;
    this->password = password;
}

void Account::setPassword(string password) {
    this->password = password;
}

string Account::getPassword() {
    return this->password;
}

bool Account::getAdmin() {
    return this->admin;
}

void Account::setAdmin(string SysPassword) {
    if (SysPassword == "admin") {
        this->admin = 1;
    }
    else {
        this->admin = 0;
    }
}

string Account::getNickname() {
    return this->login;
}

void Account::CoutData() {
    User::CoutData();
    cout << "login: " << this->login << " password: " << this->password << " admin: " << this->admin;
}