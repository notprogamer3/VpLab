//
// Created by user on 04.03.2024.
//

#ifndef PROJECTCPP_CMENU_H
#define PROJECTCPP_CMENU_H


#pragma once
#include <cstddef>
#include <string>
#include "./CMenuItem.h"



using namespace std;
class CMenu {
public:
    CMenu(string, CMenuItem *, size_t);
    int getSelect() const;
    bool isRun() const;
    string getTitle();
    size_t getCount() const;
    CMenuItem *getItems();
    void print();
    int runCommand();
private:
    int select{-1};
    size_t count{};
    bool running{};
    string title{};
    CMenuItem *items{};
};

#endif //PROJECTCPP_CMENU_H
