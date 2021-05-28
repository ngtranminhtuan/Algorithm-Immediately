/*
Giải thích
    + Case 1 : 0 is friends with 1; 1 is friends with 2; so if we pass the news to 0 & 3, news will pass it to the entire N peers.

    + Case 2 : no one is friends with any one. So we have to meet every one in person.

Lần lượt chạy DFS cho các đỉnh, nếu mỗi lần chạy vẫn còn đỉnh nào có giá trị false nghĩa là vẫn còn nhóm nào đó khác nhóm trước đã chạy. Bạn sẽ tăng biến đếm lên. Khi chạy hết N đỉnh thì kết quả cuối cùng là biến đếm.

Độ phức tạp: O(T∗(V+E)) với T là số lượng bộ dữ liệu, O(V+E) là độ phức tạp của thuật toán DFS với V là số lượng đỉnh của đồ thị và E là số lượng cạnh của đồ thị.
*/

#include <bits/stdc++.h>
#define MAX 100000 + 5
using namespace std;

int V, E;
bool visited[MAX];
vector<int> graph[MAX];

void DFS(int scr) {
    stack<int> s;
    visited[scr] = true;
    s.push(scr);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        for (int &v : graph[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}

int main() {
    int Q, u, v;
    cin >> Q;

    while (Q--) {
        cin >> V >> E;

        for (int i = 0; i < V; i++) {
            visited[i] = false;
            graph[i].clear();
        }

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        int count = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                count++;
                DFS(i);
            }
        }

        cout << count << endl;
    }
    return 0;
}

// -----------
def DFS(src):
    s = [src]
    visited[src] = True

    while len(s):
        u = s.pop()
        
        for v in graph[u]:
            if not visited[v]:
                visited[v] = True
                s.append(v)
    
Q = int(input())

for _ in range(Q):
    line = ''
    while line == '':
        line = input().strip()

    V = int(line)
    E = int(input())
    graph = [[] for _ in range(V)]
    visited = [False] * V

    for i in range(E):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)
    
    count = 0

    for i in range(V):
        if not visited[i]:
            count += 1
            DFS(i)
    
    print(count)