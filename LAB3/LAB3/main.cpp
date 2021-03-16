//
//  main.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#include <iostream>
#include "functions.hpp"
#include "structures.hpp"
#include "hashTable.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    List m;
    hashTable Table;
    Table.size = 98215;
    word def;
    def.key = "da";
    def.definition = "aga";
    Table.push_back(def);
    /*
    m.addElem(3);
    m.addElem(4);
    cout << m.get(2);
     */
    return 0;
}
