#include<iostream>
using namespace std;

#define MAX 1000

long memo[40][1000] = {0};
long fact[1000] = {1};

long nCk(int n, int k) {
  if (k > n) return memo[n][k] = 0;
  if (memo[n][k]) return memo[n][k];

  if (n == k || k == 0) return memo[n][k] = 1;
  if (k == 1) return memo[n][k] = n;

  return memo[n][k] = nCk(n-1, k) + nCk(n-1, k-1);
}


int main() {
  // freopen("input.txt", "r", stdin);
  for (int i=1; i<MAX; i++)
    fact[i] = i*fact[i-1];

  int t;
  cin>>t;

  for (int c = 1; c <= t; c++) {
    int n,k;
    cin>>n>>k;
    cout<<"Case "<<c<<": "<<nCk(n,k)*nCk(n,k)*fact[k]<<endl;
  }
}