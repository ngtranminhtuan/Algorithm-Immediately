// Solution: UCV2013B - Alice in Amsterdam, I mean Wonderland
// Link: https://www.spoj.com/problems/UCV2013B/
// 
// Complexity: N^4, N <= 100

#include <iostream>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

#define INF LLONG_MAX

struct Edge {
	int source;
	int target;
	long long weight;

	Edge(int _source, int _target, long long _weight) : source(_source), target(_target), weight(_weight) {}
};

void bellmanFord(vector<Edge>& graph, int n, int s, vector<vector<long long>>& dist, vector<bool>& negativeCycle) {
	dist[s][s] = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < graph.size(); j++) {
			Edge& edge = graph[j];

			int u = edge.source;
			int v = edge.target;
			long long w = edge.weight;

			if (dist[s][u] != INF && dist[s][u] + w < dist[s][v]) {
				if (i == n - 1) { // detect negative cycle
                    negativeCycle[s] = true;
					return;
				} else {
					dist[s][v] = dist[s][u] + w;
				}
			}
		}
	}
}

int main() {
	int n, tc = 0;
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		vector<Edge> graph;
		string k;
		long long w;
		vector<string> names(n);
		for (int i = 0; i < n; i++) {
			cin >> k;
			names[i] = k;

			for (int j = 0; j < n; j++) {
				cin >> w;

				// A loop from a given monument right back to it can be of length zero (with means that it can be reached instantly like in real life) or negative, like for regular paths. Alice also thought that she saw some positive distances for loops, but we should treat those cases as zero distance.
				if (i == j) {
					if (w > 0)
						w = 0;
				}

				// zero distance between two different monuments means a direct path doesn't exist.
				if (i == j || w != 0) {
					graph.push_back(Edge(i, j, w)); // one direction from i to j
				}
			}
		}

		vector<vector<long long>> dist(n, vector<long long>(n, INF));
		vector<bool> negativeCycle(n, false);
		for (int i = 0; i < n; i++) // O(N) * O(N^3) = O(N^4), N <= 100 -> 10^8 => This is complexity of this solution
            bellmanFord(graph, n, i, dist, negativeCycle); // O(V*E) = O(N*N^2) = O(N^3)

		cout << "Case #" << ++tc << ":" << endl;

		int q, u, v;
		cin >> q;
		while (q--) { // O(N^2)
			cin >> u >> v;

			if (negativeCycle[u]) {
				cout << "NEGATIVE CYCLE" << endl;
			} else if (dist[u][v] == INF) {
				cout << names[u] << "-" << names[v] << " " << "NOT REACHABLE" << endl;
			} else {
				cout << names[u] << "-" << names[v] << " " << dist[u][v] << endl;
			}
		}
	}

	return 0;
}
