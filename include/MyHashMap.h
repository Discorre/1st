#ifndef MYHASHMAP_H
#define MYHASHMAP_H

#include <iostream>
#include <string>
//#include "vectorDas.h"

//using namespace std;

// структура для хранения значения
template <typename TK, typename TV>
struct NodeMap {
    TK key;
    TV value;
    NodeMap* next;
};

// структура для хранения ключа и значения
template <typename TK, typename TV>
struct MyHashMap {
    NodeMap<TK, TV>** data;
    int len;
    int cap;
    int LoadFactor;
};

// хэш-функция для ключа int
template <typename TK>
int HashCode(const TK& key) {
    unsigned long hash = 5381;
    int c = 0;
    for (char ch : key) {
        hash = ((hash << 5) + hash) + ch; /* hash * 33 + c */
    }
    return hash;
}

// инициализация хэш таблицы
template <typename TK, typename TV>
MyHashMap<TK, TV>* CreateMap(int initCapacity, int initLoadFactor) {
    if (initCapacity <= 0 || initLoadFactor <= 0 || initLoadFactor > 100) {
        throw std::runtime_error("Index out of range");
    }

    MyHashMap<TK, TV>* map = new MyHashMap<TK, TV>;
    map->data = new NodeMap<TK, TV>*[initCapacity];
    for (int i = 0; i < initCapacity; i++) {
        map->data[i] = nullptr;
    }

    map->len = 0;
    map->cap = initCapacity;
    map->LoadFactor = initLoadFactor;
    return map;
}

// расширение
template <typename TK, typename TV>
void Expansion(MyHashMap<TK, TV>& map) {
    int newCap = map.cap * 2;
    NodeMap<TK, TV>** newData = new NodeMap<TK, TV>*[newCap];
    for (int i = 0; i < newCap; i++) {
        newData[i] = nullptr;
    }
    // проход по всем ячейкам
    for (int i = 0; i < map.cap; i++) {
        NodeMap<TK, TV>* curr = map.data[i];
        // проход по парам коллизионных значений и обновление
        while (curr != nullptr) {
            NodeMap<TK, TV>* next = curr->next;
            int index = HashCode(curr->key) % newCap;
            curr->next = newData[index];
            newData[index] = curr;
            curr = next;
        }
    }

    delete[] map.data;

    map.data = newData;
    map.cap = newCap;
}

// обработка коллизий
template <typename TK, typename TV>
void CollisionManage(MyHashMap<TK, TV>& map, int index, const TK& key, const TV& value) {
    NodeMap<TK, TV>* newNod = new NodeMap<TK, TV>{key, value, nullptr};
    NodeMap<TK, TV>* curr = map.data[index];
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = newNod;
}

// добавление элементов
template <typename TK, typename TV>
void AddMap(MyHashMap<TK, TV>& map, const TK& key, const TV& value) {
    if ((map.len + 1) * 100 / map.cap >= map.LoadFactor) {
        Expansion(map);
    }
    int index = HashCode(key) % map.cap;
    NodeMap<TK, TV>* temp = map.data[index];
    if (temp != nullptr) {
        if (temp->key == key) {
            // обновить значение ключа
            temp->value = value;
            map.data[index] = temp;
        } else {
            CollisionManage(map, index, key, value);
        }
    } else {
        NodeMap<TK, TV>* newNod = new NodeMap<TK, TV>{key, value, map.data[index]};
        map.data[index] = newNod;
        map.len++;
    }

}


// поиск элементов по ключу
template <typename TK, typename TV>
TV GetMap(const MyHashMap<TK, TV>& map, const TK& key) {
    int index = HashCode(key) % map.cap;
    NodeMap<TK, TV>* curr = map.data[index];
    while (curr != nullptr) {
        if (curr->key == key) {
            return curr->value;
        }
        curr = curr->next;
    }

    throw std::runtime_error("Key not found");
}


// удаление элементов
template <typename TK, typename TV>
void DeleteMap(MyHashMap<TK, TV>& map, const TK& key) {
    int index = HashCode(key) % map.cap;
    NodeMap<TK, TV>* curr = map.data[index];
    NodeMap<TK, TV>* prev = nullptr;
    while (curr != nullptr) {
        if (curr->key == key) {
            if (prev == nullptr) {
                map.data[index] = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            map.len--;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    throw std::runtime_error("Key not found");
}


// очистка памяти
template <typename TK, typename TV>
void DestroyMap(MyHashMap<TK, TV>& map) {
    for (int i = 0; i < map.cap; i++) {
        NodeMap<TK, TV>* curr = map.data[i];
        while (curr != nullptr) {
            NodeMap<TK, TV>* next = curr->next;
            delete curr;
            curr = next;
        }
    }
    delete[] map.data;
    map.data = nullptr;
    map.len = 0;
    map.cap = 0;
}


#endif