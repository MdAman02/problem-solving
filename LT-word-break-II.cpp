class Solution {
public:
    unordered_set<string> dict;
    int n;
    vector<vector<string>> mem;
    vector<int> dp;
    string inp;
    
    int checkSuffix(int start) {
        if (dp[start] != -1) return dp[start];
        if (start == n) return 1;
        
        string tmp = "";
        bool isAnyValid = false;
        for (int i=start; i<n; i++) {
            tmp += inp[i];
            int isValid = dict.count(tmp);
            int suffixValid = checkSuffix(i+1);
            if (isValid && suffixValid) {
                isAnyValid = true;
                if (i == n-1)
                    mem[start].push_back(tmp);
                else {
                    for (int j=0; j<mem[i+1].size(); j++)
                        mem[start].push_back(tmp + " " + mem[i+1][j]);
                }
            }
        }
        return dp[start] = isAnyValid;
    }
        
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        inp = s;
        for (int i=0; i<wordDict.size(); i++)
            dict.insert(wordDict[i]);
        dp.resize(n+1, -1);
        mem.resize(n+1);
        
        checkSuffix(0);
        return mem[0];
    }
};