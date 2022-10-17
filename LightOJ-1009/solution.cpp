#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

#define MAX 20010

int set[MAX];
vector<int> adjList[MAX];

void dfs(int v, int *memberCount) {
  int parentSet = set[v];
  for (int i = 0; i < adjList[v].size(); i++) {
    int curr = adjList[v][i];
    if (set[curr] == -1) {
      set[curr] = !parentSet;
      memberCount[!parentSet]++;
      dfs(curr, memberCount);
    }
  }
}

int getMaxRace(int root) {
  int memberCount[2] = {};
  set[root] = 0;
  memberCount[0]++;

  dfs(root, memberCount);
  return max(memberCount[0], memberCount[1]);
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  int t;
  cin>>t;

  for (int i=1; i<=t; i++) {
    memset(set, -1, sizeof set);
    for (int j=0; j<MAX; j++)
      adjList[j].clear();

    int n, u, v;
    cin>>n;

    for (int j = 0; j < n; j++) {
      cin>>u>>v;
      adjList[u].push_back(v);
    }

    int maxGroup = 0;
    for (int j = 1; j <= MAX; j++) {
      if (set[j] == -1 && !adjList[j].empty()) {
        int mx = getMaxRace(j);
        maxGroup += mx;
      }
    }
    cout<<"Case "<<i<<": "<<maxGroup<<endl;
  }
}