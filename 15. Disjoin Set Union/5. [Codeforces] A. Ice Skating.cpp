// Problem: A. Ice Skating
// Link: https://codeforces.com/problemset/problem/217/A

// Complexity: N*N*LogN, N <= 100

#include <iostream>
#include <vector>
using namespace std;

#define MAX 100
int parent[MAX];
int ranks[MAX]; // max degree of graph

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        ranks[i] = 0;
    }
}

int findSet(int u) {
    int oldU = u;
    while (u != parent[u])
        u = parent[u];

    parent[oldU] = u;
    return u;
}

// return: true if success, else return false
bool unionSet(int u, int v) {
    int up = findSet(u);
    int vp = findSet(v);

    if (up == vp)
        return false;

    if (ranks[up] > ranks[vp]) {
        parent[vp] = up;
    } else if (ranks[up] < ranks[vp]) {
        parent[up] = vp;
    } else {
        parent[vp] = up;
        ranks[up]++;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    makeSet(n);
    vector<pair<int, int>> snowDrift(n);
    for (int i = 0; i < n; i++) {
        cin >> snowDrift[i].first >> snowDrift[i].second;
    }

    int differentSet = n;
    for (int i = 0; i < n; i++) { // N*N*LogN, N <= 100 -> This is complexity of this problem
        for (int j = i + 1; j < n; j++) {
            if (snowDrift[i].first == snowDrift[j].first || snowDrift[i].second == snowDrift[j].second) {
                if (unionSet(i, j)) { // O(LogN)
                    differentSet--;
                }
            }
        }
    }

    cout << differentSet - 1 << endl;

    return 0;
}

// St
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

bool isSameSet(pair<int, int>& p1, pair<int, int>& p2) {
    return p1.first == p2.first || p1.second == p2.second;
}

int main() {
    int u, v, n;
    cin >> n;
    vector<pair<int, int>> p(n);

    for (int i = 0; i < n; ++i) {
        parent[i] = i;
        cin >> p[i].first >> p[i].second;

        for (int j = 0; j < i; j++) {
            if (isSameSet(p[i], p[j])) {
                unionSet(i, j);
            }
        }
    }

    int nGroup = 0;
    for (int i = 0; i < n; i++) {
        if (i == parent[i]) {
            nGroup++;
        }
    }

    cout << nGroup - 1;
    return 0;
}

//Py
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
    n = int(input())
    x = [0 for i in range(n)]
    y = [0 for i in range(n)]
    for i in range(n):
        x[i], y[i] = inp()
    ans = 0
    lab = [-1 for i in range(n)]
    cou = [1 for i in range(n)]

    for i in range(n):
        for j in range(i + 1, n):
            if x[i] == x[j] or y[i] == y[j]:
                u = getroot(lab, i)
                v = getroot(lab, j)
                if u != v:
                    union(lab, cou, u, v)

    # for i in range(n):
    #     for j in range(i + 1, n):
    #         u = getroot(lab, i)
    #         v = getroot(lab, j)
    #         if u != v:
    #             ans+=1
    #             union(lab, cou, u, v)
    # improve
    ans = lab.count(-1) - 1

    print(ans)
solve()