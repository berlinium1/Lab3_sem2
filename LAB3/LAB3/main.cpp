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
#include "reading.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    hashTable table;
    string path;
    cout<<"To start searching determinations You should give me a path to a dictionary-file\n";
    getline(cin, path);
    readingFile(path, &table);
    string userSentense;
    vector<string> userSentenseWords; // контейнер для ввёденных пользователем слов
    
    do {
        cout<<"Enter your sentense or just a phrase please: ";
        getline(cin, userSentense);
        userSentenseWords = getWordFromSentense(userSentense);
        for (int i = 0; i<userSentenseWords.size(); i++) {
            toLittle(&userSentenseWords[i]);  // переводим слово в малый регистр(для удобства)
            table.find(userSentenseWords[i]);  // находим слово в таблице
        }
    } while (userSentense != "");

    //table.output();  // вывести таблицу
    table.calculateColisions();   // вывести макс. количество коллизий на один список среди списков таблицы
    cout<<"Size of table is: "<<table.getSize()<<endl;
    return 0;
}

//   /Users/khramchenko/Desktop/Reps/Lab3_sem2/files/dict_processed.txt
//   /Users/yaroslav/Desktop/LABTODAY/Lab3_sem2/files/dict_processed.txt
