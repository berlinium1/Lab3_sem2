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

class hashTable{
    List *linkedList; // хеш-таблица является массивом связных списков
    int engagedCells; // задействованные ячейки таблицы
    int size;
    
public:
    
    hashTable();
    int getSize();
    void clear();
    bool is_overloaded();
    void resize();
    int generateHash(string word);
    void push_back(word definition);  // вставить в конец связанного списка
    void output();                 // вывод хеш-таблицы
    void find(string term);    // найти указанное слово в хеш-таблице
    void calculateColisions(); // подсчёт количества коллизий
    
};



#endif /* hashTable_hpp */
