//
//  functions.cpp
//  LAB3
//

#include "functions.hpp"



vector<string> getWordFromSentense(string strIn){
    vector<string> result;
    int index = 0;
    string s = "";
    string separator = ",. :;";
    while (index<strIn.length()) {
        bool flag = 0;
        for (int j = 0; j<separator.size(); j++) {
            if (strIn[index] == separator[j]) {
                flag = 1;
            }
        }
        if (flag) {
            if (s!="") {
                result.push_back(s);
            }
            s = "";
            flag = 0;
            index++;
        }
        else{
            s += strIn[index];
            index++;
        }
        if (index==strIn.size()) {
            bool isSep = 0;
            for (int i = 0; i<separator.size(); i++) {
                if (strIn[index] == separator[i]) {
                    isSep = 1;
                }
            }
            if (isSep) {
                break;
            }
            else if(s!=""){
                result.push_back(s);
                break;
            }
        }
    }
    return result;
}
