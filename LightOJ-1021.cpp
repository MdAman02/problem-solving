// utilize the system of dividing a num by a divisor digit by digit and taking remainder as we did in school
// make dp states based on these
#include <iostream>
#include<cstring>
using namespace std;

#define MAX_REMAINDER 20
#define MAX_MASK_BIT 13

// dp[mask][rem] -> Number of permutaion using digits in positions marked 1 in `mask` that has remainder `rem`  
int dp[1<<MAX_MASK_BIT][MAX_REMAINDER] = {0};
int digits[13];

void solution(int digitLen, int divisor, int base) {
	dp[0][0] = 1;
	for (int mask=0; mask <= (1<<digitLen)-1; mask++) {
		for (int rem=0 ; rem<divisor; rem++) {
			for (int k=0; k<digitLen; k++) {
				if ((mask & (1<<k)) == 0) {
					int changedMask = mask ^ (1<<k);
					int newRem = (rem*base+digits[k])%divisor;
					dp[changedMask][newRem] += dp[mask][rem];
				}
			}
		}
	}
}

int main() {
	// freopen("input.txt", "r", stdin);
	int t;
	cin>>t;

	for (int c = 1; c<= t; c++) {
		memset(dp, 0, sizeof(dp));
		int base,k;
		string num;
		cin>>base>>k;
		cin>>num;

		for (int i=0; i<num.size(); i++) {
			if (num[i] >= '0' && num[i] <= '9')
				digits[i] = num[i] - '0';
			else digits[i] = num[i] - 'A' + 10;
		}
		solution(num.size(), k, base);
		cout<<"Case "<<c<<": "<<dp[(1<<num.size())-1][0]<<endl;
	}	
}
