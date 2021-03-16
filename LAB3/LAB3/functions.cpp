//
//  functions.cpp
//  LAB3
//

#include "functions.hpp"

int Table::getHash(string word){
    int hash = 0;
    for(int i = 0; i < word.size(); i++){
        hash = (31 * hash + static_cast<int>(word[i])) % 98215;
    }
    return hash;
}
