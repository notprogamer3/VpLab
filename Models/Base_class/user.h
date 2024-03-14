//
// Created by rdast on 25.02.2024.
//

#ifndef C___USER_H
#define C___USER_H

#include <string>
#include <iostream>

using namespace std;

class User {
protected:
    string login;

public:
    virtual void CoutData()=0;

    string getLogin();
};


#endif //C___USER_H
