//
// Created by rdast on 25.02.2024.
//


#ifndef C__PHOTO_H
#define C__PHOTO_H

#include <string>
#include "Models/Class1/Class1.h"
#include "Models/Class2/Class2.h"
#include "vector"



using namespace std;

class Photo {
private:
    string filename;
    int day;
    int month;
    int year;
    vector<Human> humansonphoto;
    Account *owner;


public:

        Photo(string filename, int day, int month, int year, vector<Human> humansonphoto, Account *owner);

        void setFilename(string filename);

        void setDate(int day, int month, int year);

        void setHuman(vector<Human> humansonphoto);

        string getFilename();

        string getDate();

        vector<Human> getHumanList();

        string getOwner();

        void CoutData();

};

#endif //C___DEP_CLASS_H
