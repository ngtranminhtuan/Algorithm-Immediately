// Problem: 1174 - Commandos
// Link: http://lightoj.com/volume_showproblem.php?problem=1174
// 

/*
Problem: Thả 1 bầy không giới hạn số lượng các con commando từ tòa nhà s, cho nó đi lung tung phá các tòa nhà mà nó đi qua (trong cùng 1 unit time các con commando có thể phá các tòa nhà song song), xong cho nó tập hợp tại tòa nhà cuối d
-> Tìm thời gian ngắn nhất khi các con commando xuất phát từ s phá xong tất cả các tòa nhà và tập hợp tại d nhỉ

Solution: Giả sử mỗi con commando đều đi con đường ngắn nhất xuất phát từ s, chỉ phá 1 tòa nhà và kết thúc tại d.
=> Tìm con nào đường đi dài nhất trong tất cả các con
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int s, vector<vector<int>>& graph, vector<int>& dist) {
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i];

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    int n, r, u, v;
    int s, d;
    for (int x = 1; x <= T; x++) {
        cin >> n >> r;

        vector<vector<int>> graph(n);
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        for (int i = 0; i < r; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        cin >> s >> d;
        bfs(s, graph, dist1);
        bfs(d, graph, dist2);

        int longPath = 0; // long path 1 commando come from s->i->d
        for (int i = 0; i < n; i++) {
            int minPath = dist1[i] + dist2[i]; // min path of s->i->d: commando go from s to i (destroy ith building) and finish at d
            longPath = max(longPath, minPath);
        }

        cout << "Case " << x << ": " << longPath << endl;
    }

    return 0;
}


// Standard
#include <bits/stdc++.h>
#define MAX 105
using namespace std;
const int INF = 1e9 + 7;
 
int N, R;
vector<pair<int, int> > graph[MAX];
 
vector<int> Dijkstra(int s) {
    vector<int> dist(N, INF);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, s));
    dist[s] = 0;
     
    while (!pq.empty()) {
        pair<int, int> top = pq.top();
        pq.pop();
         
        int u = top.second;
        int w = top.first;
         
        if (w > dist[u]) {
            continue;
        }
         
        for (int i = 0; i < graph[u].size(); i++) {
            pair<int, int> neighbor = graph[u][i];
             
            if (w + neighbor.first < dist[neighbor.second]) {
                dist[neighbor.second] = w + neighbor.first;
                pq.push(make_pair(dist[neighbor.second], neighbor.second));
            }
        }
    }
     
    return dist;
}
 
int main() {
    int T, s, d, u, v;
    cin >> T;
     
    for (int t = 1; t <= T; t++) {
        cin >> N >> R;
         
        for (int i = 0; i < N; i++) {
            graph[i].clear();
        }
         
        for (int i = 0; i < R; i++) {
            cin >> u >> v;
            graph[u].push_back(make_pair(1, v));
            graph[v].push_back(make_pair(1, u));
        }
         
        cin >> s >> d;
         
        vector<int> distS = Dijkstra(s);
        vector<int> distD = Dijkstra(d);
        int res = 0;
         
        for (int i = 0; i < N; i++) {
            res = max(res, distS[i] + distD[i]);
        }
         
        cout << "Case " << t << ": " << res << endl;
    }
    return 0;
}

// Python

from heapq import heappush, heappop
 
def Dijkstra(s):
    dist = [10 ** 9] * N
    pq = [(0, s)]
    dist[s] = 0
     
    while pq:
        w, u = heappop(pq)
         
        if w > dist[u]:
            continue
         
        for weight, v in graph[u]:
            if w + weight < dist[v]:
                dist[v] = w + weight
                heappush(pq, (dist[v], v))
     
    return dist
 
T = int(input())
 
for t in range(1, T + 1):
    N = int(input())
    R = int(input())
    graph = [[] for _ in range(N)]
     
    for _ in range(R):
        u, v = map(int, input().split())
        graph[u].append((1, v))
        graph[v].append((1, u))
     
    s, d = map(int, input().split())
    distS = Dijkstra(s)
    distD = Dijkstra(d)
    res = 0
     
    for i in range(N):
        res = max(res, distS[i] + distD[i])
     
    print("Case {}: {}".format(t, res))