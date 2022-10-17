#include<iostream>
#include<vector>
using namespace std;

struct TrieNode {
    struct TrieNode* children[27];
    bool isEndOfWord;
    
    TrieNode() {
        for (int i=0; i<26; i++) {
            children[i] = NULL;
        }
        isEndOfWord = false;
    }
};

class Solution {
public:
    TrieNode* root = new TrieNode();
    vector<int> dp;
    int n ;
    
    void buildTrie(TrieNode* root, vector<string>& listString) {
        TrieNode* parent = root;
        for (int i=0; i<listString.size(); i++) {
            insert(parent, listString[i]);
        }
    }
    
    void insert(TrieNode* root, string& s) {
        TrieNode* lowAns = root;
        for (int i=0; i<s.size(); i++) {
            if (lowAns->children[s[i]-'a'] != NULL)
                lowAns = lowAns->children[s[i]-'a'];
            else
                lowAns = lowAns->children[s[i]-'a'] = new TrieNode();
        }
        lowAns->isEndOfWord = true;
    }
    
    bool search(string s) {
        TrieNode* curr = root;
        for (int i=0 ; i<s.size(); i++) {
            if (!(curr->children[s[i]-'a'])) {
                return false;
            }
            curr = curr->children[s[i]-'a'];
        }
        return curr->isEndOfWord;
    }
    
    bool checkSuffix(int start, string& inp) {
        if (dp[start] != -1) return dp[start];
        if (start == n-1)
            return dp[start] = search(inp.substr(start, 1));
    
        if (search(inp.substr(start, n-start)))
            return dp[start] = true;
        
        for (int i=1; i+start<=n; i++) {
            if (search(inp.substr(start, i))
                && checkSuffix(start+i, inp)
            ) 
                return dp[start] = true;
        }
        return dp[start] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        buildTrie(root, wordDict);
        n = s.size();
        dp.resize(n, -1);
        
        return checkSuffix(0, s);
    }
};

int main() {
    Solution sol;
    string inp = "a";
    vector<string> dict = { "a" };
    bool r = sol.wordBreak(inp, dict);
    cout<<r<<endl;
}
