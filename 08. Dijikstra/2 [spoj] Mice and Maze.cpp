// Problem: MICEMAZE - Mice and Maze
// Link: https://www.spoj.com/problems/MICEMAZE/


#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;
#define MAX 101
#define INF INT_MAX

vector<vector<pair<int, int>>> graph(MAX);
vector<int> dist(MAX, INF);

void dijikstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int w = top.first;

        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
            int v = neighbor.second;

            if (w + neighbor.first < dist[v]) {
                dist[v] = w + neighbor.first;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main() {
    int n, e, t, m;
    cin >> n >> e >> t >> m;

    int a, b, w;
    while (m--) {
        cin >> a >> b >> w;
        graph[b].push_back(make_pair(w, a)); // reverse path for finding shortest path from end cell to other cells
    }

    dijikstra(e); // finding shortest path from end cell to other cells

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= t) {
            ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

// Standard Code
#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 1e9 + 7;
 
vector<vector<pair<int, int>>> graph;
vector<int> dist(MAX, INF);
 
void Dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(s, 0));
    dist[s] = 0;
 
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
 
        int u = top.first;
        int w = top.second;
 
        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.second < dist[neighbor.first]) {
                dist[neighbor.first] = w + neighbor.second;
                pq.push(make_pair(neighbor.first, dist[neighbor.first]));
            }
        }
    }
}
 
int main() {
    int N, E, T, M;
    int u, v, w;
    cin >> N >> E >> T >> M;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
 
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[v].push_back(make_pair(u, w));
    }
 
    Dijkstra(E);
 
    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (dist[i] <= T) {
            count++;
        }
    }
 
    cout << count;
    return 0;
}

// ----------
import queue
MAX = 105
INF = int(1e9) + 7
graph = [[] for _ in range(MAX)]
dist = [INF for _ in range(MAX)]
 
class Node:
    def __init__(self, _id, _weight):
        self.id = _id
        self.weight = _weight
     
    def __lt__(self, other):
        return self.weight < other.weight
 
def Dijkstra(s):
    pq = queue.PriorityQueue()
    pq.put(Node(s, 0))
    dist[s] = 0
 
    while not pq.empty():
        top = pq.get()
        u = top.id
        w = top.weight
 
        for neighbor in graph[u]:
            if w + neighbor.weight < dist[neighbor.id]:
                dist[neighbor.id] = w + neighbor.weight
                pq.put(Node(neighbor.id, dist[neighbor.id]))
 
N = int(input())
E = int(input())
T = int(input())
M = int(input())
for _ in range(M):
    u, v, w = map(int, input().split())
    graph[v].append(Node(u, w))
 
Dijkstra(E)
 
count = 0
for i in range(1, N + 1):
    if dist[i] <= T:
        count += 1
 
print(count)