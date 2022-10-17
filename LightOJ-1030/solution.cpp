#include<bits/stdc++.h>
using namespace std;

#define MAX 110

int n;
int gold[MAX];
double dp[MAX];

double expGoldFromPos(int pos) {
  if (dp[pos] != -1)
    return dp[pos];
  if (pos == n) {
    dp[pos] = gold[pos];
    return dp[pos];
  }

  double res = gold[pos];
  int validNumOfSides = (n-pos < 6)? n-pos: 6;
  for (int i = pos+1; i<=n && i - pos < 7; i++) {
    res += (1.00/validNumOfSides) * expGoldFromPos(i);
  }
  dp[pos] = res;
  return dp[pos];
}

int main() {
  freopen("input.txt", "r", stdin);
  // freopen("ouput.txt", "w", stdout);

  int t;
  cin>>t;

  for (int c = 1; c<=t; c++) {
    memset(gold, -1, sizeof gold);
    for (int i=0 ; i<MAX; i++)
      dp[i] = -1;

    cin>>n;
    for (int i = 1; i <= n; i++)
      cin>>gold[i];

    cout<<"Case "<<c<<": "<<expGoldFromPos(1)<<endl;
  }
}
