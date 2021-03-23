//
//  hashTable.cpp
//  LAB3
//
//  Created by Берлинский Ярослав Владленович on 16.03.2021.
//

#include "hashTable.hpp"


//=====Конструктор
hashTable::hashTable(){
    engagedCells = 0;
    size = 8192;
    linkedList = new List[size];
};

int hashTable::getSize(){
    return size;
}

//=====Генератор хешей=====
///при генерации хеша лучше учитывать умножение на простое число, что делает полученные хеши более разнообразными
int hashTable::generateHash(string word){
        int hash = 0;
        for(int i = 0; i < word.size(); i++){
            hash = (31 * hash + static_cast<int>(word[i])) % size;
        }
        return hash;
}


//====добавить элемент в таблицу====
void hashTable::push_back(word definition){
    int generatedHash = generateHash(definition.key);
    if (linkedList[generatedHash].firstElem.value.key == "") { // если связный список пуст(есть только начальный элемент без ключа) -> ложим сюда
        linkedList[generatedHash].addFirstElem(definition);
        engagedCells++; // увеличиваем к-во занятых ячеек
    }
    else{
        linkedList[generatedHash].addElem(definition); // для случая, если сгенерированный индекс указал на непустой связный список
    }
}

//======Очистить указатели на предыдущие значения=====
void hashTable::clear(){
    for (int i = 0; i < size; i++) {
        if (linkedList[i].firstElem.pointer != NULL){
            linkedList[i].clear();  // очищаем хэш-таблицу
        }
    }
}

//=====Переполнена ли таблица=====
bool hashTable::is_overloaded(){
    bool flag = false;
    double fillIndex = 0.8; // индекс заполнения(80%)
    if ((size*fillIndex) <= engagedCells) {
        flag = true;
    }
    return flag;
}

//======Смена размера======
void hashTable::resize(){
    size *= 2; // удваиваем размер
    linkedList = new List[size]; // выделяем для указателя нужное к-во списков
    engagedCells = 0;  // анаулируем к-во занятых ячеек
}

//======Вывод======
void hashTable::output(){
    int num = 0;
    for (int i = 0; i < size; i++) {
        if (linkedList[i].firstElem.value.key != "") {
            int counter = 0;
            while (counter<linkedList[i].number) {
                cout<<num<<" Key is: "<<linkedList[i].get(counter).key<<endl;
                cout<<" Definition is "<<linkedList[i].get(counter).definition<<endl;
                num++;
                counter++;
            }
            counter = 0;
        }
        else{
        }
    }
}


//======Найти элемент в таблице=====
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


//=======Подсчёт макс. количества коллизий в таблице=====
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
