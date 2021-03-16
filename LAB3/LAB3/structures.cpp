//
//  structures.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#include "structures.hpp"




ListElement::ListElement() {}

ListElement::ListElement(int a, ListElement *p) {
    value = a;
    pointer = p;
}




List::List () {
    
}

void List::addFirstElem (int a) {
    firstElem.value = a;
    firstElem.pointer = NULL;
}

void List::addElem (int a) {
    ListElement *movingElem = &firstElem;
    while (movingElem->pointer != NULL) {
        movingElem = movingElem->pointer;
    }
    ListElement *newElement = new ListElement;
    newElement->value = a;
    newElement->pointer = NULL;
    movingElem->pointer = newElement;
}

int List::get (int n) {
    ListElement *movingElem = &firstElem;
    for (int i=0; i<n; i++) {
        movingElem = movingElem->pointer;
    }
    return movingElem->value;
}
