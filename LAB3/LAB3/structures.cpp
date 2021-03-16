//
//  structures.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#include "structures.hpp"

struct ListElement {
    int value;
    ListElement* pointer;
    ListElement () {}
    ListElement (int a) {
        value = a;
    }
    ListElement (int a, ListElement *p) {
        value = a;
        pointer = p;
    }
};

struct List {
    ListElement firstElem;
    List (int a) {
        firstElem.value = a;
        firstElem.pointer = NULL;
    }
    void addElem (int a) {
        firstElem = *new ListElement(a, &firstElem);
    }
    int get (int n) {
        ListElement movingElem = firstElem;
        for (int i=0; i<=n; i++) {
            movingElem = *movingElem.pointer;
        }
        return movingElem.value;
    }
};
