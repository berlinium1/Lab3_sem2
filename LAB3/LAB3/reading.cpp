//
//  reading.cpp
//  LAB3
//
//  Created by Anatoliy Khramchenko on 16.03.2021.
//

#include "reading.hpp"

void toLittle (string *s) { //функция которая меняет все буквы на строчные
    string sdop;
    sdop = *s;
    for (int i=0; i<sdop.size(); i++) {
        if ((sdop[i]>=65) && (sdop[i]<=90)) {
            sdop[i] = sdop[i] + 32;
        }
    }
    *s = sdop;
}

string readingCons () { //функция чтения с консоли
    string sentence;
    getline(cin,sentence);
    toLittle(&sentence);
    return sentence;
}

void readingFile (string teka, hashTable *mas) { //функция считывания словаря
    hashTable res;
    int count = 0;
    ifstream inFile;
    inFile.open(teka);
    string line;
    word word;
    int i = 0;
    if (inFile.is_open()) {
        while (!inFile.eof()) {
            if (res.is_overloaded()) {   // если таблица переполнена, открываем файл по новой
                inFile.close();
                inFile.open(teka);
                res.clear();    // очищаем указатели на старые значения
                res.resize();   // пересобираем таблицу
            }
            i++;
            count++;
            word.key="";
            getline(inFile,line,'\n'); //читаем строку
            int i;
            for (i = 0; line[i] != ';'; i++) {
                word.key = word.key + line[i]; //то что до запятой - ключ
            }
            word.definition = line.substr(i+1,line.size()); //то что после - описание
            toLittle(&word.key);
            res.push_back(word); //добавляем в таблицу
        }
        inFile.close();
    }
    else {
        cout << "File couldn't be opened\n";
    }
    *mas = res;
}
