#include<iostream>
#include "trie.h"

using namespace std;

int main(){
    Trie* trie = new Trie();
    trie->insert("abc");
    bool isExist = trie->search("ab");
    bool isStartsWith = trie->startsWith("ab");

    cout<<"is exist: "<<isExist<<endl;
    cout<<"is start with: "<<isStartsWith<<endl;

    return 0;
}
