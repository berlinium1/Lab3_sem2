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
    List *linkedList; //хеш-таблица является массивом связных списков
    int engagedCells;
public:
    int size;
    hashTable(int lenght = 100000){
        engagedCells = 0;
        size = lenght;
        linkedList = new List[size];
    };
    
    void clear(){
        for (int i = 0; i < size; i++) {
            if (linkedList[i].firstElem.value.key != ""){
                //delete[] linkedList[i];
            }
        }
    }
    
    bool is_overloaded(){
        bool flag = false;
        int fillIndex = 0.8;
        if (size*fillIndex <= engagedCells) {
            flag = true;
        }
        return flag;
    }
    void resize(){
        size *= 2;
        linkedList = new List[size];
        engagedCells = 0;
       //linkedList = new List[size];
    }
    int generateHash(string word);
    void push_back(word definition);  // вставить в конец связанного списка
    void output();                 // вывод хеш-таблицы
    void find(string term);    // найти указанное слово в хеш-таблице
    void calculateColisions(); // подсчёт количества коллизий
    
};



#endif /* hashTable_hpp */
