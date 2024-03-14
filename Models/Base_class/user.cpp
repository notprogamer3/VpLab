//
// Created by rdast on 25.02.2024.
//

#include "user.h"
#include <string>
#include <iostream>


void User::CoutData() {
    cout<<"login: "<< this->login;
}


std::string User::getLogin() {
    return this->login;
}