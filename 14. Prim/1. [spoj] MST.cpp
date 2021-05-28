// Problem: MST - Minimum Spanning Tree
// Link: https://www.spoj.com/problems/MST/


#include <iostream>
#include <queue>

#define INF 1e9
#define MAX 10000
using namespace std;

void prim(vector<vector<pair<int, int>>>& graph, int src, vector<int>& dist) {
	int n = graph.size();
	vector<int> visited(n, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		int u = top.second;
		visited[u] = true;

		for (int i = 0; i < graph[u].size(); i++) {
			pair<int, int> neighbor = graph[u][i];
			int v = neighbor.second;
			int w = neighbor.first;

			if (!visited[v] && w < dist[v]) {
				dist[v] = w;
				pq.push(make_pair(w, v));
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> graph(n);
	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		u--;
		v--;
		graph[u].push_back(make_pair(w, v));
		graph[v].push_back(make_pair(w, u));
	}

	vector<int> dist(n, INF);
	prim(graph, 0, dist);

	long long total = 0;
	for (int i = 0; i < n; i++) {
		total += (long long) dist[i];
	}

	cout << total << endl;

	return 0;
}

//St
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 7;

int N, M;
bool visited[MAX];
int dist[MAX];
vector<pair<int, int>> graph[MAX];

long long Prim(int s) {
    fill(dist, dist + (N + 1), INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        for (pair<int, int> &neighbor : graph[u]) {
            int v = neighbor.second;
            int w = neighbor.first;

            if (!visited[v] && w < dist[v]) {
                dist[v] = w;
                pq.push(make_pair(w, v));
            }
        }
    }

    long long res = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            continue;
        }
        res += dist[i];
    }
    return res;
}

int main() {
    int u, v, w;
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(w, v));
        graph[v].push_back(make_pair(w, u));
    }

    cout << Prim(N);
    return 0;
}

//Py
import queue

class Node:
    def __init__(self, dist, index):
        self.dist = dist
        self.index = index
    
    def __lt__(self, other):
        return self.dist < other.dist

def Prim(s):
    dist = [10 ** 9] * (N + 1)
    visited = [False] * (N + 1)
    pq = queue.PriorityQueue()
    pq.put(Node(0, s))
    dist[s] = 0

    while not pq.empty():
        u = pq.get().index
        visited[u] = True

        for neighbor in graph[u]:
            v = neighbor.index
            w = neighbor.dist
            if not visited[v] and w < dist[v]:
                dist[v] = w
                pq.put(Node(w, v))
    
    res = 0
    for i in range(1, N + 1):
        if not visited[i]:
            continue
        res += dist[i]
    return res

N, M = map(int, input().split())
graph = [[] for _ in range(N + 1)]

for _ in range(M):
    u, v, w = map(int, input().split())
    graph[u].append(Node(w, v))
    graph[v].append(Node(w, u))

print(Prim(N))