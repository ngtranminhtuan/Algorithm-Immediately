// Problem: 10600 - ACM Contest and Blackout
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1541

// Summary of the problem: find the first and second MST of the graph
/* Idea:
		Comment: The second MST can't not be first MST

        Use prim to find lowest MST (firstMST)
        secondMST = INF
        for all edges i of MST
            Delete edge i of the MST.
            Run prim again on the entire graph.
            Restore edge i of the MST
            secondMST = min(secondMST, MST)
        return firstMST and secondMST
*/
// Complexity: N * (M * Log(N))

#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9
using namespace std;

// return: -1 if not found, else mst
int prim(vector<vector<pair<int, int>>>& graph, int n, int src, vector<int>& path, vector<vector<bool>>& forbiddenRoad) {
	vector<int> dist(n, INF);
	vector<int> visited(n, false);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		pair<int, int> top = pq.top();
		pq.pop();
		int u = top.second;
		visited[u] = true;

		for (int i = 0; i < graph[u].size(); i++) {
			pair<int, int> neighbor = graph[u][i];
			int v = neighbor.second;
			int w = neighbor.first;

			if (!forbiddenRoad[u][v] && !visited[v] && w < dist[v]) {
				dist[v] = w;
				path[v] = u;
				pq.push(make_pair(w, v));
			}
		}
	}

	int total = 0;
	for (int i = 0; i < n; i++) {
		if (dist[i] == INF)
			return -1;

		total += dist[i];
	}
	return total;
}

int main() {
	int t;
	cin >> t;

	int n, m;
	int a, b, c;
	while (t--) {
		cin >> n >> m;

		vector<vector<pair<int, int>>> graph(n);
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			--a, --b;
			graph[a].push_back(make_pair(c, b));
			graph[b].push_back(make_pair(c, a));
		}

		vector<int> path(n, -1);
		vector<int> path2(n, -1); // unused
		vector<vector<bool>> forbiddenRoad(n, vector<bool>(n, false));

		int firstMST = prim(graph, n, 0, path, forbiddenRoad);
		int secondMST = INF;
		for (int i = 0; i < n; i++) { // for edge in lowest MST
			if (i > 0) {
				forbiddenRoad[i][path[i]] = forbiddenRoad[path[i]][i] = true; // forbid 1 road in MST
				int mst = prim(graph, n, 0, path2, forbiddenRoad);
				if (mst >= 0) // have mst
					secondMST = min(secondMST, mst);

				forbiddenRoad[i][path[i]] = forbiddenRoad[path[i]][i] = false; // restore 1 forbid road in MST
			}
		}

		cout << firstMST << " " << secondMST << endl;
	}

	return 0;
}

// St
#include <bits/stdc++.h> 
 
using namespace std; 
 
const int MAX_N = 105; 
 
int dist[MAX_N]; 
bool mark[MAX_N][MAX_N][3 * MAX_N]; 
 
struct edge {
	int u , v , c; 
};
 
vector <edge> save , tmp; 
vector <pair <int , int> > V[MAX_N]; 
bool visited[MAX_N]; 
int path[MAX_N]; 
int n , m , test; 
int cnt[MAX_N];
 
const int inf = 1e8; 
 
int Prim(int source , vector <edge> &save) {
	for (int i = 1; i <= n; i++) {
		dist[i] = inf; 
		visited[i] = false; 
		path[i] = -1; 
	}
 
	priority_queue <pair <int , int> , vector <pair <int , int> > , greater <pair <int , int> > > pq; 
 
	pq.push(make_pair(0 , source)); 
 
	dist[source] = 0; 
 
	while (!pq.empty()) {
		pair <int , int> K = pq.top(); 
		pq.pop(); 
 
		int u = K.second;
		visited[u] = true; 
 
		for (int i = 0; i < V[u].size(); i++) {
			pair <int , int> K = V[u][i]; 
 
			int v = K.first; 
			int c = K.second; 
 
			if (visited[v]) continue; 
			if (mark[u][v][c]) continue; 
			if (dist[v] <= c) continue;
 
			dist[v] = c; 
			path[v] = u;
 
			pq.push(make_pair(c , v));  
		}
	}
 
	int res = 0; 
 
	for (int i = 1; i <= n; i++)
		if (dist[i] == inf) return -1; 
 
	for (int i = 1; i <= n; i++) res += dist[i];  
 
	for (int i = 1; i <= n; i++) {
		int u = path[i]; 
 
		if (u != -1)
			save.push_back((edge) {u , i , dist[i]}); 
	}
 
	return res; 
}
 
int main () {
	scanf("%d" , &test); 
 
	while (test--) {
		for (int i = 1; i < MAX_N; i++)
			for (int j = 1; j < MAX_N; j++)
				for (int x = 1; x < 3 * MAX_N; x++) mark[i][j][x] = false; 
 
		scanf("%d %d" , &n , &m); 
 
		for (int i = 1; i <= n; i++) V[i].clear(); 
 
		while (m--) {
			int u , v , c; 
			scanf("%d %d %d" , &u , &v , &c); 
			cnt[u]++; 
			cnt[v]++; 
 
			V[u].push_back(make_pair(v , c)); 
			V[v].push_back(make_pair(u , c)); 
		}
 
		save.clear(); 
 
		int mini0 = Prim(1 , save); 
 
		printf("%d " , mini0);
 
		int mini = inf;  
 
		for (int i = 0; i < save.size(); i++) {
			int u = save[i].u; 
			int v = save[i].v; 
			int c = save[i].c; 
 
			mark[u][v][c] = mark[v][u][c] = true; 
			cnt[u]--; cnt[v]--;
 
			tmp.clear(); 
 
			int x; 
 
			for (int i = 1; i <= n; i++) 
				if (cnt[i]) {
					x = i; 
					break; 
				}
 
			int K = Prim(x , tmp); 
 
			if (K >= 0) mini = min(mini , K); 
 
			mark[u][v][c] = mark[v][u][c] = false; 
			cnt[u]++; cnt[v]++; 
		}
 
		if (mini == inf) mini = mini0; 
 
		printf("%d\n" , mini); 
	}
	return 0; 
}

//Py
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
    trace = [{} for i in range(n)]
    while not Q.empty():
        temp = Q.get()
        u = temp.index
        visited[u] = True
        _len = len(graph[u])
        for i in range(_len):
            v = graph[u][i].index
            if not visited[v] and dist[v] > graph[u][i].dist:
                dist[v] = graph[u][i].dist
                Q.put(node(dist[v], v))
                trace[v] = {'path': u, 'index': i}
    for i in range(n):
        total_cost += dist[i]
    return total_cost, trace

def inp():
    return map(int, input().split())

def solve():
    testcase = int(input())
    inf = 1e9
    for t in range(testcase):
        n, m = inp()
        graph = [[] for i in range(n)]
        for i in range(m):
            u, v, cost = inp()
            u-=1
            v-=1
            graph[u].append(node(cost, v))
            graph[v].append(node(cost, u))
        trace = []
        min1, trace = prim(graph, 0)
#         xoa canh bang cach thay cac canh do bang inf
        min2 = inf
        for j in range(1, n):
            item = trace[j]
            u = item['path']
            i = item['index']
            temp = graph[u][i].dist
            graph[u][i].dist = inf
            val, temp_trace = prim(graph, 0)
            graph[u][i].dist = temp
            min2 = min(min2, val)

        print('{} {}'.format(min1, min2))
solve()