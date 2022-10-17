#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
using namespace std;

#define MAX 510
#define MAX_PATH 200000000 

vector<pair<int, int>> adjList[MAX];
int minPath[MAX];

class Compare {
public:
  bool operator() (pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
  }
};


void dijkstra(int src) {
  minPath[src] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int> >, Compare> q;
  q.push(make_pair(src, minPath[src]));

  while(!q.empty()) {
    int curr = q.top().first;
    q.pop();

    for (int i = 0; i<adjList[curr].size(); i++) {
      int v = adjList[curr][i].first;
      int w = adjList[curr][i].second;
      if (minPath[v] > max(w, minPath[curr])) {
        minPath[v] = max(w, minPath[curr]);
        q.push(make_pair(v, minPath[v]));
      }
    }
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  int t;
  cin>>t;

  for (int c=1; c<=t; c++) {
    for (int i=0; i<MAX; i++) {
      minPath[i] = 200000000;
      adjList[i].clear();
    }

    int n, m, u, v, w, t;
    cin>>n>>m;

    for (int i=0; i<m; i++) {
      cin>>u>>v>>w;
      adjList[u].push_back(make_pair(v, w));
      adjList[v].push_back(make_pair(u, w));
    }

    cin>>t;
    dijkstra(t);
    cout<<"Case "<<c<<":"<<endl;
    for (int i=0; i<n; i++)
      cout<<(minPath[i] == MAX_PATH? "Impossible": to_string(minPath[i]))<<endl;
  }

  return 0;
}
