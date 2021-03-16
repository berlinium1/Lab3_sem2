//
//  structures.cpp
//  LAB3
//

#include "structures.hpp"


Table::Table(){
    list = new listElement * [size];
    for(int i = 0; i<size; i++){
        list[i] = nullptr;
    }
}


void Table::tableOutput(){
    for (int i=0; i<size; i++) {
        if (list[i] = NULL) {
            cout<<"NULL"<<endl;
        }
    }
}
