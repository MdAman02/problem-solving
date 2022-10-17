#include<iostream>
#include<cstring>
using namespace std;

#define MASK 20

// 5th node -> maxLt * count()

class Solution {
public:
    Solution() {
        cout<<"const"<<endl;
        memset(dp, -1, sizeof(dp));
    }
    int dp[20][100000];
    
    int getCount(int maxLt, int maxRt) {
    }

    int numTrees(int n) {
        int res = 0;
        for (int i=1; i<=n; i++);
        return res;
    }
};

int main() {
    int n;
    cin>>n;
    Solution sol;
    int res = sol.numTrees(n);
    cout<<res<<endl;
}
