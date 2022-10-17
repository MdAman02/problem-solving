class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> rating;
    int n;
    
    int getTeams(int p, int cnt, bool increasing) {
        if (dp[p][cnt][increasing] != -1)
            return dp[p][cnt][increasing];
        if (cnt == 1) return 1;
        if (p == n-1) return 0;
        
        int res = 0;
        for (int i=p+1; i<n; i++) {
            if ((rating[i] > rating[p]) == increasing) {
                res += getTeams(i, cnt-1, increasing);                
            }
        }
        return dp[p][cnt][increasing] = res;
    }
    
    int numTeams(vector<int>& rating) {
        n = rating.size();
        this->rating = rating;
        dp.resize(n, vector<vector<int>>(4, vector<int>(2, -1)));
        
        int res = 0;
        for (int i=0; i<n; i++) {
            res += getTeams(i, 3, true);
            res += getTeams(i, 3, false);
        }
        return res;
    }
};