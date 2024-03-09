//
// Created by rdast on 25.02.2024.
//

#include "user.h"
#include <string>
#include <iostream>
;


void User::CoutData() {
    cout<<"nickaname: "<< this->nickname;
}

void User::setNickname(std::string nick) {
    this->nickname=nickname;
}