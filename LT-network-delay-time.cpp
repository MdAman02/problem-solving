#include<iostream>
#include<vector>
#include <queue>
using namespace std;

#define INF 1e5
#define f first
#define s second

typedef pair<int,int> pii;

class compare {
public:
    bool operator()(pii a, pii b) {
        return a.s <= b.s;
    }
};

class Solution {
public:
    int nodes, source;
    vector<int> distance, marked;
    vector<vector<pii > > adjList;
    vector<vector<int> > edges;

    void buildAdjList() {
        for (int i=0; i<edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back(make_pair(v,w));
        }
    }

    void dijkstraSparse(int source) {
        priority_queue<pii, vector<pii>, compare> q;
        q.push(make_pair(source, 0));
        distance[source] = 0;
        
        while(!q.empty()) {
            int leastNode = q.top().f;
            q.pop();

            for (int j=0; j<adjList[leastNode].size(); j++) {
                int v = adjList[leastNode][j].f;
                int w = adjList[leastNode][j].s;
                if (distance[v] > distance[leastNode] + w) {
                    distance[v] = distance[leastNode] + w;
                    q.push(make_pair(v,distance[v]));
                }
            }
        }
    }


    void bellmanFord(int source) {
        distance[source] = 0;
        for (int i=1; i<nodes-1; i++) {
            for (int j=0; j<edges.size(); j++) {
                int u = edges[j][0], v = edges[j][1], w = edges[j][2];
                if (distance[v] > distance[u] + w)
                    distance[v] = distance[u] + w;
            }
        }
    }

    void dijkstraDense(int source) {
        distance[source] = 0;

        for (int i=1; i<nodes; i++) {
            int leastNode = -1, minDist = INF;
            for (int j=1; j<nodes; j++)
                if (!marked[j] && minDist > distance[j])
                    leastNode = j, minDist = distance[j];

            if (leastNode == -1) break;
            marked[leastNode] = 1;
            
            for (int j=0; j<adjList[leastNode].size(); j++) {
                int v = adjList[leastNode][j].f, w = adjList[leastNode][j].s;
                if (distance[v] > distance[leastNode] + w)
                    distance[v] = distance[leastNode] + w;
            }
        }
    }
    
    int networkDelayTime(vector<vector<int> >& times, int n, int k) {
        nodes = n+1, source = k;
        distance.resize(nodes, INF);
        marked.resize(nodes, 0);
        adjList.resize(nodes);
        edges = times;
        buildAdjList();

        bellmanFord(k);

        int res = -1;
        for (int i=1; i<nodes; i++)
            if (res < distance[i])
                res = distance[i];
        return (res == INF ? -1 : res);
    }
};

int main() {
}
