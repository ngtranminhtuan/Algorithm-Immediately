/*
Giải thích
    + Ví dụ trên có một bộ test.
    + Con đường dài nhất là con đường nối giữa địa điểm 4 và 6 và có độ dài 4 + 2 + 6 = 12.

    + Ảnh minh họa:
    https://drive.google.com/file/d/1FJ47htDYI3rs6k7k4v0vDUTnun0bEjqD/view?usp=sharing

-----------------------------------------------------------------------

Hướng dẫn giải

Xem danh sách được cho là một đồ thị với các đỉnh là các địa điểm trong thị trấn và con đường nối giữa hai địa điểm là một cạnh của đồ thị. Ta có:

    + Giữa hai đỉnh bất kì luôn chỉ có một cạnh nối -− đồ thị dạng cây (E = V – 1).
    + Độ dài lớn nhất giữa hai đỉnh bất kì chính là đường kính của cây.

Như vậy bài toán của ta trở thành bài toán tìm đường kính của cây. Ta lại có nhận xét đường kính của cây chính là khoảng cách lớn nhất giữa hai node lá. Như vậy nhiệm vụ của mình là phải tìm hai node lá này.

Giả sử ta thực hiện DFS từ một đỉnh bất kì. Điều chắn chắn rằng node có khoảng cách xa nhất từ điểm mà ta bắt đầu lan chính là một node lá cần tìm. Khi này chỉ cần sử dụng tiếp DFS để đi từ node lá mới tìm được là ta sẽ có được node lá thứ hai, đồng thời tính được khoảng cách giữa hai node lá đó, tức đường kính của cây. Thuật toán này có tên là “Double DFS” được mở rộng từ thuật toán DFS cơ bản.

Tóm lại, bài này ta có thể thực hiện như sau:

    + Bước 1: Đọc dữ liệu. Biết số cạnh = số đỉnh – 1 (tính chất của cây).
    + Bước 2: Khởi tạo biến lưu khoảng cách xa nhất từ node mà ta đang xét là max_dist = 0. Khai báo biến leaf lưu node lá.
    + Bước 3: Chạy DFS từ một đỉnh bất kì. Nếu tìm được đỉnh v có khoảng cách đến điểm bắt đầu lớn hơn max_dist:
    Cập nhật max_dist = dist[v]
    Cập nhật node lá leaf = v
    + Bước 4: Chạy DFS từ đỉnh f. Nếu tìm được đỉnh v có khoảng cách đến điểm bắt đầu lớn hơn max_dist thì cập nhật max_dist = dist[v].
    + Bước 5: In ra kết quả trong max_dist.

Độ phức tạp: O(T∗(V+E)) với V là số lượng đỉnh và E là số lượng cạnh của đồ thị và T là số lượng bộ test cho mỗi dataset.
*/
#include <bits/stdc++.h>
#define MAX 50000 + 5
using namespace std;

struct Triad
{
    int v, w;
};

int V, E, leaf;
long long max_dist;
long long dist[MAX];
vector<Triad> graph[MAX];

void DFS(int src)
{
    memset(dist, -1, sizeof(dist));
    stack<int> s;
    dist[src] = 0;
    s.push(src);

    while (!s.empty())
    {
        int u = s.top();
        s.pop();

        for (Triad &neighbor : graph[u])
        {
            int v = neighbor.v;
            int w = neighbor.w;

            if (dist[v] == -1)
            {
                dist[v] = dist[u] + w;
                s.push(v);

                if (dist[v] > max_dist)
                {
                    max_dist = dist[v];
                    leaf = v;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, u, v, w;
    cin >> t;

    while (t--)
    {
        cin >> V;
        E = V - 1;

        for (int i = 0; i <= V; i++)
        {
            graph[i].clear();
        }

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v >> w;
            graph[u].push_back((Triad){v, w});
            graph[v].push_back((Triad){u, w});
        }

        max_dist = 0;

        DFS(1);
        DFS(leaf);

        cout << max_dist << endl;
    }

    return 0;
}