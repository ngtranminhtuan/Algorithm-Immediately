// Problem: SHPATH - The Shortest Path
// Link: https://www.spoj.com/problems/SHPATH/en/


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <limits.h>

using namespace std;
#define INF 200001

unordered_map<string, int> mapNameToIndex;

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

    int s, n, p;

    cin >> s;
    int i, j, w;
    string name;

    while (s--) {
        cin >> n;

        vector<vector<pair<int, int>>> graph(n);
        for (i = 0; i < n; i++) {
            cin >> name;
            mapNameToIndex[name] = i;
            cin >> p;

            while (p--) {
                cin >> j >> w;
                --j;
                graph[i].push_back(make_pair(w, j));
            }
        }

        int r;
        cin >> r;
        string src, dst;
        while (r--) {
            cin >> src >> dst;
            vector<int> dist(n, INF);

            int srcIndex = mapNameToIndex[src];
            int dstIndex = mapNameToIndex[dst];
            dijikstra(srcIndex, graph, dist);

            if (dist[dstIndex] < INF) {
                cout << dist[dstIndex] << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}


// Standard Code
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;
const int INF = 1e9 + 7;
 
vector<pair<int, int>> graph[MAX];
vector<int> dist(MAX, INF);
vector<string> cities;
 
int getIndex(string name) {
    for (int i = 0; i < cities.size(); i++) {
        if (name == cities[i]) {
            return i;
        }
    }
    return -1;
}
 
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
 
        for (pair<int, int> &neighbor : graph[u]) {
            if (w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.second], neighbor.second));
            }
        }
    }
}
 
int main() {
    int T, N, Q;
    int neighbors, u, v, w;
    string name, sCity, fCity;
    cin >> T;
 
    while (T--) {
        cin >> N;
         
        for (int i = 1; i <= N; i++) {
            graph[i].clear();
        }
        cities.clear();
         
        for (int u = 1; u <= N; u++) {
            cin >> name >> neighbors;
            cities.push_back(name);
 
            for (int i = 0; i < neighbors; i++) {
                cin >> v >> w;
                graph[u].push_back(make_pair(w, v));
            }
        }
 
        cin >> Q;
 
        for (int i = 0; i < Q; i++) {
            cin >> sCity >> fCity;
            int s = getIndex(sCity) + 1;
            int f = getIndex(fCity) + 1;
            dist = vector<int>(N + 1, INF);
            Dijkstra(s, f);
            cout << dist[f] << endl;
        }
    }
    return 0;
}

// Python
from heapq import heappush, heappop
 
def Dijkstra(s, f):
    dist = [10 ** 9] * (N + 1)
    pq = [(0, s)]
    dist[s] = 0
     
    while pq:
        w, u = heappop(pq)
         
        if u == f:
            break
         
        for weight, v in graph[u]:
            if w + weight < dist[v]:
                dist[v] = w + weight
                heappush(pq, (dist[v], v))
     
    return dist[f]
     
T = int(input())
 
for t in range(T):
    N = int(input())
    graph = [[] for i in range(N + 1)]
    cities = []
     
    for u in range(1, N + 1):
        name = input()
        cities.append(name)
        neighbors = int(input())
         
        for i in range(neighbors):
            v, w = map(int, input().split())
            graph[u].append((w, v))
     
    Q = int(input())
     
    for i in range(Q):
        sCity, fCity = input().split()
        s = cities.index(sCity) + 1
        f = cities.index(fCity) + 1
        print(Dijkstra(s, f))
     
    input()