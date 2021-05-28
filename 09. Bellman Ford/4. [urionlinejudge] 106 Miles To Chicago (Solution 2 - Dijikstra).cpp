// Solution: 106 Miles To Chicago
// Link: https://www.urionlinejudge.com.br/judge/en/problems/view/1655
// 
// Summary of problem: Find the longest path of the undirected graph, don't have negative cycle
// Complexity: O(N^2LogN)

#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

#define INF 2
typedef pair<double, int> pdi;

// O(ELogV) = O(MLogN) = O(N^2LogN) -> this complexity of this solution
double dijikstra(const vector<vector<pdi>>& graph, int n, int s) {
    vector<double> dist(n, -INF);
    priority_queue<pdi> pq; // max-heap
    dist[s] = 1;
    pq.push(make_pair(dist[s], s));

    while (!pq.empty()) {
        pdi top = pq.top();
        pq.pop();
        int u = top.second;

        for (int i = 0; i < graph[u].size(); i++) {
            pdi neighbor = graph[u][i];
            int v = neighbor.second;
            double w = neighbor.first;

            if (w * top.first > dist[v]) {
                dist[v] = w * top.first;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    return dist[n - 1];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	while (true) {
		cin >> n >> m;
		if (n == 0)
			break;

		vector<vector<pdi>> graph(n);
		int a, b, p;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> p;
			--a, --b;

			// Each street can be used in both directions
			graph[a].push_back(make_pair(p / 100.0f, b));
			graph[b].push_back(make_pair(p / 100.0f, a));
		}

		cout << fixed << setprecision(6) << (dijikstra(graph, n, 0) * 100.0f) << " percent" << endl;
	}

	return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX_N 100 + 5
#define MAX_M 100 * 50 + 5
using namespace std;

struct Edge {
    int source, target;
    double weight;
};

int n, m;
double prob[MAX_N];
Edge graph[MAX_M];

void BellmanFord() {
    fill(prob, prob + (n + 1), -1.0);
    prob[1] = 1.0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int u = graph[j].source;
            int v = graph[j].target;
            double w = graph[j].weight;

            prob[u] = max(prob[u], prob[v] * w);
            prob[v] = max(prob[v], prob[u] * w);
        }
    }
}

int main() {
    int u, v, c;

    while (cin >> n, n != 0) {
        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            graph[i] = (Edge) {u, v, c / 100.0};
        }

        BellmanFord();
        cout << fixed << setprecision(6) << prob[n] * 100.0 << " percent" << endl;
    }
    return 0;
}

// Python
def BellmanFord():
    prob[1] = 1.0

    for i in range(n - 1):
        for edge in graph:
            u, v, w = edge
            prob[u] = max(prob[u], prob[v] * w)
            prob[v] = max(prob[v], prob[u] * w)

while True:
    line = list(map(int, input().split()))
    if len(line) == 1:
        break
    
    graph = []
    n, m = line[0], line[1]
    
    for _ in range(m):
        u, v, c = map(int, input().split())
        graph.append((u, v, c / 100))
    
    prob = [-1.0] * (n + 1)
    BellmanFord()

    print("{:.6f} percent".format(prob[n] * 100))
