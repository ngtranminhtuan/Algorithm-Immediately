// Problem: 10803 - Thunder Mountain
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744

// Complexity: O(n^3), n <= 100
/* Summary of problem:
        Input: There are n (1 < n < 101) coordinates (x, y) on planes (0 <= x,y <= 1023), there exists a direct path between 2 point if distance <= 10,
            calculate the shortest path between every pair of 2 different points, find the path that have maximum distance.
        Output:
            If there exists no path between any 2 points
                -> print "Send Kurdy"
            else
                -> print maximum distance of the path have maximum distance

*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF INT_MAX

void floydWarshall(vector<vector<double>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

double calcDistance(const pair<int, int>& p1, const pair<int, int>& p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
    int N;
    cin >> N;

    int n;
    for (int tc = 1; tc <= N; tc++) {
        cin >> n;
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        vector<vector<double>> dist(n, vector<double>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double w = calcDistance(points[i], points[j]);
                if (w <= 10) {
                    dist[i][j] = dist[j][i] = w;
                } else {
                    dist[i][j] = INF;
                }
            }
        }

        floydWarshall(dist, n); // O(n^3), n <= 100 -> This is complexity of this algorithm

        double maxDist = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                maxDist = max(maxDist, dist[i][j]);
            }
        }

        cout << "Case #" << tc << ":" << endl;

        if (maxDist == INF)
            cout << "Send Kurdy" << endl;
        else
            printf("%0.4f\n", maxDist);
        cout << endl;
    }

	return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 2049;        
// Khoảng cách lớn nhất là từ điểm (0, 0) đến (1024, 1024) nên phải khởi tạo INF lớn hơn khoảng cách này

int n;
int x[MAX], y[MAX];
double dist[MAX][MAX];

double getDistance(int i, int j) {
    return sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
}

void FloydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    for (int t = 1; t <= N; t++) {
        cin >> n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = (i == j ? 0 : INF);
            }
        }

        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                double d = getDistance(i, j);
                if (d <= 10) {
                    dist[i][j] = d;
                }
            }
        }

        FloydWarshall();
        double res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dist[i][j]);
            }
        }

        cout << "Case #" << t << ":" << endl;
        if (res != INF) {
            cout << fixed << setprecision(4) << res << endl;
        }
        else {
            cout << "Send Kurdy" << endl;
        }

        cout << endl;
    }
    return 0;
}

// Python
class Scanner:
    def __gen__():
        while True:
            buff = input().strip().split()
            for x in buff:
                yield x
    __sc__ = __gen__()
    def next():
        return Scanner.__sc__.__next__()

INF = 1029
MAX = 105
x = [None] * MAX
y = [None] * MAX
dist = [[0] * MAX for _ in range(MAX)]

def getDistance(i, j):
    return ((x[i] - x[j]) ** 2 + (y[i] - y[j]) ** 2) ** 0.5

def FloydWarshall():
    for k in range(n):
        for i in range(n):
            for j in range(n):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

N = int(Scanner.next())

for t in range(1, N + 1):
    n = int(Scanner.next())
    
    for i in range(n):
        for j in range(n):
            dist[i][j] = (0 if i == j else INF)
    
    for i in range(n):
        x[i] = int(Scanner.next())
        y[i] = int(Scanner.next())
    
    for i in range(n):
        for j in range(n):
            d = getDistance(i, j)
            if d <= 10:
                dist[i][j] = d
    
    FloydWarshall()

    res = 0
    for i in range(n):
        for j in range(n):
            res = max(res, dist[i][j])
    
    print('Case #{}:'.format(t))
    print(res if res != INF else 'Send Kurdy')
    print()