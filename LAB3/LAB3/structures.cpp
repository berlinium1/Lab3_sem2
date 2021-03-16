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

//void ListElement::set (int a) {
//    value = a;
//}



List::List (int a) {
    ListElement dop (a, NULL);
    firstElem = &dop;
}

void List::addElem (int a) {
    ListElement *p;
    p = firstElem;
    firstElem = new ListElement(a, p);
}

int List::get (int n) {
    ListElement *movingElem = firstElem;
    for (int i=0; i<n; i++) {
        movingElem = movingElem->pointer;
    }
    return movingElem->value;
}
