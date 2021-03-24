//
//  structures.hpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#ifndef structures_hpp
#define structures_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

struct word{
    string key = "";
    string definition = "";
};

struct ListElement { //структура в которой хранится значение елемента и указатель на следущий
    word value;
    ListElement* pointer;
    ListElement ();
};

class List{ //клас связного списка
public:
    void delElem(ListElement *elem);
    ListElement firstElem;
    List();
    int number = 0;
    void addFirstElem (word a);
    void addElem (word a);
    void clear();
    word* get(int n);
};


#endif /* structures_hpp */
