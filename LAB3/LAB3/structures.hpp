//
//  structures.hpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#ifndef structures_hpp
#define structures_hpp

#include <stdio.h>

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

#endif /* structures_hpp */
