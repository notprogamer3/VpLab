//
// Created by rdast on 14.04.2024.
//

#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <iostream>
#include <string>
#include "Models/Depended class/Photo.h"
using namespace std;



class MyContainer {
private:
    Photo *data;
    int size;
    int capacity;

public:

    MyContainer() {
        this->capacity = 1;
        this->size = 0;
        this->data = new Photo[capacity];
    }

    ~MyContainer() {
        delete[] data;
    };


    void push_back(Photo val) {
        if (size >= capacity) {
            capacity++;
            Photo *new_data = new Photo[capacity];
            for (int i = 0; i < size; i++) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
        }
        data[size] = val;
        size++;
    };

    void coutData() {
        for (int i = 0; i < size; i++) {
            cout << data[i] << " | ";
        }
    };


    Photo& operator[](int index) {
        if (index >= 0 and index < size) {
            return data[index];
        }
        cout << "Index out of range" << endl;
        exit(1);
    }

    int getCapacity() {
        return capacity;
    }

    void sort() {
        // По дате
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (data[j] > data[j + 1]) {
                    Photo temp = data[j];
                    data[j] = data[j + 1];
                    data[j + 1] = temp;
                }
            }
        }
    }

    void filter(string owner) {
        for (int i = 0; i < size; i++) {
            if (data[i].getOwner() == owner) {
                cout << data[i] << " ";
            }
        }
    }


};





#endif //MYVECTOR_H
