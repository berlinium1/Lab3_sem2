//
//  hashTable.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 16.03.2021.
//

#include "hashTable.hpp"


hashTable::hashTable(){
    linkedList = new List[size];
};

int hashTable::generateHash(string word){
        int hash = 0;
        for(int i = 0; i < word.size(); i++){
            hash = (31 * hash + static_cast<int>(word[i])) % 98215;
        }
        return hash;
}

word hashTable::find(word term){
    int index = generateHash(term.key);
    return linkedList[index].get(index);
}


void hashTable::push_back(word definition){
    int generatedHash = generateHash(definition.key);
    linkedList[generatedHash].addElem(definition);
}
