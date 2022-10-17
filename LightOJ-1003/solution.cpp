#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define MAX 10010

vector<int> adjList[MAX];
int visited[MAX];
map<string, int> nodeIndex;
int nodeCount;

bool hasCycleInGraph(int n) {
  visited[n] = 1;

  for (int i=0; i<adjList[n].size(); i++) {
    int v = adjList[n][i];
    if (!visited[v])
      if (hasCycleInGraph(v)) return true;
    if (visited[v] == 1) return true;
  }

  visited[n] = 2;
  return false;
}

bool hasCycle() {
  for (int i=1; i<=nodeCount; i++) {
    if (!visited[i]) {
      if (hasCycleInGraph(i))
        return true;
    }
  }

  return false;
}

int main() {
  // freopen("input.txt", "r", stdin);

  int t;
  cin>>t;

  for (int c = 1; c<=t; c++) {
    for (int i=0; i<MAX; i++) {
      adjList[i].clear();
      visited[i] = 0;
    }
    nodeIndex.clear();
    nodeCount = 0;

    int m;
    string a,b;
    cin>>m;

    for (int i=0; i<m; i++) {
      cin>>a>>b;
      if (nodeIndex[a] == 0) nodeIndex[a] = ++nodeCount;
      if (nodeIndex[b] == 0) nodeIndex[b] = ++nodeCount;

      adjList[nodeIndex[a]].push_back(nodeIndex[b]);
    }

    cout<<"Case "<<c<<": "<<(hasCycle()? "No": "Yes")<<endl;
  }
}