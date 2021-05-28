#include <bits/stdc++.h>
using namespace std;
const int MAX = 105;

int parent[MAX];

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    parent[up] = vp;
}

int main() {
    int u, v, N, M;
    cin >> N >> M;
    
    if (N != M) {
        cout << "NO";
        return 0;
    }

    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        unionSet(u, v);
    }

    int nGroup = 0;
    for (int i = 1; i <= N; i++) {
        if (i == parent[i]) {
            nGroup++;
            if (nGroup > 1) {
                break;
            }
        }
    }

    cout << (nGroup == 1 ? "FHTAGN!" : "NO");
    return 0;
}

//Python
import sys

def getroot(lab, u):
    if lab[u] == -1:
        return u
    lab[u] = getroot(lab, lab[u])
    return lab[u]

def union(lab, cou, a, b):
    if cou[a] > cou[b]:
        cou[a] += cou[b]
        lab[b] = a
    else:
        cou[b] += cou[a]
        lab[a] = b

def inp():
    return map(int, input().split())

def solve():
    n, m = inp()
    lab = [-1 for i in range(n)]
    cou = [1 for i in range(n)]

    if n != m:
        print("NO") #impossible
        return

    for i in range(m):
        u, v = inp()
        u = getroot(lab, u-1)
        v = getroot(lab, v-1)
        if u != v:
            union(lab, cou, u, v)
    if lab.count(-1) > 1: #not connected
        print("NO")
        return 

    print("FHTAGN!")

solve()