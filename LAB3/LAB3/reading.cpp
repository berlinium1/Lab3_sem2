//
//  reading.cpp
//  LAB3
//
//  Created by Anatoliy Khramchenko on 16.03.2021.
//

#include "reading.hpp"

void readingFile (string teka) {
    ///Users/khramchenko/Desktop/Reps/Lab3_sem2/files/dict_processed.txt
    ifstream inFile;
    inFile.open(teka);
    string line;
    string word;
    string explanation;
    while (!inFile.eof()) {
        getline(inFile,line);
        int i;
        for (i = 0; line[i] != ';'; i++) {
            word = word + line[i];
        }
        explanation = line.substr(i+1,line.size());
        cout << word << endl;
    }
}
