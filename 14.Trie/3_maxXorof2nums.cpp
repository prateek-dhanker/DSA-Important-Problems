#include <bits/stdc++.h>
using namespace std;

class TrieNode{
public:
    vector<TrieNode*> bits;

    TrieNode(){
        bits.resize(2,NULL);
    }
};
class Trie{
public:
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    void insert(int num){
        TrieNode* node = root;

        for(int i=31;i>=0;i--){
            int bitVal = num & (1<<i) ? 1 : 0;

            if(node->bits[bitVal]==NULL)
                node->bits[bitVal] = new TrieNode();
            
            node = node->bits[bitVal];
        }
    }

    int maxXor(int k){
        TrieNode* node = root;
        int maxi = 0;

        for(int i=31;i>=0;i--){
            int bitVal = k & (1<<i) ? 1 : 0;

            if(node->bits[!bitVal]){
                maxi |=  (1<<i);
                node = node->bits[!bitVal];
            }
            else
                node = node->bits[bitVal];
        }

        return maxi;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        for(int n:nums)
            T.insert(n);
        

        int maxi = 0;
        for(int n:nums)
            maxi = max(maxi,T.maxXor(n));

        return maxi;
    }
};