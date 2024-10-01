#include<iostream>
#include<unordered_map>
using namespace std;

struct trieNode{
    unordered_map<char, trieNode*> children;
    bool wordCompleted;

    trieNode(){
        wordCompleted = false;
    }
};

class Trie{
    public: 
        trieNode* root;

        Trie(){
            root = new trieNode();
        }

        void insert(string word);
        bool search(string word);
};

void Trie::insert(string word){
    trieNode* currNode = root;
    int wordLen = word.size();

    for(int i = 0; i < wordLen; i++){
        if(currNode->children.count(word[i]) == 0){
            currNode->children[word[i]] = new trieNode();
        }
        currNode = currNode->children[word[i]];
    }

    currNode->wordCompleted = true;
}

bool Trie::search(string word){
    trieNode* currNode = root;
    int wordLen = word.size();

    for(int i = 0; i < wordLen; i++){
        if(currNode->children.count(word[i]) == 0){
            return false;
        }
        currNode = currNode->children[word[i]];
    }

    return currNode->wordCompleted;
}


int main(){
    int numberWords, numberSearches;
    cin>>numberWords;

    Trie myTrie;

    string word;
    for(int i = 0; i < numberWords; i++){
        cin>>word;
        //cout << word << endl;
        myTrie.insert(word);
    } 

    cin>>numberSearches;

    for(int i = 0; i < numberSearches; i++){
        cin>>word;
        cout << myTrie.search(word) << endl;
    } 

    return 0;
}

