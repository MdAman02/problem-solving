// Time Complexity: O(n + q)
// Space Complexity: O(n)

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 100010

int main() {
	// freopen("input.txt", "r", stdin);

	int t;
	cin>>t;

	while(t--) {
		int n,q;
		cin>>n>>q;

		int strength[MAX], firstWinRound[MAX] = {0}, loseRound[MAX] = {0};
		for (int i=1; i<=n; i++)
			cin>>strength[i];
		int head = 1, secHead = 2;
		for (int i=1; i<n; i++, secHead++) {
			// cout<<head<<" "<<secHead<<endl;
			if (strength[head] > strength[secHead]) {
				if (firstWinRound[head] == 0)
					firstWinRound[head] = i;
			} else {
				loseRound[head] = i;
				firstWinRound[secHead] = i;
				head = secHead;
			}
		}

		while(q--) {
			int pos, k;
			cin>>pos>>k;

			int wins = 0;
			if (firstWinRound[pos] == 0 || firstWinRound[pos] > k)
				wins = 0;
			else {
				// cout<<"win "<<firstWinRound[pos]<<" lose "<<loseRound[pos]<<" k "<<k<<endl;
				if (loseRound[pos]) {
					int endRound = min(loseRound[pos]-1, k);
					wins = endRound - firstWinRound[pos] + 1;
				} else {
					wins = k - firstWinRound[pos] + 1;
				}
			}
			cout<<wins<<endl;
		}
	}
}
