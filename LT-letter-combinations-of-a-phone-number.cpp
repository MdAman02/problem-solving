// Time Complexity: k^n
// Space: Constant + O(n)

#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    Solution() {
        if (digitsMap[2] == "") {
            digitsMap[2] = "abc";
            digitsMap[3] = "def";
            digitsMap[4] = "ghi";
            digitsMap[5] = "jkl";
            digitsMap[6] = "mno";
            digitsMap[7] = "pqrs";
            digitsMap[8] = "tuv";
            digitsMap[9] = "wxyz";
        }
    }
    static map<int, string> digitsMap;
    void generate(vector<string>& store, string& digits, int currPos, string& currString) {
        if (currPos >= digits.size())
            return store.push_back(currString);

        int currDigit = digits[currPos] - '0';
        for (int i=0; i<digitsMap[currDigit].size(); i++) {
            currString[currPos] = digitsMap[currDigit][i];
            generate(store, digits, currPos+1, currString);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits == "") return res;
        generate(res, digits, 0, string(digits.size(), 'x'));
        return res;
    }
};

map<int,string> Solution::digitsMap;

int main() {
    Solution sol;
    vector<string> r = sol.letterCombinations("257");
    for (int i=0 ; i<r.size(); i++)
        cout<<r[i]<<endl;
}
