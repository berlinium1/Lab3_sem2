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
    string key;
    string definition;
};

struct ListElement {
    word value;
    ListElement* pointer;
    ListElement ();
    ListElement (word a, ListElement *p);
    //void set (int a);
};

struct List{
    ListElement firstElem;
    List();
    void addFirstElem (word a);
    void addElem (word a);
    word get(int n);
};

struct Table{
    ListElement** list;
    int size = 98215;
    
public:
    
    Table();
    int getHash(string key);
    void tableOutput();
};


#endif /* structures_hpp */
