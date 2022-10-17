#include <iostream>
#include<string>
using namespace std;

#define MAX 100000

bool flag[10000010];

string sieve(long n) {
	string prime = "2";
	for (int i=3; i*i<=n; i+=2) {
		if (flag[i]) continue;
		for (int j=3; i*j <= n ; j+=2)
			flag[i*j] = true;
	}
	for (int i=3; i<=n; i+=2)
		if (!flag[i])
			prime += to_string(i);

	return prime;
}

void solution(int n) {
	string res = "";
	string primeString = sieve(MAX);
	for (int i=n; i<n+5; i++)
		res += primeString[i];
	cout<<res<<endl;
}

int main() {
	int n;

	while(1) {
		cin>>n;
		solution(n);
		// cout<<solution(n)<<endl;;		
	}
}