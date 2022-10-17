#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define max 50010

int yPoints[max];

int main() {
	// freopen("input.txt", "r", stdin);

	int t;
	cin>>t;

	for (int c = 1; c<=t; c++) {
		long n,w,x,y;
		cin>>n>>w;

		for (int i=0; i<n; i++) {
			cin>>x>>y;
			yPoints[i] = y;
		}

		sort(yPoints, yPoints+n);
		long pointerY = yPoints[0], coveredY = -10000000010, res = 0;
		
		for (int i=0; i<n; i++) {
			if (yPoints[i] <= coveredY) continue;
			res++;
			coveredY = yPoints[i] + w;
		};
		cout<<"Case "<<c<<": "<<res<<endl;
	}
}
