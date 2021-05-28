// Problem: SOCIALNE - Possible Friends
// Link: https://www.spoj.com/problems/SOCIALNE/

// Complexity: O(M^3), M <= 50
 
#include <iostream>
#include <string>
#include <vector>
 
#define INF 1e9
 
using namespace std;
 
void input(int r, string& line, vector<vector<int>>& graph, vector<vector<int>>& dist) {
    for (int c = 0; c < line.size(); c++) {
        if (r == c)
            graph[r][c] = 0;
        else if (line[c] == 'N')
            graph[r][c] = INF; // no path
        else
            graph[r][c] = 1; // path length 1
 
        dist[r][c] = graph[r][c];
    }
}
 
bool floydWarshall(vector<vector<int>>& graph, vector<vector<int>>& dist) {
    int V = graph.size();
 
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
 
    // check negative cycle
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0)
            return false;
    }
    return true;
}
 
int main() {
    int T;
    cin >> T;
    while (T--) {
        string line;
        cin >> line;
 
        int m = line.size();
        vector<vector<int>> graph(m, vector<int>(m));
        vector<vector<int>> dist(m, vector<int>(m));
 
        input(0, line, graph, dist);
 
        for (int i = 1; i < m; i++) { // O(M^2)
            cin >> line;
            input(i, line, graph, dist); // O(M)
        }
 
        floydWarshall(graph, dist); //O(M^3), M <= 50 -> This is complexity of this solution
 
        int maxPossibleFriend = 0;
        int minId = 0;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            cnt = 0;
            for (int j = 0; j < m; j++) {
                if (dist[i][j] == 2) // Two persons are possible friends if they are not friends and they have at least one common friend
                    cnt++;
 
                if (cnt > maxPossibleFriend) {
                    maxPossibleFriend = cnt;
                    minId = i;
                }
            }
        }
 
        cout << minId << " " << maxPossibleFriend << endl;
    }
 
    return 0;
}

// Standard
#include <bits/stdc++.h>
#define MAX 55
using namespace std;
const int INF = 1e9 + 7;

int M;
string matrix[MAX];
int dist[MAX][MAX];

void FloydWarshall() {
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < M; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int main() {
    int T;
    string s;
    cin >> T;

    while (T--) {
        cin >> s;
        M = s.length();

        for (int i = 0; i < M; i++) {
            if (i == 0) {
                matrix[0] = s;
			      }
			      else {
				        cin >> matrix[i];
			      }

            for (int j = 0; j < M; j++) {
                if (matrix[i][j] == 'Y') {
                    dist[i][j] = 1;
                }
                else {
                    dist[i][j] = (i == j ? 0 : INF);
                }
            }
        }

        FloydWarshall();
        int nfriends = 0, index = 0;

        for (int i = 0; i < M; i++) {
            int count = 0;
            
            for (int j = 0; j < M; j++) {
                if (dist[i][j] == 2) {
                    count++;
                }
            }

            if (count > nfriends) {
                nfriends = count;
                index = i;
            }
        }

        cout << index << " " << nfriends << endl;
    }
    return 0;
}

// PYthon
INF = 10 ** 9

def FloydWarshall():
    for k in range(M):
        for i in range(M):
            for j in range(M):
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

T = int(input())

for _ in range(T):
    s = input()
    M = len(s)
    dist = [[INF] * M for i in range(M)]
    matrix = []

    for i in range(M):
        if i == 0:
            matrix.append(s)
        else:
            matrix.append(input())

        for j in range(M):
            if matrix[i][j] == 'Y':
                dist[i][j] = 1
            elif i == j:
                dist[i][j] = 0
    
    FloydWarshall()
    nfriends, index = 0, 0

    for i in range(M):
        count = 0
        
        for j in range(M):
            if dist[i][j] == 2:
                count += 1
        
        if count > nfriends:
            nfriends = count
            index = i
    
    print(index, nfriends)