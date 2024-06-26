#include "menu/CMenu.h"
#include "menu/CMenuItem.h"
#include "cmath"
#include <vector>
#include <algorithm>
#include "Models/Depended class/Photo.h"
#include <Models/MyVector/MyContainer2.h>


using namespace std;
vector<Photo> photos;

#pragma region функции-заглушки
int f1() {
    std::cout<<"(╯°□°)╯︵ ┻━┻\n\n";
    return 4;
}
int f2() {
    std::cout<<std::sqrt(100)<<"\n\n";
    return 5;
}
int f3() {
    Photo temp("photo.jpg", 1, 1, 2021, vector<Human>(), nullptr);
    cin>>temp;
    photos.push_back(temp);
    return 6;
}

int f4() {
    for (int i = 0; i < photos.size(); ++i) {
        photos[i].CoutData();
    }
    return 7;
}

int f5() {
    sort(photos.begin(), photos.end());
    return 8;
}

int f6() {
    string filename;
    cout<<"Введите имя файла: ";
    cin>>filename;
    for (int i = 0; i < photos.size(); ++i) {
        if (photos[i].getFilename() == filename) {
            photos.erase(photos.begin() + i);
            break;
        }
    }
    return 9;
}

#pragma endregion


const int ITEMS_USER_NUMBER = 5;
const int ITEMS_ADMIN_NUMBER = 6;


int main() {
    MyList<ItemList<int>> lst;

    lst.add(new ItemList<int>(25));
    lst.add(new ItemList<int>(26));
    lst.add(new ItemList<int>(27));
    lst.add(new ItemList<int>(28));
    cout << lst << endl;
    for (const auto& it : lst) {
        cout << it << endl;
    }

    //lst.add(new ItemList<Photo>( Photo("photo.jpg", 1, 1, 2021, vector<Human>(), nullptr)));
    //lst.add(new ItemList<Photo>( Photo("photo2.jpg", 1, 1, 2021, vector<Human>(), nullptr)));
    //lst.add(new ItemList<Photo>( Photo("photo3.jpg", 1, 1, 2021, vector<Human>(), nullptr)));
    //lst.add(new ItemList<Photo>( Photo("photo4.jpg", 1, 1, 2021, vector<Human>(), nullptr)));


    // CMenuItem items[ITEMS_ADMIN_NUMBER] {CMenuItem{"Вывести смайлик", f1},
    //                                CMenuItem{"Квадратный корень из 100", f2},
    //                                CMenuItem{"Добавить фото", f3},
    //                                CMenuItem{"Вывести список фото", f4},
    //                                CMenuItem{"Сортировка списка фото по дате", f5},
    //                                CMenuItem{"Удаление фото", f6}};
    // CMenu menu("My console menu", items, ITEMS_ADMIN_NUMBER);
    // while (menu.runCommand()) {};
    return 0;
}
