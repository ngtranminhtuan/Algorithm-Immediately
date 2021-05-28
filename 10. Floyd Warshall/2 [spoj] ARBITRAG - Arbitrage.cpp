// Problem: ARBITRAG - Arbitrage
// Link: https://www.spoj.com/problems/ARBITRAG/

// Complexity: O(N^3), N <= 30

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool floydWarshall(vector<vector<double>>& dist, int V) {
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] > 0 && dist[k][j] > 0 && dist[i][j] < dist[i][k] * dist[k][j]) {
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }

    // check positive cycle
    for (int i = 0; i < V; i++) {
        if (dist[i][i] > 1)
            return true;
    }
    return false;
}

int main() {
    int T = 0;
    int n, m;
    string s, s1, s2;
    int id1, id2;
    double convertRate;
    while (true) {
        cin >> n;
        if (n == 0)
            break;

        vector<vector<double>> dist(n, vector<double>(n));
        unordered_map<string, int> mapIds;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dist[i][j] = 1;
                } else {
                    dist[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            cin >> s;
            mapIds[s] = i;
        }

        cin >> m;
        while (m--) {
            cin >> s1 >> convertRate >> s2;
            id1 = mapIds[s1];
            id2 = mapIds[s2];
            dist[id1][id2] = convertRate;
        }

        bool isArbitrage = floydWarshall(dist, n); // O(N^3), N <= 30 -> This is complexity of this solution
        cout << "Case " << ++T << ": " << (isArbitrage ? "Yes" : "No") << endl;
    }

    return 0;
}

// Standard
#include <iostream>
using namespace std;
const int MAX = 40;

string currencies[MAX];
double dist[MAX][MAX];
int n, m;

int findCurrency(string s){
    for (int i = 0; i < n; i++)
        if (currencies[i] == s)
            return i;
    return -1;
}

void floydWarshall() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][j] < dist[i][k] * dist[k][j]) {
                    dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }
    }
}

int main() {
    int tc = 1;
    string u, v;
    double w;

    while (true) {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = 0;
                if (i == j)
                    dist[i][j] = 1;
            }
        }
        for (int i = 0; i < n; i++)
            cin >> currencies[i];
        cin >> m;
        for (int i = 0; i < m; i++){
            cin >> u >> w >> v;
            dist[findCurrency(u)][findCurrency(v)] = w;
        }
        floydWarshall();
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (dist[i][i] > 1) {
                flag = true;
                break;
            }
        }
        cout << "Case " << tc++ << ": " << (flag ? "Yes" : "No") << "\n";
    }
    return 0;
}

// Python
def FloydWarshall():
    for k in range(N):
        for i in range(N):
            for j in range(N):
                dist[i][j] = max(dist[i][j], dist[i][k] * dist[k][j])

t = 1
while True:
    N = int(input())
    if N == 0:
        break
    
    dist = [[1 if i == j else 0 for j in range(N)] for i in range(N)]
    currencies = []

    for _ in range(N):
        currencies.append(input().strip())
    
    M = int(input())
    for _ in range(M):
        sourceCur, rate, desCur = input().split()
        u, v = map(lambda x: currencies.index(x), (sourceCur, desCur))
        dist[u][v] = float(rate)
    input()

    FloydWarshall()

    arbitrage = False
    for i in range(N):
        if dist[i][i] > 1:
            arbitrage = True
            break
    
    print('Case {}: {}'.format(t, "Yes" if arbitrage else "No"))
    t += 1