#include<map>
#include<iostream>

class Solution {
  map<char, int> val;

public:
  Solution() {
    val['I'] = 1;
    val['V'] = 5;
    val['X'] = 10;
    val['L'] = 50;
    val['C'] = 100;
    val['D'] = 500;
    val['M'] = 1000;
  }
  int romanToInt(string s) {
    int size = s.size();
    int res = 0;

    for (int i=0; i<size; i++) {
      if (i == size-1) {
        res += val[s[i]];
        continue;
      }
      if (s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X') ) {
        res += val[s[i+1]] - val[s[i]];
        i++;
        continue;
      }
      if (s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')) {
        res += val[s[i+1]] - val[s[i]];
        i++;
        continue;
      }
      if (s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')) {
        res += val[s[i+1]] - val[s[i]];
        i++;
        continue;
      }
      res += val[s[i]];
    }

    return res;
  }
};
