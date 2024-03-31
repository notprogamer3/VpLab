//
// Created by rdast on 25.02.2024.
//


#include "Photo.h"

Photo::Photo(string filename, int day, int month, int year, vector<Human> humansonphoto, Account *owner) {
    this->filename=filename;
    this->day=day;
    this->month=month;
    this->year=year;
    this->humansonphoto=humansonphoto;
    this->owner=owner;
}

void Photo::setFilename(string filename) {
    this->filename=filename;
};

void Photo::setDate(int day, int month, int year) {
    this->day=day;
    this->month=month;
    this->year=year;

};

void Photo::setHuman(vector<Human> humansonphoto){
    this->humansonphoto=humansonphoto;
};

string Photo::getFilename(){
    return this->filename;
};

string Photo::getDate(){
    return to_string(this->day)+"."+to_string(this->month)+"."+to_string(this->year);
};

vector<Human> Photo::getHumanList() {
    return this->humansonphoto;
};

string Photo::getOwner(){
    if (this->owner==NULL){
        return "Нет владельца";
    }
    return this->owner->getNickname();
};

void Photo::CoutData(){
    cout<<"filename: "<<this->filename<<" date: "<<this->getDate()<<" owner: "<<this->getOwner()<<endl;
    cout<<"Humans on photo: ";
    for (int i=0; i<this->humansonphoto.size(); i++){
        cout<<this->humansonphoto[i].getName()<<" "<<this->humansonphoto[i].getSurname()<<", ";
    }
    cout<<endl;
};

std::ostream& operator<<(std::ostream& os, const Photo& photo) {
    os << "filename: " << photo.filename
       << " date: " << photo.day << "." << photo.month << "." << photo.year
       << " owner: " << (photo.owner ? photo.owner->getNickname() : "Нет владельца")
       << " Humans on photo: ";

    return os;
}

std::istream& operator>>(std::istream& is, Photo& photo) {
    std::string ownerNickname;
    cout << "Filename: ";
    is >> photo.filename;
    cout << "Day: ";
    is >> photo.day;
    cout << "Month: ";
    is >> photo.month;
    cout << "Year: ";
    is >> photo.year;

    return is;
}

bool Photo::operator==(const Photo& other) const {
    return filename == other.filename && day == other.day && month == other.month && year == other.year;
}

bool Photo::operator!=(const Photo& other) const {
    return !(*this == other);
}

bool Photo::operator<(const Photo& other) const {
    if (year != other.year)
        return year < other.year;
    if (month != other.month)
        return month < other.month;
    return day < other.day;
}

bool Photo::operator>(const Photo& other) const {
    if (year != other.year)
        return year > other.year;
    if (month != other.month)
        return month > other.month;
    return day > other.day;
}