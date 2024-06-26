//
// Created by user on 04.03.2024.
//

#ifndef PROJECTCPP_CMENU_CPP
#define PROJECTCPP_CMENU_CPP


#include "./CMenu.h"


CMenu::CMenu(string title, CMenuItem *items, size_t count) : title(title), items(items), count(count) {}

int CMenu::getSelect() const {
    return select;
}
bool CMenu::isRun() const {
    return running;
}
size_t CMenu::getCount() const {
    return count;
}
string CMenu::getTitle() {
    return title;
}
CMenuItem *CMenu::getItems() {
    return items;
}
void CMenu::print() {
    for (size_t i{}; i < count; ++i) {
        std::cout << i + 1 << ". ";
        items[i].print();
        std::cout << std::endl;
    }
    std::cout << "0. exit" << std::endl;
}
int CMenu::runCommand() {
    print();
    std::cout << "\nSelect >> ";
    std::cin >> select;
    if (select == 0) {
        return 0;
    }
    return items[select - 1].run();
}


#endif //PROJECTCPP_CMENU_CPP
