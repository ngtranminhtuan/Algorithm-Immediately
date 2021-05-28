// Problem: TRAFFICN - Traffic Network
// Link: https://www.spoj.com/problems/TRAFFICN/en/


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;
#define MAX 10001
#define INF 100000*1000 + 1000 + 1 // length of m one-way roads + length of proposed two-way road + 1

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

    int T;
    cin >> T;

    int n, m, k, s, t;
    int a, b, w;
    while (T--) {
        cin >> n >> m >> k >> s >> t;

        vector<vector<pair<int, int>>> graph(n + 1);
        vector<vector<pair<int, int>>> graph2(n + 1);
        vector<int> dist(n + 1, INF);
        vector<int> dist2(n + 1, INF);

        // one-way road
        while (m--) {
            cin >> a >> b >> w;
            graph[a].push_back(make_pair(w, b)); // for find shortest path from start point to other points
            graph2[b].push_back(make_pair(w, a)); // reverse path for find shortest path from destinate point to other points
        }

        dijikstra(s, graph, dist); // find shortest path from start point to other points
        dijikstra(t, graph2, dist2); // find shortest path from destinate point to other points

        // proposed two-way road
        int ans = INF;
        while (k--) {
            cin >> a >> b >> w;

            // check path: s -> a -> b -> t
            if (dist[a] != INF && dist2[b] != INF) {
                ans = min(ans, dist[a] + w + dist2[b]);
            }

            // check path: s -> b -> a -> t
            if (dist[b] != INF && dist2[a] != INF) {
                ans = min(ans, dist[b] + w + dist2[a]);
            }
        }

        // path from s -> t: don't choose from proposed two-way road
        if (dist[t] != INF)
            ans = min(ans, dist[t]);

        cout << (ans == INF ? -1 : ans) << endl;
    }

    return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 7;
 
vector<pair<int, int>> graphS[MAX], graphT[MAX];
int distS[MAX], distT[MAX];
 
void Dijkstra(int s, int dist[], vector<pair<int, int>> (&graph)[MAX]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
     
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
         
        int u = top.second;
        int w = top.first;
         
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
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T, n, m, k, s, t, u, v, d;
    cin >> T;
     
    while (T--) {
        cin >> n >> m >> k >> s >> t;
         
        for (int i = 1; i <= n; i++) {
            graphS[i].clear();
            graphT[i].clear();
            distS[i] = INF;
            distT[i] = INF;
        }
         
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> d;
            graphS[u].push_back(make_pair(d, v));
            graphT[v].push_back(make_pair(d, u));
        }
         
        Dijkstra(s, distS, graphS);
        Dijkstra(t, distT, graphT);
        int res = distS[t];
         
        for (int i = 0; i < k; i++) {
            cin >> u >> v >> d;
            int a = distS[u] + d + distT[v];
            int b = distS[v] + d + distT[u];
            res = min(res, min(a, b));
        }
         
        cout << (res != INF ? res : -1) << endl;
    }
    return 0;
}

// Python
from heapq import heappush, heappop
INF = 10 ** 9
MAX = 10001
 
def Dijkstra(s, dist, graph):
    pq = [(0, s)]
    dist[s] = 0
     
    while pq:
        w, u = heappop(pq)
         
        if w > dist[u]:
            continue
         
        for weight, v in graph[u]:
            if w + weight < dist[v]:
                dist[v] = w + weight
                heappush(pq, (dist[v], v))
 
T = int(input())
 
for _ in range(T):
    n, m, k, s, t = map(int, input().split())
     
    graphS = [[] for _ in range(MAX)]
    graphT = [[] for _ in range(MAX)]
    distT = [INF] * MAX
    distS = [INF] * MAX
     
    for i in range(m):
        u, v, d = map(int, input().split())
        graphS[u].append((d, v))
        graphT[v].append((d, u))
     
    Dijkstra(s, distS, graphS)
    Dijkstra(t, distT, graphT)
    res = distS[t]
     
    for i in range(k):
        u, v, d = map(int, input().split())
        res = min(res, distS[u] + d + distT[v], distS[v] + d + distT[u])
     
    print(res if res != INF else -1)