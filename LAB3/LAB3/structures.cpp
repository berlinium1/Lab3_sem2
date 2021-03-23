//
//  structures.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#include "structures.hpp"




ListElement::ListElement() {}

List::List () {}

void List::addFirstElem (word a) { //добавление первого елемента в лист
    firstElem.value.key = a.key;
    firstElem.value.definition = a.definition;
    firstElem.pointer = NULL;
    number++;
}

void List::addElem (word a) { //добавления елемента в конец листа
    ListElement *movingElem = &firstElem;
    while (movingElem->pointer != NULL) { //переводим мувинг в самый конец
        movingElem = movingElem->pointer;
    }
    ListElement *newElement = new ListElement;
    newElement->value = a;
    newElement->pointer = NULL;
    movingElem->pointer = newElement; //добавляем новый елемент и кидаем на него ссылку
    number++;
}


word List::get (int n) { //получения елемента с любым индексом
    ListElement *movingElem = &firstElem;
    for (int i=0; i<n; i++) {
        movingElem = movingElem->pointer;
    }
    return movingElem->value;
}

void List::clear() {
    delElem(&firstElem);
}

void List::delElem(ListElement *elem) {
    if (elem->pointer != NULL) {
        delElem(elem->pointer);
    }
    delete elem->pointer;
}
