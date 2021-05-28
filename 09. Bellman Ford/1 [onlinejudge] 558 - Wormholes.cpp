// Solution: 558 - Wormholes
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=499

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;
#define INF INT_MAX

struct Edge {
    int source;
    int target;
    int weight;
};

bool bellmanFord(vector<Edge>& graph, int n, int s) {
    vector<int> dist(n, INF);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < graph.size(); j++) {
            Edge& edge = graph[j];

            int u = edge.source;
            int v = edge.target;
            int w = edge.weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
				if (i == n - 1) // detect negative cycle
					return true;
				
				dist[v] = dist[u] + w;
            }
        }
    }
	
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    int n, m;
    int x, y, t;
    vector<Edge> graph;
    while (c--) {
        graph.clear();

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            graph.push_back((Edge){x, y, t});
        }

        bool hasNegativeCycle = bellmanFord(graph, n, 0);
        cout << (hasNegativeCycle ? "possible" : "not possible") << endl;
    }
}

// Python
INF = 10 ** 9

class Edge:
    def __init__(self, _source, _target, _weight):
        self.source = _source
        self.target = _target
        self.weight = _weight

def BellmanFord(s):
    dist = [INF] * n
    dist[s] = 0

    for i in range(n - 1):
        for j in range(len(graph)):
        # for edge in graph:
            edge = graph[j]
            u, v, w = edge.source, edge.target, edge.weight
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
    
    for j in range(len(graph)):
        # for edge in graph:
        edge = graph[j]
    # for edge in graph:
        u, v, w = edge.source, edge.target, edge.weight
        if dist[u] != INF and dist[u] + w < dist[v]:
            return False
    
    return True


T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    graph = []

    for i in range(m):
        x, y, t = map(int, input().split())
        graph.append(Edge(x, y, t))
    
    print("possible" if not BellmanFord(0) else "not possible")