//
//  structures.hpp
//  LAB3
//

#ifndef structures_hpp
#define structures_hpp

#include <iostream>
#include <stdio.h>

using namespace std;

struct word{
    string key;
    string definition;
};

struct listElement{
    int value;
    listElement* pointer;
};

struct List{
    listElement firstElem;
    List(int a);
    void addElem(int a);
    int get(int n);
};






struct Table{
    listElement** list;
    int size = 98215;
    
public:
    
    Table();
    int getHash(string key);
    void tableOutput();
};


#endif /* structures_hpp */
