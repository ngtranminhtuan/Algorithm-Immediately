// Problem: TRVCOST - Travelling cost
// Link: https://www.spoj.com/problems/TRVCOST


#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 501
#define INF 50000

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
    int n;
    cin >> n;

    int a, b, w;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(w, b));
        graph[b].push_back(make_pair(w, a));
    }

    int u, q;
    cin >> u >> q;

    dijikstra(u);

    int v;
    for (int i = 0; i < q; i++) {
        cin >> v;
        if (dist[v] == INF) {
            cout << "NO PATH" << endl;
        } else {
            cout << dist[v] << endl;
        }
    }

    return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 500 + 5
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
    int N, A, B, W;
    cin >> N;
    graph = vector<vector<pair<int, int>>>(MAX, vector<pair<int, int>>());
 
    for (int i = 0; i < N; i++) {
        cin >> A >> B >> W;
        graph[A].push_back(make_pair(B, W));
        graph[B].push_back(make_pair(A, W));
    }
 
    int S, Q, V;
    cin >> S;
    Dijkstra(S);
    cin >> Q;
 
    for (int i = 0; i < Q; i++) {
        cin >> V;
         
        if (dist[V] != INF) {
            cout << dist[V] << endl;
        }
        else {
            cout << "NO PATH" << endl;
        }
    }
 
    return 0;
}

// Python
import queue
MAX = 505
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
for _ in range(N):
    A, B, W = map(int, input().split())
    graph[A].append(Node(B, W))
    graph[B].append(Node(A, W))
 
S = int(input())
Dijkstra(S)
 
Q = int(input())
for _ in range(Q):
    V = int(input())
    print(dist[V] if dist[V] != INF else "NO PATH")
