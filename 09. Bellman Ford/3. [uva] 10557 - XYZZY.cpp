// Problem: 10557 - XYZZY
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
// 
// Complextiy: O(N^4), N <= 100

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// check if have path from src to dst
// O(E + V) = O(M + N)
bool bfs(vector<vector<int>>& graph, int n, int src, int dst) {
    vector<bool> visited(n, false);

    queue<int> q;
    q.push(src);
    visited[src] = true;

    int u, v;
    while (!q.empty()) {
        u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            v = graph[u][i];

            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return visited[dst];
}

// O(E*V) = O(M*N), M <= N(N-1)/2 = O(N^2 * N) = O(N^3)
bool bellmanFord(vector<vector<int>>& graph, int n, vector<int>& energy, int s) {
    vector<int> dist(n, -1);
    dist[s] = 100;

	// O(E*V) = O(M*N), M <= N(N-1)/2 = O(N^2 * N) = O(N^3)
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < graph.size(); u++) {
            for (int j = 0; j < graph[u].size(); j++) {
                int v = graph[u][j];
                int w = energy[v];
                // have energy and have better room for energy
                if (dist[u] > 0 && dist[u] + w > dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }

    // can enter to last room
    if (dist[n - 1] >= 0)
        return true;

    // detect positive cycle
	// O(E * (E + V)) = O(M * (M + N)), M <= N(N-1)/2 = O(N^4), N <= 100 -> This is complexity of this solution
    for (int u = 0; u < graph.size(); u++) {
        for (int j = 0; j < graph[u].size(); j++) {
            int v = graph[u][j];
            int w = energy[v];
            if (dist[u] > 0 && dist[u] + w > dist[v]) {
                if (bfs(graph, n, u, n - 1))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    while (true) {
        cin >> n;
        if (n == -1)
            break;

        vector<int> energy(n);
        vector<vector<int>> graph(n);

        int j;
        for (int i = 0; i < n; i++) {
            cin >> energy[i] >> m;
            while (m--) {
                cin >> j;
                graph[i].push_back(j - 1);
            }
        }

        cout << (bellmanFord(graph, n, energy, 0) ? "winnable" : "hopeless") << endl;
    }
}

// Standard
#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 1e9 + 7;

int n, m;
bool visited[MAX];
int dist[MAX], energy[MAX];
vector<pair<int, int>> graph;

bool hasPathBFS(int s, int f) {
    fill(visited, visited + (n + 1), false);
    queue<int> q;
    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (pair<int, int> &edge : graph) {
            if (edge.first == u) {
                int v = edge.second;

                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);

                    if (v == f) {
                        return true;
                    }
                }
            }
        }        
    }
    return false;
}

bool BellmanFord(int s, int f) {
    fill(dist, dist + (n + 1), -INF);
    dist[1] = 100;

    for (int i = 0; i < n - 1; i++) {
        for (pair<int, int> &edge : graph) {
            int u = edge.first;
            int v = edge.second;
            if (dist[u] > 0) {
                dist[v] = max(dist[v], dist[u] + energy[v]);
            }
        }
    }

    for (pair<int, int> &edge : graph) {
        int u = edge.first;
        int v = edge.second;
        if (dist[u] > 0 && dist[u] + energy[v] > dist[v] && hasPathBFS(u, f)) {
            return true;
        }
    }

    return dist[f] > 0;
}

int main() {
    int v;

    while (cin >> n, n != -1) {
        graph.clear();

        for (int u = 1; u <= n; u++) {
            cin >> energy[u] >> m;
            
            for (int i = 0; i < m; i++) {
                cin >> v;
                graph.push_back(make_pair(u, v));
            }
        }

        bool canGo = BellmanFord(1, n);
        cout << (canGo ? "winnable" : "hopeless") << endl;
    }
    return 0;
}

// Python
import queue
INF = 10 ** 9
energy = [0] * 105

class Edge:
    def __init__(self, _source, _target):
        self.source = _source
        self.target = _target

def hasPathBFS(s, f):
    visited = [False] * (n + 1)
    q = queue.Queue()
    q.put(s)
    visited[s] = True

    while not q.empty():
        u = q.get()

        for edge in graph:
            if edge.source == u:
                v = edge.target

                if not visited[v]:
                    visited[v] = True
                    q.put(v)
                
                if v == f:
                    return True
    
    return False

def BellmanFord(s, f):
    dist = [-INF] * (n + 1)
    dist[1] = 100

    for i in range(n - 1):
        for edge in graph:
            u = edge.source
            v = edge.target
            if dist[u] > 0:
                dist[v] = max(dist[v], dist[u] + energy[v])
    
    for edge in graph:
        u = edge.source
        v = edge.target
        if dist[u] > 0 and dist[u] + energy[v] > dist[v] and hasPathBFS(u, f):
            return True
    
    return dist[f] >0
            
while True:
    n = int(input())
    if n == -1:
        break
    
    graph = []

    for u in range(1, n + 1):
        line = list(map(int, input().split()))
        energy[u] = line.pop(0)

        if not line:    # input could be ill-formated
            line.extend(list(map(int, input().split())))

        m = line.pop(0)

        while len(line) != m:
            line.extend(list(map(int, input().split())))
        
        for v in line:
            graph.append(Edge(u, v))
        
    canGo = BellmanFord(1, n)
    print("winnable" if canGo else "hopeless")