#include<iostream>
#include<cstring>
using namespace std;

int binaryDigits[35], length;
long long dp[35][3][3];
int validNumCount[35][3][3];

long long compute(int pos, int d, int is_already_smaller) {
  if (dp[pos][d][is_already_smaller] != -1)
    return dp[pos][d][is_already_smaller];
  if (pos == length) {
    validNumCount[pos][d][is_already_smaller] = 1;
    dp[pos][d][is_already_smaller] = 0;
    return 0;
  }

  long long adjBits, adjBitsInCurrPos;
  if (is_already_smaller) {
    adjBits = compute(pos+1, 0, is_already_smaller) + compute(pos+1, 1, is_already_smaller);

    validNumCount[pos][d][is_already_smaller] =
      validNumCount[pos+1][0][is_already_smaller] + validNumCount[pos+1][1][is_already_smaller];
    adjBitsInCurrPos = d == 1? validNumCount[pos+1][1][is_already_smaller]: 0;

    dp[pos][d][is_already_smaller] = adjBits + adjBitsInCurrPos;
  } else {
    if (binaryDigits[pos+1] == 1) {
      adjBits = compute(pos+1, 0, 1) + compute(pos+1, 1, 0);
      validNumCount[pos][d][is_already_smaller] =
        validNumCount[pos+1][0][1] + validNumCount[pos+1][1][0];
      adjBitsInCurrPos = d==1? validNumCount[pos+1][1][0]: 0;

      dp[pos][d][is_already_smaller] = adjBits + adjBitsInCurrPos;
    } else {
      dp[pos][d][is_already_smaller] = compute(pos+1, 0, 0);
      validNumCount[pos][d][is_already_smaller] = validNumCount[pos+1][0][0];
    }
  }
  return dp[pos][d][is_already_smaller];
}

int getDigits(int n) {
  int digits[35], cnt = 0;
  if (n == 0) digits[++cnt] = 0;
  while (n>0) {
    digits[++cnt] = n % 2;
    n = n/2;
  }
  for (int j = cnt; j>0; j--)
    binaryDigits[cnt - j +1 ] = digits[j];
  return cnt;
}

int main() {
  int t;
  cin>>t;

  for (int c = 1; c<=t; c++) {
    memset(dp, -1, sizeof(dp));
    memset(validNumCount, -1, sizeof(validNumCount));

    int n;
    cin>>n;

    length = getDigits(n);

    cout<<"Case "<<c<<": "<<compute(1, 0, 1) + compute(1, 1, 0)<<endl;
  }
}
