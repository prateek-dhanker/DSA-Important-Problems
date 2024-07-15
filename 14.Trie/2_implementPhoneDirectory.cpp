#include <bits/stdc++.h>
using namespace std; 

class TrieNode{
    public:
        char data;
        TrieNode * children[26];
        int childno ;
        bool isTerminal;

        TrieNode(char ch){
            this->data = ch;
            this->childno = 0;
            for(int i= 0 ; i<26;i++)
                this->children[i] = NULL;

            this->isTerminal = false;
        }
};
class Trie {
public:
    TrieNode * root;
    Trie() {
        this->root = new TrieNode('\0');
    }
    
    void insertUtil(TrieNode * root , string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return ;
        }

        int index = word[0] - 'a';
        TrieNode * child;

        if(root->children[index]){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
            root->childno++;
        }
        return insertUtil(child , word.substr(1)); 
    }

    void insert(string word) {
        insertUtil(root , word);
    }
    void printSuggestion(TrieNode *curr , string prefix , vector<string> &temp){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch = 'a' ; ch <='z' ; ch++){
            if(curr->children[ch-'a']){
                prefix.push_back(ch);
                printSuggestion(curr->children[ch-'a'] , prefix , temp);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestion(string &queryStr){
        vector<vector<string>> ans;
        string prefix = "";
        TrieNode *prev = root;

        for(int i=0;i<queryStr.length() ; i++){
            char prevchar  = queryStr[i];
            int index = prevchar - 'a';
            prefix.push_back(prevchar);

            TrieNode * curr  = prev->children[index];
            if(curr){
                vector<string> temp;
                printSuggestion(curr , prefix , temp);
                ans.push_back(temp);
                prev = curr;
            }
            else
                break;
        }
        return ans;
    }
    
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.;
    Trie *t = new Trie;

    for(string s :contactList){
        t->insert(s);
    }

    vector<vector<string>>ans = t->getSuggestion(queryStr);

    return ans;
  
}