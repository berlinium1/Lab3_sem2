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

using namespace std;

int main(int argc, const char * argv[]) {
    List m;
    hashTable Table;
    word def;
    def.key = "da";
    def.definition = "aga";
    Table.push_back(def);
    m.addFirstElem(def);
    m.addElem(def);
    cout<<m.get(1).definition;
    int size = 98215;
    
    List *wds = new List[2];
    
    word fw;
    fw.key = "one";
    fw.definition = "first";
    wds[0].addFirstElem(fw);
    cout<<wds[0].get(0).key<<endl;
    cout<<wds[0].get(0).definition<<endl;
    
    word sw;
    sw.key = "two";
    sw.definition = "second";
    wds[0].addFirstElem(fw);
    cout<<wds[0].get(0).key<<endl;
    cout<<wds[0].get(0).definition<<endl;
    
    word tw;
    tw.key = "three";
    tw.definition = "third";
    wds[1].addFirstElem(fw);
    cout<<wds[0].get(0).key<<endl;
    cout<<wds[0].get(0).definition<<endl;
    
    word fow;
    fow.key = "four";
    fow.definition = "fourth";
    wds[1].addFirstElem(fw);
    cout<<wds[0].get(0).key<<endl;
    cout<<wds[0].get(0).definition<<endl;
    
    
    
    
    /*
    
    List *arr = new List[size];
    for (int i = 0; i<2; i++) {
        for (int j = 0; j<2; j++) {
            word key;
            cout<<j<<"] ENTER A key: ";
            cin>>key.key;
            cout<<j<<"] ENTER A definition: ";
            cin>>key.definition;
            if (arr[i].firstElem.pointer == NULL) {
                arr[i].addFirstElem(key);
            }
            else{
                arr[i].addElem(key);
            }
            cout<<endl;
        }
    }
    
    for (int i = 0; i<2; i++) {
        for (int j = 0; j<2; j++) {
            cout<<"key: "<<arr[i].get(j).key;
            cout<<"def: "<<arr[i].get(j).definition;
            cout<<endl;
        }
    }
     */
    /*
    m.addElem(3);
    m.addElem(4);
    cout << m.get(2);
     */
    return 0;
}
