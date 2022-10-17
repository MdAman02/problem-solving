/*
Solution: 
- For any m = x mod y (y <= x), the highest value of m is n/2-1
- Each number in input array will correspond to one element in permutation of 1 to n
- For any number distinct Ai <= n, we can keep it as is
- For duplicate Ai or Ai > n, we perform mod operations
- In iteration of above numbers, we follow greedy approach. We take the least unassigned value in permutation and check if its possible to convert Ai to it

Time Complexity: O(nlogn)
Space: O(n)
*/

#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

#define MAX 100010

int main() {
	// freopen("input.txt", "r", stdin);

	int t;
	cin>>t;

	while(t--) {
		int n;
		cin>>n;

		int t;
		vector<int>numbers;
		set<int> absentNumbers;
		for (int i=1; i<=n; i++)
			absentNumbers.insert(i);

		for (int i=0; i<n; i++) {
			cin>>t;
			if (t <= n && absentNumbers.find(t) != absentNumbers.end()) {
				absentNumbers.erase(t);					
			} else {
				numbers.push_back(t);
			}
		}

		sort(numbers.begin(), numbers.end());
		
		bool err = false;
		for (int i=0; i<numbers.size(); i++) {
			int lowestNum = *(absentNumbers.begin());
			if ((numbers[i]+1)/2 <= lowestNum) {
				err = true;
				break;
			}
			absentNumbers.erase(lowestNum);
		}

		if (err) cout<<"-1"<<endl;
		else cout<<numbers.size()<<endl;
	}
}
