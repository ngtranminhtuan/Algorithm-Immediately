// Problem: 10397 - Connect the Campus
// Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1338

#include <iostream>
#include <queue>
#include <math.h>

#define INF 1e9
#define MAX 750
using namespace std;

void prim(vector<vector<pair<double, int>>>& graph, int src, vector<double>& dist) {
	int n = graph.size();
	vector<bool> visited(n, false);

	priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
	dist[src] = 0;
	pq.push(make_pair(0, src));

	while (!pq.empty()) {
		pair<double, int> top = pq.top();
		pq.pop();
		int u = top.second;
		visited[u] = true;

		for (int i = 0; i < graph[u].size(); i++) {
			pair<double, int> neighbor = graph[u][i];
			int v = neighbor.second;
			double w = neighbor.first;

			if (!visited[v] && w < dist[v]) {
				dist[v] = w;
				pq.push(make_pair(w, v));
			}
		}
	}
}

double calcDistance(pair<int, int>& p1, pair<int, int>& p2) {
	return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

int main() {
    int n;
    while (cin >> n) {
        vector<pair<int, int>> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i].first >> points[i].second;
        }

        vector<vector<pair<double, int>>> graph(n);
        double buildingDistances[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double w = calcDistance(points[i], points[j]);
                buildingDistances[i][j] = w;
            }
        }

        int m, u, v;
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            u--;
            v--;
            buildingDistances[u][v] = buildingDistances[v][u] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double w = buildingDistances[i][j];
                graph[i].push_back(make_pair(w, j));
                graph[j].push_back(make_pair(w, i));
            }
        }

        vector<double> dist(n, INF);
        prim(graph, 0, dist);

        double total = 0;
        for (int i = 0; i < n; i++) {
            total += dist[i];
        }

        printf("%0.2f\n", total);
    }

	return 0;
}

// St
#include <cmath>
#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <functional>
using namespace std;
#define MAX 751

const int INF = 1e9;
vector<pair<int, double> > graph[MAX];
vector<double> dist(MAX, INF);
vector<int> path(MAX, -1);
bool visited[MAX];
int N, M;
int x[MAX], y[MAX];

int distance(int i, int j)
{
	return (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
}

double result() 
{
	double ans = 0;
	for (int i = 0; i<N; i++) 
	{
		ans += sqrt(dist[i]);
		if (ans >= INF) 
		{
			return -1;
		}
	}
	return ans;
}

void prims(int src) 
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	pq.push(make_pair(0, src));
	dist[src] = 0;
	while (!pq.empty()) 
	{
		int u = pq.top().second;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i<graph[u].size(); i++) 
		{
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && dist[v] > w) 
			{
				dist[v] = w;
				pq.push(make_pair(w, v));
				path[v] = u;
			}
		}
	}
}

void ResetGraph()
{
	for (int i = 0; i < N; i++)
	{
		graph[i].clear();
		visited[i] = false;
		dist[i] = INF;
		path[i] = -1;
	}
}

int main() 
{
	freopen("INPUT.INP", "rt", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> N) 
	{
		for (int i = 0; i<N; i++)
		{
			int a, b;
			cin >> a >> b;
			x[i] = a;
			y[i] = b;
		}
		cin >> M;
		vector<vector<bool> > edges(MAX, vector<bool>(MAX, false));
		for (int i = 0; i<M; i++)
		{
			int a, b;
			cin >> a >> b;
			edges[a - 1][b - 1] = true;
			edges[b - 1][a - 1] = true;
		}
		for (int i = 0; i<N - 1; i++) 
		{
			for (int j = i + 1; j<N; j++)
			{
				if (edges[i][j] == false)
				{
					int w = distance(i, j);
					graph[i].push_back(make_pair(j, w));
					graph[j].push_back(make_pair(i, w));
				}
				else 
				{
					graph[i].push_back(make_pair(j, 0));
					graph[j].push_back(make_pair(i, 0));
				}
			}
		}
		prims(0);
		double r = result();
		printf("%0.2f\n", r);
		ResetGraph();
	}
	return 0;
}

// Py
import queue
import math

class Scanner:
    def __generator__():
        while True:
            try:
                buff = input().strip().split()
                for x in buff:
                    yield x
            except EOFError:
                exit()
                
    sc = __generator__()
    def next():
        return Scanner.sc.__next__()

class node:
    dist = 0
    index = 0

    def __init__(self, dist, index):
        self.dist = dist
        self.index = index

    def __lt__(self, other):
        return self.dist < other.dist

def prim(graph, src):
    # graph = matrix [n][n]
    n = len(graph)
    dist = [1e9] * n
    visited = [0] * n
    total_cost = 0
    dist[src] = 0
    Q = queue.PriorityQueue()
    Q.put(node(0, src))

    while not Q.empty():
        temp = Q.get()
        u = temp.index
        visited[u] = True
        for v in range(n):
            if not visited[v] and dist[v] > graph[u][v]:
                dist[v] = graph[u][v]
                Q.put(node(dist[v], v))

    for i in range(n):
        total_cost += dist[i]
    return total_cost

def distance(x1, y1, x2, y2):
    square_dis = (x1-x2)**2 + (y1-y2)**2
    return math.sqrt(square_dis)

def solve():
    while True:
        n = int(Scanner.next())
        x = [0] * n
        y = [0] * n
        for i in range(n):
            x[i], y[i] = int(Scanner.next()), int(Scanner.next())
        graph = []
        for i in range(n):
            graph.append([])
            for j in range(n):
                graph[i].append(distance(x[i], y[i], x[j], y[j]))
        m = int(Scanner.next())
        for i in range(m):
            u, v = int(Scanner.next()), int(Scanner.next())
            u-=1
            v-=1
            graph[u][v] = 0
            graph[v][u] = 0
        print("%.2f" % prim(graph, 0))

solve()