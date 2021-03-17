//
//  functions.cpp
//  LAB3
//

#include "functions.hpp"



vector<string> getWordFromSentense(string strIn){
    vector<string> result;
    int index = 0;
    string s = "";
    string separator = ",. :;?!";  //массив часто встречающихся сепараторов
    while (index<strIn.length()) {
        bool flag = 0;
        ///наткнулись на сепаратор
        for (int j = 0; j<separator.size(); j++) {
            if (strIn[index] == separator[j]) {
                flag = 1;
            }
        }
        if (flag) {
            ///если следующий элемент тоже оказался сепаратором
            if (s!="") {
                result.push_back(s);
            }
            s = "";
            flag = 0;
            index++;
        }
        ///индекс стоит на симв. литерале, который не входит в сепараторы
        else{
            s += strIn[index];
            index++;
        }
        ///получение слова, находящегося в конце строки
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
