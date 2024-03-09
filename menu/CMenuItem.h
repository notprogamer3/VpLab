//
// Created by user on 04.03.2024.
//

#ifndef PROJECTCPP_CMENUITEM_H
#define PROJECTCPP_CMENUITEM_H

#pragma once
#include <iostream>
#include <string>

using namespace std;
class CMenuItem {
public:
    typedef int(*Func)();
    CMenuItem(string, Func);
    Func func{};
    string item_name{};
    string getName();
    void print();
    int run();
};
#endif //PROJECTCPP_CMENUITEM_H
