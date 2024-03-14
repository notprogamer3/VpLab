#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include "cmath"
#include <vector>
#include "Models/Depended class/Photo.h"


using namespace std;
vector<Photo> photos;

#pragma region функции-заглушки
int f1() {
    std::cout << "function f1 is running...\n\n";
    return 1;
}

int f2() {
    std::cout << "function f2 is running...\n\n";
    return 2;
}

int f3() {
    std::cout << "function f3 is running...\n\n";
    return 3;
}
int f4() {
    std::cout<<"(╯°□°)╯︵ ┻━┻\n\n";
    return 4;
}
int f5() {
    std::cout<<std::sqrt(100)<<"\n\n";
    return 5;
}
int f6() {
    string filename;
    int day, month, year;
    for (int i = 0; i < 4; ++i) {
        switch (i) {
            case 0:
                cout << "Введите имя файла: ";
                cin >> filename;
                break;
            case 1:
                cout << "Введите день: ";
                cin >> day;
                break;
            case 2:
                cout << "Введите месяц: ";
                cin >> month;
                break;
                case 3:
                cout << "Введите год: ";
                cin >> year;
                break;
        }
    }
    Photo temp = Photo(filename, day, month, year, vector<Human>(), nullptr);
    photos.push_back(temp);
    return 6;
}

int f7() {
    for (int i = 0; i < photos.size(); ++i) {
        photos[i].CoutData();
    }
    return 7;
}

#pragma endregion


const int ITEMS_NUMBER = 7;

int main() {
    CMenuItem items[ITEMS_NUMBER] {CMenuItem{"first item", f1},
                                   CMenuItem{"second item", f2},
                                   CMenuItem{"third item", f3},
                                   CMenuItem{"Вывести смайлик", f4},
                                   CMenuItem{"Квадратный корень из 100", f5},
                                   CMenuItem{"Добавить фото", f6},
                                   CMenuItem{"Вывести список фото", f7}};
    CMenu menu("My console menu", items, ITEMS_NUMBER);
    while (menu.runCommand()) {};
    return 0;
}
