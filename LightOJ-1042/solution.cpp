#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int main() {
  // freopen("input.txt", "r", stdin);
	int t;
	cin>>t;

	for (int c=1; c<=t; c++) {
		long n,res;
    int digitCount[2] = {0};
		cin>>n;
		
    while(n >= 0) {
      int r = n % 2;
      if (!r && digitCount[1] > 0) {
        int cutDigits = digitCount[0] + digitCount[1];
        res = n*(1 << cutDigits) + (1 << cutDigits);
        digitCount[1]--;
        for (int i=0; i<digitCount[1]; i++)
          res += (1 << i);
        break;
      } else {
        digitCount[r]++;
      }
      n /= 2;
    }
    cout<<"Case "<<c<<": "<<res<<endl;
	}	
}
