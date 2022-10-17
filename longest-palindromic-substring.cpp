class Solution {
public:
    int dp[1001][1001];
    int length;
    
    int getCount(int start, int len, string& s) {
        if (dp[start][len] != -1) return dp[start][len];
        if (len == 1) return 1;
        if (len == 2)
            return dp[start][len] = (s[start] == s[start+1] ? 1 : 0);
        
        if (s[start] != s[start+len-1])
            dp[start][len] = 0;
        else
            dp[start][len] = getCount(start+1, len-2, s);

        return dp[start][len];
    }

    string longestPalindrome(string s) {
        int length = s.size();
        memset(dp, -1, sizeof(dp));
        
        string maxPal;
        int maxPalLen = -1;
        for (int i=0; i<length; i++) {
            for (int j=1; i+j<=length; j++) {
                int isPal = getCount(i,j,s);
                if (isPal && j > maxPalLen) {
                    maxPalLen = j;
                    maxPal = s.substr(i, j);
                }
            }
        }
        
        return maxPal;
    }
};