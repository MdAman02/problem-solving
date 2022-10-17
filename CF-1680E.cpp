#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 2*100010
#define MAX_VAL 1e9

int dp[MAX][2];
int cost[MAX][2];
int firstChipCol, lastChipCol;

// solution to subproblem from 0th column to `col` where last chip stands at row `row`
int solution(int col, int row) {
	if (dp[col][row] != -1)
		return dp[col][row];
	if (col == firstChipCol) {
		dp[col][row] = cost[col][!row];
		return dp[col][row];
	}

	int sameRow = solution(col-1, row) + 1 + cost[col][!row];
	int diffRow = solution(col-1, !row) + 2;
	dp[col][row] = min(sameRow, diffRow);
	return dp[col][row];
}

int main() {
	// freopen("input.txt", "r", stdin);

	int t;
	cin>>t;

	while(t--) {
		memset(dp, -1, sizeof(dp));
		firstChipCol = MAX_VAL, lastChipCol = -1;

		int n;
		cin>>n;

		string s1, s2;
		cin>>s1>>s2;
		for (int i=0; i<n; i++) {
			if (s1[i] == '*' || s2[i] == '*') {
				firstChipCol = min(firstChipCol, i);
				lastChipCol = max(lastChipCol, i);
			}
			cost[i][0] = s1[i] == '*';
			cost[i][1] = s2[i] == '*';
		}
		cout<<min(solution(lastChipCol, 0), solution(lastChipCol, 1))<<endl;
	}
}
