// 1707. Maximum XOR With an Element From Array
// You are given an array nums consisting of non-negative integers. You are also given a queries array, where queries[i] = [xi, mi].

// The answer to the ith query is the maximum bitwise XOR value of xi and any element of nums that does not exceed mi. In other words, the answer is max(nums[j] XOR xi) for all j such that nums[j] <= mi. If all elements in nums are larger than mi, then the answer is -1.

// Return an integer array answer where answer.length == queries.length and answer[i] is the answer to the ith query.
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
    bool empty;
    TrieNode* root;

    Trie(){
        this->root = new TrieNode();
        this->empty = true;
    }

    void insert(int num){
        TrieNode* node = root;

        for(int i=31;i>=0;i--){
            int bitVal = num & (1<<i) ? 1 : 0;

            if(node->bits[bitVal] == NULL)
                node->bits[bitVal] = new TrieNode();
            
            node = node->bits[bitVal];
        }

        empty = false;
    }

    int maxXor(int k){
        TrieNode* node = root;
        int maxi = 0;

        for(int i=31;i>=0;i--){
            int bitVal = k & (1<<i) ? 1 : 0;

            if(node->bits[!bitVal]){
                maxi |= (1<<i);
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int q = queries.size(), n=nums.size();
        vector<vector<int>> offlineQueries;

        for(int i=0;i<q;i++)
            offlineQueries.push_back({queries[i][1],queries[i][0],i});
        
        sort(offlineQueries.begin(),offlineQueries.end());
        sort(nums.begin(),nums.end());

        Trie T;
        vector<int> res(q);
        int i=0;
        for(auto& oq : offlineQueries){
            int m = oq[0], x = oq[1], idx = oq[2];

            while(i<n && nums[i]<=m)
                T.insert(nums[i++]);
            
            res[idx] = T.empty ? -1 : T.maxXor(x);
        }

        return res;
    }
};