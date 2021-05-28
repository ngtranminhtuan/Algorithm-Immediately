#include <bits/stdc++.h>
using namespace std;

const int MAX = 105;
const int inf = 1e7;

int test;
map <string , int> my_map;
int n, m;
int dist[MAX];
bool visited[MAX];
vector<pair<int, int> > adj[MAX];

void Prim(int source) {
    priority_queue<pair<int , int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    for (int i = 1; i <= n; i++) {
        dist[i] = inf;
        visited[i] = false;
    }
    pq.push(make_pair(0 , source));
    dist[source] = 0;

    while (!pq.empty()) {
        pair <int , int> tmp = pq.top();
        pq.pop();
        int u = tmp.second;
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            pair<int , int> neighbor = adj[u][i];
            int v = neighbor.first;
            int c = neighbor.second;

            if (!visited[v] && dist[v] > c) {
                dist[v] = c;
                pq.push(make_pair(c , v));
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res += dist[i];

    if (res >= inf) {
        cout << "Impossible\n";
    }
    else {
        cout << res << endl;
    }
}

int main () {
    //freopen("input.txt" , "r" , stdin);
    cin >> test;
    int t = test;

    while (test--) {
        cout << "Case " << t - test << ": ";
        cin >> m;

        my_map.clear();
        n = 0;

        for (int i = 1; i <= 2*m; i++)
            adj[i].clear();

        for (int i = 1; i <= m; i++) {
            string s1 , s2;
            int w;

            cin >> s1 >> s2 >> w;
            if (my_map.find(s1) == my_map.end()) {
                my_map[s1] = ++n;
            }

            if (my_map.find(s2) == my_map.end()) {
                my_map[s2] = ++n;
            }

            int u = my_map[s1];
            int v = my_map[s2];
            adj[u].push_back(make_pair(v , w));
            adj[v].push_back(make_pair(u , w));
        }
        Prim(1);
    }
    return 0;
}

// Py
import queue

class node:
    dist = 0
    index = 0

    def __init__(self, dist, index):
        self.dist = dist
        self.index = index

    def __lt__(self, other):
        return self.dist < other.dist

def inp():
    return map(int, input().split())

def prim(graph, src):
    n = len(graph)
    dist = [1e18 for i in range(n)]
    visited = [0 for i in range(n)]
    total_cost = 0
    dist[src] = 0
    Q = queue.PriorityQueue()
    Q.put(node(0, src))

    while not Q.empty():
        temp = Q.get()
        u = temp.index
        visited[u] = True
        for item in graph[u]:
            v = item.index
            if not visited[v] and dist[v] > item.dist:
                dist[v] = item.dist
                Q.put(node(dist[v], v))

    for i in range(n):
        if dist[i] >= 1e18:
            return "Impossible"
        total_cost += dist[i]
    return total_cost

def solve():
    testcase = int(input())
    for t in range(testcase):
        input()
        m = int(input())
        cities = dict()
        cnt = 0
        graph = []
        for i in range(m):
            name1, name2, cost = input().split()
            if name1 in cities:
                u = cities[name1]
            else:
                u = cnt
                cities[name1] = cnt
                graph.append([])
                cnt+=1
            if name2 in cities:
                v = cities[name2]
            else:
                v = cnt
                cities[name2] = cnt
                graph.append([])
                cnt+=1
            cost = int(cost)
            graph[u].append(node(cost, v))
            graph[v].append(node(cost, u))

        print("Case {}: {}".format(t + 1, prim(graph, 0)))

solve()