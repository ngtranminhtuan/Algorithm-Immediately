// Solution: 1074 - Extended Traffic
// Link: http://lightoj.com/volume_showproblem.php?problem=1074

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

bool bellmanFord(vector<Edge>& graph, int n, vector<int>& dist, int s) {
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

int cube(int x) {
    return x*x*x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n, m, q;
    int src, dst;
    vector<Edge> graph;
    for (int x = 1; x <= T; x++) {
        graph.clear();

        cin >> n;
        vector<int> busyness(n);
        for (int i = 0; i < n; i++) {
            cin >> busyness[i];
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> src >> dst;
            src--;
            dst--;
            graph.push_back((Edge){src, dst, cube(busyness[dst] - busyness[src])});
        }

        vector<int> dist(n, INF);
        bool hasNegativeCycle = bellmanFord(graph, n, dist, 0);

        cin >> q;

        cout << "Case " << x << ":" << endl;
        for (int i = 0; i < q; i++) {
            cin >> dst;
            dst--;

            if (dist[dst] < 3 || dist[dst] == INF) {
                cout << "?" << endl;
            } else {
                cout << dist[dst] << endl;
            }
        }
    }
}

// Standard
#include <bits/stdc++.h>
#define MAX_V 205
#define MAX_E 205 * 204
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int source, target, weight;
};

int n, m;
int weight[MAX_V];
int dist[MAX_V];
Edge graph[MAX_E];

void BellmanFord(int s) {
    fill(dist, dist + (n + 1), INF);
    dist[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF) {
                dist[v] = min(dist[v], dist[u] + w);
            }
        }
    }
  
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = -INF;
            }
        }
    }
}

int main() {
    int T, q, u, v, f;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> weight[i];
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            graph[i] = (Edge) {u, v, int(pow(weight[v] - weight[u], 3))};
        }

        BellmanFord(1);
        cin >> q;
        cout << "Case " << t << ":" << endl;

        for (int i = 0; i < q; i++) {
            cin >> f;

            if (dist[f] != INF && dist[f] >= 3) {
                cout << dist[f] << endl;
            }
            else {
                cout << "?" << endl;
            }
        }
    }
    return 0;
}

// Python
INF = 10 ** 9

class Edge:
    def __init__(self, _source, _target, _weight):
        self.source = _source
        self.target = _target
        self.weight = _weight

def BellmanFord(s):
    dist[s] = 0
    for i in range(n - 1):
        for edge in graph:
            u, v, w = edge.source, edge.target, edge.weight

            if dist[u] != INF:
                dist[v] = min(dist[v], dist[u] + w)
    
    for i in range(n):
        for e in graph:
            u, v, w = e.source, e.target, e.weight
            if dist[u] != INF and dist[v] > dist[u] + w:
                dist[v] = -INF

T = int(input())

for t in range(1, T + 1):
    input()
    n = int(input())
    weight = [0] + list(map(int, input().split()))
    m = int(input())
    
    graph = []
    dist = [INF] * (n + 1)

    for _ in range(m):
        u, v = map(int, input().split())
        graph.append(Edge(u, v, (weight[v] - weight[u]) ** 3))
    
    BellmanFord(1)
    q = int(input())
    print("Case {}:".format(t))

    for _ in range(q):
        f = int(input())
        print(dist[f] if dist[f] != INF and dist[f] >= 3 else "?")