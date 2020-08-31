/*
Với bài này, ta phải thử đi hết các đường đi từ nút gốc (nhà Kefa) đến tất cả nút lá (nhà hàng) để xem có bao nhiêu nút lá có thể đến được. Vậy ta sẽ sử dụng BFS để giải quyết bài này.

Số đỉnh đánh dấu từ 11 nên khi lưu trữ dữ liệu và chạy BFS, ta cũng bắt đầu từ 11. Dùng một mảng chứa số lượng mèo xuất hiện khi đi từ đỉnh 11 đến đỉnh ii, đồng thời dùng một biến để đếm số nút lá (nhà hàng) có thể đến được.

Đầu tiên ta phải xét liệu đỉnh 1 có chứa mèo, nếu có thì tăng số mèo ở đỉnh này lên 1.

Kefa chỉ đi đến nhà hàng khi đường đó không xuất hiện quá M con mèo, nên ta chỉ cần xét những đỉnh mà số lượng mèo xuất hiện nhỏ hơn hoặc bằng M, lớn hơn M không cần xét nữa.

Vậy khi chạy BFS, thực hiện xét các đỉnh kề với đỉnh đang xét uu, nếu đỉnh kề vv chưa thăm thì đánh dấu đã thăm. Đồng thời, nếu đỉnh đó chứa mèo thì cập nhật lại cat[v] = cat[u] + 1, và nếu cat[v] nhỏ hơn hoặc bằng M thì kiểm tra nếu số đỉnh kề với v là 1 (đồng nghĩa với việc chỉ có 1 đỉnh đi đến đỉnh v hay v là nút lá) thì tăng biến đếm lên, ngược lại ta đẩy đỉnh v vào hàng đợi.

Độ phức tạp: O(V+E) với V và E lần lượt là số lượng đỉnh và cạnh của đồ thị.
*/
#include <bits/stdc++.h>
#define MAX 100000 + 5
using namespace std;

int n, m;
int a[MAX], cat[MAX];
bool visited[MAX];
vector<int> graph[MAX];

int BFS(int s)
{
    int nrestaurants = 0;
    queue<int> q;
    visited[s] = true;
    q.push(s);

    cat[s] = (a[s] == 1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int &v : graph[u])
        {
            if (!visited[v])
            {
                visited[v] = true;

                if (a[v] == 1)
                {
                    cat[v] = cat[u] + 1;
                }

                if (cat[v] <= m)
                {
                    if (graph[v].size() == 1)
                    {
                        nrestaurants++;
                    }
                    else
                    {
                        q.push(v);
                    }
                }
            }
        }
    }

    return nrestaurants;
}

int main()
{
    int u, v;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << BFS(1);
    return 0;
}