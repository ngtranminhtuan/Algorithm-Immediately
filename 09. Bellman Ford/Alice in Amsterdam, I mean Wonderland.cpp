#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const long long INF = (1LL << 30) * 100 + 7;		// Should be large enough

struct Edge {
    int source, target;
    long long weight;
};

int n;
long long dist[MAX][MAX];
string monuments[MAX];
vector<Edge> graph;

void BellmanFord(int s) {
    dist[s][s] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (Edge &edge : graph) {
            int u = edge.source;
            int v = edge.target;
            long long w = edge.weight;
            if (dist[s][u] != INF && dist[s][u] + w < dist[s][v]) {
                dist[s][v] = dist[s][u] + w;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (Edge &edge : graph) {
            int u = edge.source;
            int v = edge.target;
            long long w = edge.weight;
            if (dist[s][u] != INF && dist[s][u] + w < dist[s][v]) {
                dist[s][v] = -INF;
            }
        }
    }
}

int main() {
    int q, u, v, tc = 1;
    long long w;

    while (cin >> n, n != 0) {
        graph.clear();

        for (int i = 0; i < n; i++) {
            cin >> monuments[i];           
            for (int j = 0; j < n; j++) {
                cin >> w;
                dist[i][j] = INF;
                if (i != j && w == 0) {
                    continue;
                }
                if (i == j && w >= 0) {
                    w = 0;
                }
                graph.push_back((Edge) {i, j, w});
            }
        }

        for (int i = 0; i < n; i++) {
            BellmanFord(i);
        }

        cin >> q;
        cout << "Case #" << tc++ << ":" << endl;
        while (q--) {
            cin >> u >> v;
            if (dist[u][v] <= -INF) {		// Be careful here
                cout << "NEGATIVE CYCLE" << endl;
            }
            else {
                cout << monuments[u] << "-" << monuments[v] << " ";
                if (dist[u][v] != INF) {
                    cout << dist[u][v] << endl;
                }
                else {
                    cout << "NOT REACHABLE" << endl;
                }
            }
        }
    }
    return 0;
}

// Python
INF = (1 << 30) * 100 + 7     # Should be large enough

def BellmanFord(s):
   dist[s][s] = 0

   for i in range(n - 1):
      for edge in graph:
         u, v, w = edge
         if dist[s][u] != INF and dist[s][u] + w < dist[s][v]:
            dist[s][v] = dist[s][u] + w

   for i in range(n - 1):
      for edge in graph:
         u, v, w = edge
         if dist[s][u] != INF and dist[s][u] + w < dist[s][v]:
            dist[s][v] = -INF

tc = 1
while True:
   n = int(input())
   if n == 0:
      break

   monuments = []
   graph = []
   dist = [[INF] * n for _ in range(n)]

   for i in range(n):
      name, *weights = input().split()
      monuments.append(name)
      for j in range(n):
         w = int(weights[j])
         if i != j and w == 0:
            continue
         if i == j and w >= 0:
            w = 0
         graph.append((i, j, w))

   for i in range(n):
      BellmanFord(i)

   print('Case #{}:'.format(tc))
   tc += 1
   q = int(input())

   for _ in range(q):
      u, v = map(int, input().split())
      if dist[u][v] <= -INF:		# Be careful here
         print('NEGATIVE CYCLE')
      else:
         print('{}-{} {}'.format(monuments[u], monuments[v], 'NOT REACHABLE' if dist[u][v] == INF else dist[u][v]))