// Problem: 10986 - Sending email
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
// 

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;
#define MAX 20000
#define INF 200000001

void dijikstra(int s, vector<vector<pair<int, int>>>& graph, vector<int>& dist) {
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int n, m, S, T;
    int s1, s2, w;
    for (int x = 1; x <= N; x++) {
        cin >> n >> m >> S >> T;

        vector<vector<pair<int, int>>> graph(n);
        vector<int> dist(n, INF);

        while (m--) {
            cin >> s1 >> s2 >> w;
            graph[s1].push_back(make_pair(w, s2));
            graph[s2].push_back(make_pair(w, s1));
        }

        dijikstra(S, graph, dist);

        cout << "Case #" << x << ": ";
        if (dist[T] < INF) {
            cout << dist[T] << endl;
        } else {
            cout << "unreachable" << endl;
        }
    }

    return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 20005
using namespace std;
const int INF = 1e9 + 7;
 
int Q;
vector<pair<int, int>> graph[MAX];
int dist[MAX];
 
void Dijkstra(int s, int f) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
     
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
        int u = top.second;
        int w = top.first;
         
        if (u == f) {
            break;
        }
         
        if (w > dist[u]) {
            continue;
        }
         
        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.second], neighbor.second));
            }
        }
    }
}
 
int main() {
    int n, m, S, T, u, v, w;
    cin >> Q;
     
    for (int t = 1; t <= Q; t++) {
        cin >> n >> m >> S >> T;
         
        for (int i = 0; i < n; i++) {
            graph[i].clear();
            dist[i] = INF;
        }
         
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            graph[u].push_back(make_pair(w, v));
            graph[v].push_back(make_pair(w, u));
        }
         
        Dijkstra(S, T);
         
        cout << "Case #" << t << ": ";
         
        if (dist[T] != INF) {
            cout << dist[T] << endl;
        }
        else {
            cout << "unreachable" << endl;
        }
    }
    return 0;
}

// Python
from heapq import heappush, heappop
INF = 10 ** 9 + 7
 
def Dijkstra(s, f):
    global dist
    pq = [(0, s)]
    dist[s] = 0
     
    while pq:
        w, u = heappop(pq)
        if u == f:
            break
         
        if w > dist[u]:
            continue
         
        for weight, v in graph[u]:
            if w + weight < dist[v]:
                dist[v] = w + weight
                heappush(pq, (dist[v], v))
 
Q = int(input())
 
for t in range(1, Q + 1):
    n, m, S, T = map(int, input().split())
    graph = [[] for _ in range(n)]
     
    for _ in range(m):
        u, v, w = map(int, input().split())
        graph[u].append((w, v))
        graph[v].append((w, u))
     
    dist = [INF] * n
    Dijkstra(S, T)
     
    print('Case #{}: '.format(t), end='')
    print(dist[T] if dist[T] != INF else "unreachable")