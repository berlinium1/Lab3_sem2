//
//  reading.cpp
//  LAB3
//
//  Created by Anatoliy Khramchenko on 16.03.2021.
//

#include "reading.hpp"

void toLittle (string *s) {
    string sdop;
    sdop = *s;
    for (int i=0; i<sdop.size(); i++) {
        sdop[i] = sdop[i] + 32;
    }
    *s = sdop;
}

void readingFile (string teka, hashTable *mas) {
    ///Users/khramchenko/Desktop/Reps/Lab3_sem2/files/dict_processed.txt
    hashTable res;
    ifstream inFile;
    inFile.open(teka);
    string line;
    word word;
    while (!inFile.eof()) {
        word.key="";
        getline(inFile,line,'\n');
        int i;
        for (i = 0; line[i] != ';'; i++) {
            word.key = word.key + line[i];
        }
        word.definition = line.substr(i+1,line.size());
        toLittle(&word.key);
        res.push_back(word);
    }
    *mas = res;
}
