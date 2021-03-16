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

void readingFile (string teka) {
    ///Users/khramchenko/Desktop/Reps/Lab3_sem2/files/dict_processed.txt
    ifstream inFile;
    inFile.open(teka);
    string line;
    string word;
    string explanation;
    while (!inFile.eof()) {
        word="";
        getline(inFile,line,'\n');
        int i;
        for (i = 0; line[i] != ';'; i++) {
            word = word + line[i];
        }
        explanation = line.substr(i+1,line.size());
        toLittle(&word);
        cout << word << endl;
    }
}
