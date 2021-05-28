// Problem: 10171 - Meeting Prof. Miguel...
// Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1112

// Complexity: O(NLog(MAX) + MAX), MAX = 26 => O(NLog26)

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

#define MAX 'Z'-'A'+1
#define INF INT_MAX
using namespace std;

struct Target {
	int energy;
	int target;
	bool isYoung;

	Target(int _energy, int _target, bool _isYoung) : energy(_energy), target(_target), isYoung(_isYoung) {}
	Target(int _energy, int _target) : energy(_energy), target(_target), isYoung(false) {}
};

struct minHeapOption {
	bool operator()(const Target& a, const Target& b) {
		return a.energy > b.energy;
	}
};

// O(ELogV)
void dijikstra(int s, vector<vector<Target>>& graph, vector<int>& dist, bool isYoung) {
	priority_queue<Target, vector<Target>, minHeapOption> pq;
	dist[s] = 0;
	pq.push(Target(dist[s], s));

	while (!pq.empty()) {
        Target top = pq.top();
		pq.pop();
		int u = top.target;
		int w = top.energy;

		for (int i = 0; i < graph[u].size(); i++) {
			Target& neighbor = graph[u][i];
			int v = neighbor.target;

			if (neighbor.isYoung == isYoung && w + neighbor.energy < dist[v]) {
				dist[v] = w + neighbor.energy;
				pq.push(Target(dist[v], v));
			}
		}
	}
}

int main() {
	int n;
	char age, direction, city1, city2;
	int energy;
	char src, dst;
	while (true) {
		cin >> n;
		if (n == 0)
			break;

		vector<vector<Target>> graph(MAX);
		while (n--) {
			cin >> age >> direction >> city1 >> city2 >> energy;
			city1 -= 'A', city2 -= 'A';
			graph[city1].push_back(Target(energy, city2, age == 'Y'));
			if (direction == 'B')
				graph[city2].push_back(Target(energy, city1, age == 'Y'));
		}

		cin >> src >> dst;
		src -= 'A', dst -= 'A';
		vector<int> distFromSrc(MAX, INF);
		vector<int> distFromDst(MAX, INF);
		dijikstra(src, graph, distFromSrc, true); // NLog(MAX)
		dijikstra(dst, graph, distFromDst, false); // NLog(MAX)

		int minDist = INF;
		for (int i = 0; i < MAX; i++) { // O(MAX)
			if (distFromSrc[i] != INF && distFromDst[i] != INF && distFromSrc[i] + distFromDst[i] < minDist) {
				minDist = distFromSrc[i] + distFromDst[i];
			}
		}

		if (minDist != INF) {
			cout << minDist;
			for (int i = 0; i < MAX; i++) {
				if (distFromSrc[i] != INF && distFromDst[i] != INF && distFromSrc[i] + distFromDst[i] == minDist) {
					cout << " " << char(i + 'A');
				}
			}
			cout << endl;
		} else {
			cout << "You will never meet." << endl;
		}
	}

	return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 28
using namespace std;
const int INF = 1e9 + 7;

struct Place {
    int cost, id;

    bool operator<(const Place &other) const {
        return cost < other.cost || (cost == other.cost && id < other.id);
    }
};

int distS[MAX][MAX], distD[MAX][MAX];
vector<Place> res;

void FloydWarshall(int dist[MAX][MAX]) {
    for (int k = 0; k < MAX; k++) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int N, c;
    char age, dir, x, y;

    while (cin >> N && N != 0) {
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                distS[i][j] = (i == j ? 0 : INF);
                distD[i][j] = (i == j ? 0 : INF);
            }
        }

        for (int i = 0; i < N; i++) {
            cin >> age >> dir >> x >> y >> c;
            int u = x - 'A';
            int v = y - 'A';

            if (age == 'Y') {
                distS[u][v] = min(distS[u][v], c);
                if (dir == 'B') {
                    distS[v][u] = min(distS[v][u], c);
                }
            }
            else {
                distD[u][v] = min(distD[u][v], c);
                if (dir == 'B') {
                    distD[v][u] = min(distD[v][u], c);
                }
            }
        }

        cin >> x >> y;
        int s = x - 'A';
        int d = y - 'A';
        FloydWarshall(distS);
        FloydWarshall(distD);

        res.clear();
        int minDist = INF;

        for (int i = 0; i < MAX; i++) {
            int dist1 = distS[s][i];
            int dist2 = distD[d][i];

            if (dist1 != INF && dist2 != INF && dist1 + dist2 <= minDist) {
                res.push_back({dist1 + dist2, i});
                minDist = dist1 + dist2;
            }
        }

        if (res.empty()) {
            cout << "You will never meet.";
        }
        else {
            sort(res.begin(), res.end());
            cout << minDist;

            for (Place &place : res) {
                if (place.cost != minDist) {
                    break;
                }
                cout << " " << char(place.id + 'A');
            }
        }
        cout << endl;
    }
    return 0;
}

// Python
INF = 10 ** 9
MAX = 28

def FloydWarshall(dist):
    for k in range(MAX):
        for i in range(MAX):
            for j in range(MAX):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

while True:
    N = int(input())
    if N == 0:
        break
    
    distS = [[0 if i == j else INF for j in range(MAX)] for i in range(MAX)]
    distD = [[0 if i == j else INF for j in range(MAX)] for i in range(MAX)]

    for _ in range(N):
        age, dir, x, y, c = input().split()
        u, v = map(lambda char: ord(char) - ord('A'), (x, y))
        c = int(c)

        if age == 'Y':
            distS[u][v] = min(distS[u][v], c)
            if dir == 'B':
                distS[v][u] = min(distS[v][u], c)
        else:
            distD[u][v] = min(distD[u][v], c)
            if dir == 'B':
                distD[v][u] = min(distD[v][u], c)
        
    s, d = map(lambda char: ord(char) - ord('A'), input().split())
    FloydWarshall(distS)
    FloydWarshall(distD)

    res = []
    minDist = INF

    for i in range(MAX):
        dist1 = distS[s][i]
        dist2 = distD[d][i]

        if dist1 != INF and dist2 != INF and dist1 + dist2 <= minDist:
            res.append((dist1 + dist2, i))
            minDist = dist1 + dist2
    
    if not res:
        print('You will never meet.')
    else:
        res.sort()
        print(minDist, end='')

        for place in res:
            if place[0] != minDist:
                break
            print(' ' + chr(place[1] + ord('A')), end = '')
        print()


