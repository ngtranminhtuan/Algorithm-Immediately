// Problem: 459 - Graph Connectivity
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400

// Complexity: O(M * LogN), M <= 26^2, N <= 26

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 'Z'-'A'+1
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
    int tc;
    scanf("%d\n\n", &tc);

    int N, M, i, j;
    string s;
    int differentSet;
    while (tc--) {
        getline(cin, s);
        N = s[0] - 'A' + 1; // This character represents the largest node name in the graph

        differentSet = N;
        makeSet(N);

        M = 0;
        while (true) { // O(M * LogN), M <= 26^2, N <= 26 -> This is complexity of this solution
            if (!getline(cin,s) || s.empty())
                break;

            i = s[0] - 'A';
            j = s[1] - 'A';

            if (unionSet(i, j)) { // Log(N)
                differentSet--;
            }
            M++;
        }

        cout << differentSet << endl;
        if (tc > 0)
            cout << endl;
    }

    return 0;
}

// St
#include <bits/stdc++.h> 

using namespace std;

int parent[26];

int test , n , u , v , ans; 
char c;
string s;

void init(int u) {
    parent[u] = u;
}

int findSet(int u) {
    while (u != parent[u]) u = parent[u]; 

    return u; 
}

int unionSet(int u , int v){
    int up = findSet(u); int vp = findSet(v); 

    parent[vp] = up; 
}

int main() {
    scanf("%d\n\n" , &test); 
    
    for(int t = 1; t <= test; t++) {
        getline(cin,s);
        n = s[0] - 'A' + 1; 
        
        ans = n; 
        for (int i = 0; i < n; i++) init(i); 
        
        while(1) {
            if (!getline(cin , s) || s.empty()) break; 
            
            u = s[0] - 'A'; v = s[1] - 'A'; 
            
            int up = findSet(u); int vp = findSet(v); 

            if (up != vp) {
                ans--; 
                unionSet(u , v); 
            }
        }
        
        if (t != 1) printf("\n"); 
        printf("%d\n" , ans); 
    }
    
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

def convert_number(x):
    return ord(x) - ord('A')

def solve():
    inf = sys.stdin
    input = []
    for line in inf:
        input.append(line)
    len_input = len(input)
    k = 0
    testcase = int(input[k])
    k+=1
    for t in range(testcase):
        k+=1
        x = list(input[k])[0]
        k+=1
        n = convert_number(x) + 1
        lab = [-1 for i in range(n)]
        cou = [1 for i in range(n)]
        while k < len_input and input[k] != '\n':
            temp = list(input[k])
            u = convert_number(temp[0])
            v = convert_number(temp[1])
            k+=1
            u = getroot(lab, u)
            v = getroot(lab, v)
            if u != v:
                union(lab, cou, u, v)
        ans = lab.count(-1)
        if t == testcase - 1:
            print(ans)
        else:
            print("{}\n".format(ans))

solve()