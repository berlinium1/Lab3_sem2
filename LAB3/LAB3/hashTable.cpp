//
//  hashTable.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 16.03.2021.
//

#include "hashTable.hpp"


hashTable::hashTable(){
};
///при генерации хеша лучше учитывать умножение на простое число, что делает полученные хеши более разнообразными
int hashTable::generateHash(string word){
        int hash = 0;
        for(int i = 0; i < word.size(); i++){
            hash = (31 * hash + static_cast<int>(word[i])) % 98215;
        }
        return hash;
}

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
        cout<<"The word ["<<term<<"] couldn't be found it the dictionary\n";
        cout<<"Your hash is "<<currentHash<<endl;
    }
    else{
        int counter = 0;
        bool flag = 0;
        /// двигаемся в конец списка
        while (counter<linkedList[currentHash].number) {
            if (linkedList[currentHash].get(counter).key == term) {
                cout<<linkedList[currentHash].get(counter).key<<";"<<linkedList[currentHash].get(counter).definition<<endl;
                flag = 1;
                break;
            }
            else counter++;
            }
        ///  для случая, если хеш оказался одинаковым, но слово найдено не было среди остальных
        if (flag == 0) {
            cout<<"The word ["<<term<<"] couldn't be found it the dictionary\n";
            cout<<"Your hash is "<<currentHash<<endl;
        }
        }
    
};

void hashTable::calculateColisions(){
        int array[size];
        int max = array[0];
        int sum = 0;
        for (int i = 0; i < size; i++) {
            array[i] = linkedList[i].number;
            //cout<<array[i]<<endl;
            if (array[i] > max) {
                max = array[i];
            }
            sum += array[i];
        }
    cout<<"Max is "<<max<<endl;        
}
