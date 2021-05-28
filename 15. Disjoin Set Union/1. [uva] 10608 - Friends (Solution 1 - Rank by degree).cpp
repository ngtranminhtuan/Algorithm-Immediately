// Problem: 10608 - Friends
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549

// Complexity: O(N + MLogN) = O(MLogN)

#include <iostream>
using namespace std;

#define MAX 30000
int parent[MAX];
int ranks[MAX]; // max degree of graph
int sizes[MAX];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
        sizes[i] = 1;
    }
}

int findSet(int u) {
    int oldU = u;
    while (u != parent[u])
        u = parent[u];

    parent[oldU] = u;
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);

    if (up == vp)
        return;

    if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
        sizes[up] += sizes[vp];
    } else if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
        sizes[vp] += sizes[up];
    } else {
        parent[vp] = up;
        sizes[up] += sizes[vp];
        ranks[up]++;
    }
}

int main() {
    int t, n, m;
    cin >> t;

    int a, b;
    while (t--) {
        cin >> n >> m;

        makeSet(n); // O(N)
        for (int i = 0; i < m; i++) { // O(MLogN)
            cin >> a >> b;
            --a, --b;
            unionSet(a, b); // LogN
        }

        int maxFriends = 0;
		for (int i = 0; i < n; i++) { // O(N)
            maxFriends = max(maxFriends, sizes[i]);
        }

        cout << maxFriends << endl;
    }

    return 0;
}

// St
#include <bits/stdc++.h>
using namespace std;
const int MAX = 30005;

int parent[MAX], cnt[MAX], ranks[MAX];

int findSet(int u) {
    while (u != parent[u]) {
        u = parent[u];
    }
    return u;
}

void unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);
    if (up != vp) {
        if (ranks[up] < ranks[vp]) {
            parent[up] = vp;
            cnt[vp] += cnt[up];
        }
        else {
            parent[vp] = up;
            cnt[up] += cnt[vp];
            if (ranks[up] == ranks[vp]) {
                ranks[up] += 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int u, v, t, n, m;
    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            cnt[i] = 1;
            ranks[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            unionSet(u, v);
        }

        int res = -1;
        for (int i = 1; i <= n; i++) {
            res = max(res, cnt[i]);
        }
        cout << res << endl;
    }

    return 0;
}


// py
def findSet(u):
    while u != parent[u]:
        u = parent[u]
    return u

def unionSet(u, v):
    up = findSet(u)
    vp = findSet(v)
    if vp != up:
        if ranks[up] < ranks[vp]:
            parent[up] = vp
            cnt[vp] += cnt[up]
        else:
            parent[vp] = up
            cnt[up] += cnt[vp]
            if ranks[up] == ranks[vp]:
                ranks[up] += 1

t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    parent = [i for i in range(n + 1)]
    cnt = [1 for i in range(n + 1)]
    ranks = [0 for i in range(n + 1)]

    for i in range(m):
        u, v = map(int, input().split())
        unionSet(u, v)
    
    print(max(cnt))
