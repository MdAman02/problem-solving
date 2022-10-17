#include<iostream>
using namespace std;

int main() {
	// freopen("input.txt", "r", stdin);
	int t;
	cin>>t;

	while(t--) {
		int n,l,r;
		cin>>n>>l>>r;

		int sol[n+1];
		bool hasRes = true;
		for (int i = 1; i<=n; i++) {
			int rem = l%i;
			sol[i] = l + (rem ? (i-rem) : 0);
			if (sol[i] > r) {
				hasRes = false;
				break;
			}
		}
		cout<<(hasRes ? "YES" : "NO")<<endl;
		if (hasRes) {
			for (int i=1; i<=n; i++)
				cout<<sol[i]<<" ";
			cout<<endl;
		}
	}
}
