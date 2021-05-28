#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include "sstream"
#include <vector>
#include <queue>
using namespace std;
 
vector<int> adj[500];
int dis[1010];
int vis[1010];
 
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i = 0; i < adj[f].size(); i++)
        {
            int e = adj[f][i];
            if (!vis[e])
            {
                vis[e] = 1;
                dis[e] = dis[f] + 1;
                q.push(e);
            }
        }
    }
}
 
int main()
{
    freopen("INPUT.INP", "rt", stdin);
    int n, p = 1;
    cin >> n;
    map<string, int> mp;
    map<string, int>::iterator it;
 
    for (int i = 0; i < n; i++)
    {
        string f, s, t;
        cin >> f >> s >> t;
        if (!mp[f])
            mp[f] = p++;
        if (!mp[s])
            mp[s] = p++;
        if (!mp[t])
            mp[t] = p++;
        adj[mp[f]].push_back(mp[s]);
        adj[mp[f]].push_back(mp[t]);
        adj[mp[s]].push_back(mp[f]);
        adj[mp[s]].push_back(mp[t]);
        adj[mp[t]].push_back(mp[f]);
        adj[mp[t]].push_back(mp[s]);
    }
 
    bfs(mp["Isenbaev"]);
 
    for (it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second == 0)
            continue;
 
        if (!vis[it->second])
        {
            cout << it->first << " undefined" << endl;
        }
        else
        {
            cout << it->first << " " << dis[it->second] << endl;
        }
    }
 
    return 0;
}

// Python
import queue
 
def BFS(graph, src, rank):
    Q = queue.Queue()
    rank[src] = 0
    Q.put(src)
    while not Q.empty():
        u = Q.get()
        for v in graph[u]:
            if rank[v] == 'undefined':
                rank[v] = rank[u] + 1
                Q.put(v)
    return rank
 
def solve():
    n = int(input())
    S = dict()
    cnt = 0
    graph = []
    for i in range(n):
        line = input().split()
        v = []
        for name in line:
            if name in S:
                id = S[name]
            else:
                S[name] = cnt
                id = cnt
                graph.append([])
                cnt+= 1
            v.append(id)
        for x in v:
            for y in v:
                if x != y:
                    graph[x].append(y)
    rank = ['undefined' for i in range(cnt)]
    if 'Isenbaev' in S:
        rank = BFS(graph, S['Isenbaev'], rank)
    a = []
    for name in S:
        a.append(name)
    a.sort()
    for name in a:
        print(name + ' ' + str(rank[S[name]]))
solve()