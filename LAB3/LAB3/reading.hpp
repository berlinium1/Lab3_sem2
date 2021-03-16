//
//  reading.hpp
//  LAB3
//
//  Created by Anatoliy Khramchenko on 16.03.2021.
//

#ifndef reading_hpp
#define reading_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "structures.hpp"
#include "hashTable.hpp"
using namespace std;

void readingFile (string teka, hashTable *mas, int *size);
void toLittle (string *);
string readingCons ();

#endif /* reading_hpp */
