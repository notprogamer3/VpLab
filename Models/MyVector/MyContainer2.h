//
// Created by rdast on 26.05.2024.
//

#ifndef MYCONTAINER2_H
#define MYCONTAINER2_H
#include <iostream>
#include <string>
#include "Models/Depended class/Photo.h"
using namespace std;


template<class T>
class ItemContainer {
private:
    T cur_value{};
    ItemContainer *next;
    ItemContainer *prev;

public:
    typedef T obj_type;

    ItemContainer();

    explicit ItemContainer(T val) : cur_value(val) {
    };

    ItemContainer(T val, ItemContainer *next, ItemContainer *prev) : cur_value(val), next(next), prev(prev) {
    };

    ItemContainer(const ItemContainer &it) : ItemContainer<T>(it.cur_value, it.next, it.prev) {
    };

    void set(T v) {
        cur_value = v;
    }

    T get() {
        return cur_value;
    }

    void setNext(ItemContainer *n) {
        next = n;
    }

    T getNext() {
        return next;
    }

    void setBack(ItemContainer *b) {
        prev = b;
    }

    T getBack() {
        return prev;
    }

    friend ostream &operator<<(ostream &os, const ItemContainer &item) {
        os << item.cur_value;
        return os;
    }
};


template<class T>
class MyContainer {
public:
    template<class V>
    class IteratorCont {
        friend class MyContainer<V>;

    public:
        IteratorCont<V>(const IteratorCont<V> &it) : m_item(it.m_item) {
        }

        bool operator==(const IteratorCont<V> &it) const {
            return m_item == it.m_item;
        }

        bool operator!=(const IteratorCont<V> &it) const {
            return m_item != it.m_item;
        }

        IteratorCont<V> &operator++() {
            m_item = m_item->getNext();
            return *this;
        }

        V &operator*() const {
            return *m_item;
        }

    private:
        V *m_item{};

        explicit IteratorCont(V *p) : m_item(p) {
        }
    };

    typedef IteratorList<T> iterator;
    typedef IteratorList<T> const_iterator;

    MyContainer() = default;

    explicit MyContainer(T *it) {
        initList(*it);
    }

    iterator begin() {
        return iterator(m_start);
    }

    iterator end() {
        return iterator(m_end);
    }

    const_iterator begin() const {
        return const_iterator(m_start);
    }

    const_iterator end() const {
        return const_iterator(m_end);
    }

    void erase() {
        for (int i{}; i < m_len; ++i) {
            m_start = m_start->getNext();
            delete m_start->getBack();
        }
        delete m_end;
        m_start = m_end = nullptr;
        m_len = 0;
    }

    ~MyContainer() {
        erase();
    }

    friend ostream &operator<<(ostream &out, const MyContainer<T> &lst) {
        if (lst.isEmpty()) {
            out << "List is empty" << endl;
            return out;
        }
        for (const ItemList<typename T::objType> &it: lst) {
            out << it << endl;
        }
        return out;
    }

    MyContainer(const MyContainer<T> &lst) = delete;

    // метод проверки на пустоту
    bool isEmpty() const {
        return !m_start;
    }

    size_t len() {
        return m_len;
    }

    void add(T *it) {
        if (isEmpty()) {
            initList(*it);
        } else {
            m_end->getBack()->setNext(it);
            it->setNext(m_end);
            m_end->setBack(it);
            ++m_len;
        }
    }

    void pushStart(T *it) {
        if (isEmpty()) {
            initList(*it);
        } else {
            it->setNext(m_start);
            m_start = it;
            ++m_len;
        }
    }

    // метод удаления эл. с конца
    void delEnd() {
        if (isEmpty()) {
            return;
        } else if (len() == 1) {
            delete m_start;
            m_start = nullptr;
            delete m_end;
            m_end = nullptr;
            m_len = 0;
        } else {
            m_end->setBack(m_end->getBack()->getBack());
            delete m_end->getBack()->getNext();
            m_end->getBack()->setNext(m_end);

            --m_len;
        }
    }

    void delStart() {
        if (isEmpty()) {
            return;
        } else if (len() == 1) {
            delete m_start;
            m_start = nullptr;
            delete m_end;
            m_end = nullptr;
            m_len = 0;
        } else {
            m_start = m_start->getNext();
            delete m_start->getBack();
            m_start->setBack(nullptr);
            --m_len;
        }
    }

private:
    T *m_start{};
    T *m_end{};
    size_t m_len{};
    void initList(T &it) {
        m_start = &it;
        m_end = new T(0, m_start);
        it.setNext(m_end);

        m_len = 1;
    }
};



#endif //MYCONTAINER2_H
