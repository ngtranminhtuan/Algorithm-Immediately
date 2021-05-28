// 
#include <bits/stdc++.h>
#define MAX 505
using namespace std;

int n;
int dist[MAX][MAX];
long long res[MAX];
int middleV[MAX];

int main() {

    int u, v;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> middleV[i];
    }

    for (int index = n - 1; index >= 0; index--) {
        int k = middleV[index];
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }

        for (int i = index; i < n; i++) {
            u = middleV[i];
            for (int j = index; j < n; j++) {
                v = middleV[j];
                res[index] += dist[u][v];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }

    return 0;
}

// Python
n = int(input())
dist = [[0] * (n + 1)]

for i in range(1, n + 1):
    dist.append([0] + list(map(int, input().split())))

middleV = list(map(int, input().split()))
res = [0] * n

for index in range(n - 1, -1, -1):
    k = middleV[index]

    for i in range(1, n + 1):
        for j in range(1, n + 1):
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
    
    for u in middleV[index:]:
        for v in middleV[index:]:
            res[index] += dist[u][v]

print(*res)