#include<iostream>
#include<cmath>
#include<set>
using namespace std;

#define MAX 1000000
#define MOD 1000000000


set<int> blockCells[MAX];

long bigMod(long base, int exp) {
  if (exp == 0) return 1;
  if (exp == 1) return base%MOD;

  return ( bigMod(base, (exp+1)/2) * bigMod(base, exp/2) ) % MOD;
}

pair<int, int> calculateExponent(int rows, int colNo, int numBlockCells) {
  int maxColor = 0, maxColorMinus1 = 0;
  int blockCells = 0, colorableSegments = 0, lastBlockPointer;

  for (int i=0; 
    i<numBlockCells; i++) {
    // if (blockCells[i][1] != colNo) continue;
    // if () 
  }

  return make_pair(maxColor, maxColorMinus1);
}


long solution(int row, int col, int numColors, int numBlockCells) {
  long res = 1;
  for (int i = 0; i < col; ++i) {
    pair<int, int> exp = calculateExponent(row, i, numBlockCells);

    cout<<"calculated: "<<exp.first<<" "<<exp.second<<endl;
    res *= ( bigMod(numColors, exp.first) * bigMod(numColors-1, exp.second) ) % MOD; 
  }

  return res;
}

int main() {
  freopen("input.txt", "r", stdin);

  // int n, b;
  // cin<<" "<< n >> b;
  // for (int i=0; i<b; i++) {
  //   cin>>blockCells[i][0]>>blockCells[i][1];
  // }

  // pair<int, int> t = calculateExponent(n, 1, b);
  // cout<<t.first<<" "<<t.second<<endl;

  int t, X, Y;
  cin>>t;
  while(t--) {

    int row, col, numColors, numBlockCells;
    cin >> row >> col >> numColors >> numBlockCells;

    for (int i=0; i<=col; i++)
      blockCells[i] = new set<int>(); 

    for (int i=0; i<numBlockCells; i++) {
      cin>>X>>Y;
      blockCells[Y].insert(X);
    }

    cout<<"case: "<<endl;
    for (int i=1; i<=col; i++) {
      cout<<i<< " : size: "<<blockCells[i].size()<<endl;
      for (auto it = blockCells[i].begin(); it != blockCells[i].end(); it++) {
        cout<<*it<<" ";
      }
      cout<<endl;
    }
    //cout<<"Case "<<t+1<<": "<<solution(row, col, numColors, numBlockCells)<<endl;
  }

}
