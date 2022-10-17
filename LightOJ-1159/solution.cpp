#include<iostream>
#include<algorithm>
using namespace std;

#define MAX 60

int dir[][3] = {
  { 0, 0, 1 },
  { 0, 1, 0 },
  { 0, 1, 1 },
  { 1, 0, 0 },
  { 1, 0, 1 },
  { 1, 1, 0 },
};

int memo[MAX][MAX][MAX];
string x, y, z;
int sizeX, sizeY, sizeZ;

int lcs(int i, int j, int k) {
  if (memo[i][j][k] != -1)
    return memo[i][j][k];

  if (sizeX < i || sizeY < j || sizeZ < k)
    return memo[i][j][k] = 0;

  if (x[i] == y[j] && x[i] == z[k]) {
    memo[i][j][k] = 1 + lcs(i+1, j+1, k+1);
    return memo[i][j][k];
  }

  int maxLength = -1;
  for (int p=0; p<6; p++) {
    int l = lcs(i+dir[p][0], j+dir[p][1], k+dir[p][2]);
    maxLength = max(maxLength, l);
  }

  return memo[i][j][k] = maxLength;
}

int main () {
  // freopen("input.txt", "r", stdin);
  int t;
  cin>>t;

  for (int c = 1; c<=t; c++) {
    for (int i=0; i<MAX; i++)
      for (int j=0; j<MAX; j++)
        for (int k=0; k<MAX; k++)
          memo[i][j][k] = -1;

    cin>>x>>y>>z;
    sizeX = x.size()-1; sizeY = y.size()-1; sizeZ = z.size()-1;
    cout<<"Case "<<c<<": "<<lcs(0,0,0)<<endl;
  }
  return 0;
}