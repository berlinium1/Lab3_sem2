//
//  structures.hpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#ifndef structures_hpp
#define structures_hpp

#include <stdio.h>
#include <string>

using namespace std;

struct ListElement {
    int value;
    ListElement* pointer;
    ListElement ();
    ListElement (int a, ListElement *p);
    //void set (int a);
};

struct List{
    ListElement firstElem;
    List ();
    void addFirstElem (int a);
    void addElem (int a);
    int get (int n);
};

struct word{
    string key;
    string definition;
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
