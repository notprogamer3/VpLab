//
// Created by rdast on 25.02.2024.
//


#ifndef C__PHOTO_H
#define C__PHOTO_H

#include <string>
#include "Models/Class1/Class1.h"
#include "Models/Class2/Class2.h"



using namespace std;

class Photo {
private:
    string filename;
    int day;
    int month;
    int year;
    Human *humansonphoto;
    Owner owner;


};

#endif //C___DEP_CLASS_H
