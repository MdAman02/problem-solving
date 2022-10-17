#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;

#define MAX 2*100010

bool isBipartite(vector<int> *adjList, int numOfNodes, int* whichSet) {
	queue<int> q;

	q.push(1);
	whichSet[1] = 0;
	while(!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i<adjList[curr].size(); i++) {
			int to = adjList[curr][i];
			if (whichSet[to] == whichSet[curr])
				return false;
			if (whichSet[to] == -1) {
				q.push(to);
				whichSet[to] = !whichSet[curr];
			}
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	// freopen("input.txt", "r", stdin);

	int whichSet[MAX];
	memset(whichSet, -1, sizeof(whichSet));

	int n,m,u,v;
	cin>>n>>m;

	vector<int> adjList[n+1];
	int edges[m][2];
	for (int i=0; i<m; i++) {
		cin>>u>>v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
		edges[i][0] = u, edges[i][1] = v;
	}

	bool isValid = isBipartite(adjList, n, whichSet);
	cout<<(isValid ? "YES" : "NO")<<endl;
	if (isValid) {
		for (int i=0; i<m; i++) {
			u = edges[i][0], v = edges[i][1];
			cout<<whichSet[u];
		}
		cout<<endl;
	}
	return 0;
}
