// Solution: Monk's Business Day
// Link: https://www.hackerearth.com/practice/algorithms/graphs/shortest-path-algorithms/practice-problems/algorithm/monks-business-day/description/
// 
// Summary of question: Find positive of directed graph
// Idea:
//      Step 1: Reverse sign of weight
//      Step 2: Find the negative of directed graph
// Complexity: O(M*N)

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

// Return: True if exist negative cycle, else return false
bool bellmanFord(vector<Edge>& graph, int n, int s) {
    vector<int> dist(n, INF);
    dist[s] = 0;

	// O(E*V) = O(M*N) -> This is complexity of this solution
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

    int t;
    cin >> t;

    int n, m;
    vector<Edge> graph;
    while (t--) {
        graph.clear();

        cin >> n >> m;
        int i, j, c;
        while (m--) {
            cin >> i >> j >> c;
            --i, --j;
            graph.push_back((Edge){i, j, -c}); // reverse sign of weight
        }

        bool hasNegativeCycle = bellmanFord(graph, n, 0);
        cout << (hasNegativeCycle ? "Yes" : "No") << endl;
    }

    return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX_N 105
#define MAX_M 1005
using namespace std;
const int INF = 1e9 + 7;

struct Edge {
    int source, target, weight;
};

int n, m;
int dist[MAX_N];
Edge graph[MAX_M];

bool BellmanFord(int s) {
    fill(dist, dist + (n + 1), INF);
    dist[s] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            int w = graph[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;

                if (i == n - 1) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int T, u, v, w;
    cin >> T;

    while (T--) {
        cin >> n >> m;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[i] = (Edge) {u, v, -w};
        }

        cout << (BellmanFord(1) ? "Yes" : "No") << endl;
    }
    return 0;
}

//PYthon
INF = 10 ** 9

def BellmanFord(s):
    dist = [INF] * (n + 1)
    dist[s] = 0

    for i in range(n):
        for edge in graph:
            u, v, w = edge
            
            if dist[u] != INF and dist[u] + w < dist[v]:
                dist[v] = dist[u] + w
                
                if i == n - 1:
                    return True
    
    return False

T = int(input())

for _ in range(T):
    n, m = map(int, input().split())
    graph = []

    for i in range(m):
        u, v, w = map(int, input().split())
        graph.append((u, v, -w))
    
    print("Yes" if BellmanFord(1) else "No")