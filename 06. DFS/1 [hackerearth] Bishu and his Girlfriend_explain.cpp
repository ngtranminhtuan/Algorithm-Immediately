/*
Chạy thuật toán DFS, sau đó lấy lần lượt từng vùng đất của các cô gái rồi tìm đường đi tới vùng đất số 1. Lấy vùng đất có lượng đường đi qua các đỉnh là ít nhất. Để chọn ID nhỏ thì chỉ khi vùng đất nào thật sự lớn hơn vùng đất hiện tại bạn mới cập nhật lại. Nếu bằng thì cũng không cập nhật.

Bạn cũng có thể cải tiến một chút bằng cách chạy thuật toán từ vùng đất số 1 mà Bishu đang đứng để lấy kết quả đường đi đến các vùng đất mà các cô gái đang đứng. Cách này sẽ đỡ phải mất thời gian chạy đi chạy lại DFS nhiều lần.

Độ phức tạp: O(V+E+Q) với V là số lượng đỉnh của cây, E=V−1 là số lượng cạnh của cây và Q là số lượng vùng đất cô gái đang ở.
*/
#include <bits/stdc++.h>
#define MAX 1000 + 5
using namespace std;

int V, E;
bool visited[MAX];
int dist[MAX];
vector<int> graph[MAX];

void DFS(int scr)
{
    stack<int> s;
    visited[scr] = true;
    s.push(scr);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        for (int &v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                s.push(v);
            }
        }
    }
}

int main()
{
    int Q, u, v;
    cin >> V;
    E = V - 1;

    for (int i = 0; i < E; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    DFS(1);
    int ans = 0, min_dist = MAX;
    cin >> Q;

    for (int i = 0; i < Q; i++)
    {
        cin >> u;

        if (dist[u] < min_dist || (dist[u] == min_dist && u < ans))
        {
            min_dist = dist[u];
            ans = u;
        }
    }

    cout << ans;
    return 0;
}