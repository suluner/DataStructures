#ifndef TRIE_H
#define TRIE_H

using namespace std;

class TrieNode {
    public:
        TrieNode* children[26];
        bool isWord;
        TrieNode() {
            memset(children, NULL, sizeof(children));
            isWord = false;
        }

        ~TrieNode() {
            for(int i=0; i<26; i++){
                if(children[i]){
                    delete children[i];
                    children[i]=NULL;
                }
            }
        }
};

class Trie {
    TrieNode* root;
    public:
        Trie() {
            root = new TrieNode();
        }

        ~Trie() {
            delete root;
        }

        void insert(string word) {
            TrieNode* pNode = root;
            for(int i=0; i<word.size(); i++){
                if(pNode->children[word[i]-'a'] == NULL){
                    pNode->children[word[i]-'a'] = new TrieNode();
                }
                pNode = pNode->children[word[i]-'a'];
            }
            pNode->isWord = true;
        }

        bool search(string word){
            TrieNode* pNode = root;
            for(int i=0; i<word.size()&&pNode; i++){
                pNode = pNode->children[word[i]-'a'];
            }
            return pNode&&pNode->isWord;
        }

        bool startsWith(string word){
            TrieNode* pNode = root;
            for(int i=0; i<word.size()&&pNode; i++){
                pNode = pNode->children[word[i]-'a'];
            }
            return pNode;
        }
};

#endif
