#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
const int MAX = 1e5 + 10;
const int INF = 1e9;

vector<pii > graph[MAX];
vector<int> dist(MAX, INF);
bool visited[MAX];

struct option {
    bool operator() (const pii &a, const pii &b) const {
        return a.second > b.second;
    }
}; 

void prim(int src) {
    priority_queue<pii, vector<pii >, option > pq;
    pq.push(make_pair(src, 0));
    dist[src] = 0;
    while (!pq.empty()) {
        int u = pq.top().first;
        pq.pop();
        visited[u] = true;
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (!visited[v] && dist[v] > w) {
                dist[v] = w;
                pq.push(make_pair(v, w));
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m;
    for (int u, v, w, i = 0; i < m; i++) {
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
        graph[v].push_back(make_pair(u, w));
    }
    prim(1);
    priority_queue<int> mstCable;
    for (int i = 2; i <= n; i++) {
        mstCable.push(dist[i]); // add all edges in mst to max heap
    }
    cin >> q;
    priority_queue<int, vector<int>, greater<int> > newCables;
    for (int x, i = 0; i < q; i++) {
        cin >> x;
        newCables.push(x);
    }
    long long res = 0;
    while (!mstCable.empty()) {
        int usedCable = mstCable.top();
        mstCable.pop();
        if (!newCables.empty() && newCables.top() < usedCable) {
            usedCable = newCables.top(); // replace old cable by new cable
            newCables.pop();
        }
        res += usedCable;
    }
    cout << res;
    return 0;
}

//Python
import queue

INF = 1e9

class Node:
    def __init__(self, dist, index):
        self.dist = dist
        self.index = index

    def __lt__(self, other):
        return self.dist < other.dist

def prim(src):
    dist[src] = 0
    pq = queue.PriorityQueue()
    pq.put(Node(0, src))
    while not pq.empty():
        u = pq.get().index
        visited[u] = True
        for item in graph[u]:
            v, w = item.index, item.dist
            if not visited[v] and dist[v] > w:
                dist[v] = w
                pq.put(Node(dist[v], v))

    return dist

n, m = map(int, input().split())
graph = [[] for i in range(n + 1)]
dist = [INF for i in range(n + 1)]
visited = [False for i in range(n + 1)]
for i in range(m):
    u, v, w = map(int, input().split())
    graph[u].append(Node(w, v))
    graph[v].append(Node(w, u))
mstCables = prim(1)[2: ]
mstCables.sort(reverse=True)
newCables = queue.PriorityQueue() # min heap
q = int(input())
if (q > 0):
    for cable in list(map(int, input().split())):
        newCables.put(cable)
res = 0
for oldCable in mstCables:
    usedCable = oldCable
    if not newCables.empty() and newCables.queue[0] < usedCable:
        usedCable = newCables.get()
    res += usedCable
print(res)