//
// Created by rdast on 25.02.2024.
//

#ifndef C___CLASS1_H
#define C___CLASS1_H
#include "Models/Base_class/user.h"
#include <string>

using namespace std;


class Account : User {
private:
    string password;
    bool admin=0;

public:

    Account(string login, string password);

    void setPassword(string password);

    void setAdmin(string SysPassword);

    string getPassword();

    bool getAdmin();

    string getNickname();

    void CoutData();
};

#endif //C___CLASS1_H
