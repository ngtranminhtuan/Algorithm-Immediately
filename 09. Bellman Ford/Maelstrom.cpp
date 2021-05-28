#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
 
struct Edge {
    int source, target, weight;
};
 
void BellmanFord(int s, int n, vector<int> &dist, vector<Edge> &graph) {
    dist[s] = 0;
     
    for (int i = 0; i < n - 1; i++) {
        for (Edge edge : graph) {
            int u = edge.source;
            int v = edge.target;
            int w = edge.weight;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
}
 
int main() {
    int n;
    string temp;
    cin >> n;
    vector<Edge> graph;
    vector<int> dist(n + 1, INF);
 
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            cin >> temp;
 
            if (temp != "x") {
                int w = atoi(temp.c_str());
                graph.push_back({i, j, w});
                graph.push_back({j, i, w});
            }
        }
    }
 
    BellmanFord(1, n, dist, graph);
     
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, dist[i]);
    }
    cout << res;
 
    return 0;
}

// PYthon
def BellmanFord(s, n, dist, graph):
    dist[s] = 0
 
    for i in range(n - 1):
        for edge in graph:
            u, v, w = edge
            dist[v] = min(dist[v], dist[u] + w)
 
n = int(input())
dist = [10 ** 9] * (n + 1)
graph = []
 
for i in range(2, n + 1):
    line = input().split()
 
    for j in range(1, i):
        if line[j - 1] != 'x':
            w = int(line[j - 1])
            graph.append((i, j, w))
            graph.append((j, i, w))
 
BellmanFord(1, n, dist, graph)
 
res = 0
for i in range(1, n + 1):
    res = max(res, dist[i])
print(res)