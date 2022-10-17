// Sparse Graph

#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define INF 1e9

struct Edge
{
	int u,v,w;
	Edge(int a, int b, int c) {
		u = a, v = b, w = c;
	}
	bool operator<(const Edge& a) const {
		return w < a.w;
	}
};

vector<Edge> MstPrims(vector<Edge>* adjList, int numOfNodes) {
	vector<bool> selected(numOfNodes+1,0);
	set<Edge> minEdges;
	vector<int> minWeight(numOfNodes+1, INF);

	int startingNode = 1;
	minEdges.insert(Edge(0, startingNode, 0));

	vector<Edge> MST;
	for (int i=0; i<numOfNodes; i++) {
		Edge currEdge = *(minEdges.begin());
		minEdges.erase(minEdges.begin());
		int currNode = currEdge.v;

		selected[currNode] = true;
		if (currNode != startingNode) {
			MST.push_back(currEdge);
		}

		for (auto it = adjList[currNode].begin(); it != adjList[currNode].end(); it++) {
			Edge to = *it;
			if (!selected[to.v] && minWeight[to.v] > to.w) {
				minEdges.erase(Edge(to.u, to.v, minWeight[to.v] ));
				minEdges.insert(to);
				minWeight[to.v] = to.w;
			}
		}
	}

	return MST;
}

int main() {
	freopen("input.txt", "r", stdin);

	int numberOfNodes, numEdges;
	cin>>numberOfNodes>>numEdges;

	vector<Edge> adjList[numberOfNodes+1];

	int u,v,w;
	for (int i=0; i<numEdges; i++) {
		cin>>u>>v>>w;
		adjList[u].push_back(Edge(u,v,w));
		adjList[v].push_back(Edge(v,u,w));
	}

	vector<Edge> MST = MstPrims(adjList, numberOfNodes);
	cout<<MST.size()<<endl;
	for (auto it = MST.begin(); it != MST.end(); it++)
		cout<<it->u<<" -> "<<it->v<<" : "<<it->w<<endl;
}
