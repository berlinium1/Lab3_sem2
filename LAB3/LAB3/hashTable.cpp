//
//  hashTable.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 16.03.2021.
//

#include "hashTable.hpp"


hashTable::hashTable(){
};

int hashTable::generateHash(string word){
        int hash = 0;
        for(int i = 0; i < word.size(); i++){
            hash = (31 * hash + static_cast<int>(word[i])) % 98215;
        }
        return hash;
}
/*
word hashTable::find(word term){
    int index = generateHash(term.key);
    return linkedList[index].get(index);
}
*/

void hashTable::push_back(word definition){
    int generatedHash = generateHash(definition.key);
    if (linkedList[generatedHash].firstElem.value.key == "") {
        linkedList[generatedHash].addFirstElem(definition);
    }
    else{
        linkedList[generatedHash].addElem(definition);
    }
}


void hashTable::output(){
    for (int i = 0; i < size; i++) {
        if (linkedList[i].firstElem.value.key != "") {
            int counter = 0;
            while (counter<linkedList[i].number) {
                cout<<"Key is: "<<linkedList[i].get(counter).key<<endl;
                cout<<"Definition is "<<linkedList[i].get(counter).definition<<endl;
                counter++;
            }
            counter = 0;
        }
        else{
        }
    }
}

void hashTable::find(string term){
    int currentHash = generateHash(term);
    if (linkedList[currentHash].firstElem.value.key == "") {
        cout<<"This dictionary doesn't contain the word you've asked\n";
    }
    else{
        int counter = 0;
        while (counter<linkedList[currentHash].number) {
            if (linkedList[currentHash].get(counter).key == term) {
                cout<<"Definition is: "<<linkedList[currentHash].get(counter).definition<<endl;
                break;
            }
            else counter++;
            }
            counter = 0;
        }
    
};
