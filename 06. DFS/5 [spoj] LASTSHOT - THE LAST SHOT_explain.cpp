/*
Vì bạn cần lựa chọn để châm ngòi nổ 1 quả bom sao cho số lượng quả bom nổ được là lớn nhất, do đó cách đơn giản nhất là bạn sẽ thử châm ngòi nổ từng quả và đếm xem khi một quả nổ thì sẽ kéo theo có tổng cộng bao nhiêu quả nổ và chọn ra tổng số quả nổ lớn nhất. Để đếm xem có bao nhiêu quả nổ khi quả bom thứ i được châm ngòi, bạn hãy sử dụng kỹ thuật duyệt DFS với đỉnh xuất phát là đỉnh thứ i.

Độ phức tạp: O(V∗(V+E)) với V là số lượng đỉnh, và E là số lượng cạnh của đồ thị.
*/
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int N, M;
bool visited[MAX];
vector<int> graph[MAX];

int DFS(int src)
{
    memset(visited, false, sizeof(visited));
    stack<int> s;
    visited[src] = true;
    s.push(src);

    int nbombs = 0;

    while (!s.empty())
    {
        int u = s.top();
        s.pop();
        nbombs++;

        for (int &v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;
                s.push(v);
            }
        }
    }

    return nbombs;
}

int main()
{
    int u, v;
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
    }

    int max_bombs = 0;

    for (int i = 1; i <= N; i++)
    {
        max_bombs = max(max_bombs, DFS(i));
    }

    cout << max_bombs;
    return 0;
}