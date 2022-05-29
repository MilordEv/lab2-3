#ifndef __SET__
#define __SET__

#include "AVLTree.hpp"

template <typename T>
class Set {
    private:
        AVLTree<T>* items;

    public:
        Set(T* items, int number);
        Set();
        Set(const Set<T> &set);
        
        ~Set();

        void Add(T value);
        void Remove(T value);
        bool Find(T value);
        void Map(T func(T));
        void Where(bool func(T));
        T Reduce(T func(T, T), T startValue);
        void Print();
};

template <typename T>
Set<T>::Set(T* items, int number) {
    this->items = new AVLTree<T>;

    for (int i = 0; i < number; i++) {
        if (!(this->items->Find(items[i]))) {
            this->items->Insert(items[i]);
        }
    }
}

template <typename T>
Set<T>::Set() {
    this->items = new AVLTree<T>;
}

template <typename T>
Set<T>::Set(const Set<T> &set) {
    this->items = nullptr;
    *(this->items) = *(set.items);
}

template <typename T>
Set<T>::~Set() {
    delete this->items;
}


template <typename T>
void Set<T>::Add(T value) {
    if (!(this->items->Find(value))) {
        this->items->Insert(value);
    }
}

template <typename T>
void Set<T>::Remove(T value) {
    if (!(this->items->Find(value))) {
        this->items->Remove(value);
    }
}

template <typename T>
bool Set<T>::Find(T value) {
    return this->items->Find(value);
}

template <typename T>
void Set<T>::Map(T func(T)) {
    AVLTree<T>* newTree = this->items->Map(func);
    delete this->items;
    this->items = newTree;
}

template <typename T>
void Set<T>::Where(bool func(T)) {
    AVLTree<T>* newTree = this->items->Where(func);
    delete this->items;
    this->items = newTree;
}

template <typename T>
T Set<T>::Reduce(T func(T, T), T startValue) {
    return this->items->Reduce(func, startValue);
}

template <typename T>
void Set<T>::Print() {
    this->items->Print();
}

#endif