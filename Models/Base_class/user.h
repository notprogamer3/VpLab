//
// Created by rdast on 25.02.2024.
//

#ifndef C___USER_H
#define C___USER_H

#include "user.h"
#include <string>
#include <iostream>

using namespace std;

class User {
protected:
    string nickname;

public:
    virtual void CoutData()=0;

    void setNickname(string nick);

};


#endif //C___USER_H
