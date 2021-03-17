//
//  hashTable.hpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 16.03.2021.
//

#ifndef hashTable_hpp
#define hashTable_hpp

#include <stdio.h>
#include <iostream>
#include "structures.hpp"

struct hashTable{
    int size = 98215; 
    List *linkedList = new List[size];  //хеш-таблица является массивом связных списков
    hashTable();
    int generateHash(string word);
    void push_back(word definition);  // вставить в конец связанного списка
    void output();                 // вывод хеш-таблицы
    void find(string term);    // найти указанное слово в хеш-таблице
    void calculateColisions(); // подсчёт количества коллизий
};



#endif /* hashTable_hpp */
