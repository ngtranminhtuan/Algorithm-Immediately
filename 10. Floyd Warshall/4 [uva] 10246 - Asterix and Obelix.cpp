// Problem: 10246 - Asterix and Obelix
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1187

// Complexity: O(C^3), C <= 80

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
#define INF INT_MAX

void floydWarshall(vector<vector<int>>& dist, int V, vector<int> fcost) {
    vector<vector<int>> maxCost(V, vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            maxCost[i][j] = max(fcost[i], fcost[j]);
            if (dist[i][j] != INF)
                dist[i][j] = dist[i][j] + maxCost[i][j];
        }
    }

    for (int e = 0; e < 2; e++) {
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j] - min(maxCost[i][k], maxCost[k][j])) {
                        dist[i][j] = dist[i][k] + dist[k][j] - min(maxCost[i][k], maxCost[k][j]);
                        maxCost[i][j] = max(maxCost[i][k], maxCost[k][j]);
                    }
                }
            }
        }
    }
}

int main() {
	int T = 0;
	int C, R, Q;
	int c1, c2, d;
	while (true) {
		cin >> C >> R >> Q;
		if (C + R + Q == 0)
			break;

		vector<vector<int>> dist(C, vector<int>(C));
		vector<int> fcost(C);
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < C; j++) {
				if (i == j) {
					dist[i][j] = 0;
				} else {
					dist[i][j] = INF;
				}
			}
		}

		for (int i = 0; i < C; i++) {
			cin >> fcost[i];
		}

		while (R--) {
			cin >> c1 >> c2 >> d;
			--c1, --c2;
			dist[c1][c2] = dist[c2][c1] = d;
		}

		floydWarshall(dist, C, fcost); // O(C^3), C <= 80 -> This is complexity of this algorithm

		if (T > 0)
            cout << endl; // Print a blank line between two consecutive test cases

		cout << "Case #" << ++T << endl;
		while (Q--) {
			cin >> c1 >> c2;
			--c1, --c2;
			if (dist[c1][c2] == INF) {
				cout << -1 << endl;
			} else {
				cout << dist[c1][c2] << endl;
			}
		}
	}

	return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 85
using namespace std;
const int INF = 1e9 + 7;

int C, R;
int dist[MAX][MAX];
int maxCost[MAX][MAX];
int f[MAX];

void FloydWarshall() {
    int times = 2;

    while (times--) {
        for (int k = 1; k <= C; k++) {
            for (int i = 1; i <= C; i++) {
                for (int j = 1; j <= C; j++) {
                    int maxFeast = max(maxCost[i][k], maxCost[k][j]);
                    if (dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + maxFeast) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                        maxCost[i][j] = maxFeast;
                    }
                }
            }
        }
    }
}

int main() {
    int u, v, w, Q, t = 1;

    while (cin >> C >> R >> Q) {
        if (C == 0) {
            break;
        }

        for (int i = 1; i <= C; i++) {
            cin >> f[i];
        }

        for (int i = 1; i <= C; i++) {
            for (int j = 1; j <= C; j++) {
                dist[i][j] = INF;
                maxCost[i][j] = max(f[i], f[j]);
            }
        }

        for (int i = 0; i < R; i++) {
            cin >> u >> v >> w;
            dist[u][v] = dist[v][u] = w;
        }

        FloydWarshall();

        if (t > 1) {
            cout << endl;
        }
        cout << "Case #" << t++ << endl;

        for (int i = 0; i < Q; i++) {
            cin >> u >> v;
            cout << (dist[u][v] == INF ? -1 : dist[u][v] + maxCost[u][v]) << endl;
        }
    }
    return 0;
}

// python
maxCost = [[None] * 85 for _ in range(85)]
INF = 10 ** 9
t = 1

def FloydWarshall():
    for _ in range(2):
        for k in range(1, C + 1):
            for i in range(1, C + 1):
                for j in range(1, C + 1):
                    maxFeast = max(maxCost[i][k], maxCost[k][j])
                    if dist[i][j] + maxCost[i][j] > dist[i][k] + dist[k][j] + maxFeast:
                        dist[i][j] = dist[i][k] + dist[k][j]
                        maxCost[i][j] = maxFeast

while True:
    C, R, Q = map(int, input().split())

    if C == 0:
        break
    
    f = [0] + list(map(int, input().split()))
    
    for i in range(1, C + 1):
        for j in range(1, C + 1):
            maxCost[i][j] = max(f[i], f[j])

    dist = [[INF] * (C + 1) for _ in range(C + 1)]

    for _ in range(R):
        u, v, w = map(int, input().split())
        dist[u][v] = dist[v][u] = w
    
    FloydWarshall()

    if t > 1:
        print()
    
    print('Case #{}'.format(t))
    t += 1

    for _ in range(Q):
        u, v = map(int, input().split())
        print(-1 if dist[u][v] == INF else dist[u][v] + maxCost[u][v])