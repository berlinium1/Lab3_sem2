//
//  main.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 14.03.2021.
//

#include <iostream>
#include "functions.hpp"
#include "structures.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    List m(2);
    m.addElem(3);
    cout << m.get(1);
    return 0;
}