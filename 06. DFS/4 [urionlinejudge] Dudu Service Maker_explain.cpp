/*
Đồ thị chỉ có thể tồn tại chu trình chỉ khi nào có một cạnh nối từ u đến một đỉnh v nào đó được thăm trước đó, đồng thời từ v phải đến được u.
Do đó ta cần thêm một mảng để truy vết đường đi và kiểm tra điều kiện trên, tạm gọi là mảng path.
Như vậy, ý tưởng giải cơ bản sẽ là sử dụng DFS để duyệt qua từng đỉnh, với mỗi đỉnh u đang xét, ta duyệt qua từng đỉnh v kề với u:

Nếu v chưa thăm thì ta duyệt DFS(v).
Nếu v thăm rồi, lúc này cần kiểm tra trong mảng path xem từ v có đến được u hay không, nếu đến được thì chứng tỏ có chu trình.

Độ phức tạp: O(N) với mỗi đỉnh ---→ O(N^2) cho toàn đồ thị.

Như vậy ta cần cải tiến để kiểm tra nhanh xem từ v có đến được u hay không.
Nhận xét: Nếu từ v đến được u thì v sẽ nằm trên đường đi từ gốc DFS đến u. Như vậy, nếu mình đánh dấu lại các đỉnh thuộc đường đi từ gốc đến u, thì có thể kiểm tra nhanh v có thuộc đường đi đó hay không, đồng nghĩa với việc từ v có đến được u hay không.
Do đó thay vì dùng mảng path, ta dùng một mảng là inPath với inPath_i = true nếu i nằm trên đường đi từ gốc DFS đến đỉnh u đang xét, ngược lại inPath_i = false.
Khi mình duyệt xong DFS(u), thì lúc trở về đỉnh cha của u, chắc chắn u không nằm trên đường đi từ gốc đến cha của u, nên cần gán lại inPath_u = false trước khi thoát khỏi DFS(u).
Ngoài ra, còn một cách xử lý nữa là sử dụng mảng visited, nhưng thay vì lúc này chỉ đánh dấu 0/1(false/true) thì lúc này mình đánh dấu 3 giá trị nhằm mục đích sử dụng nó để thực hiện chức năng của cả 2 mảng visited và path ở cách trên:

    + visited_u = 0 nếu u chưa được duyệt (tức visited_u = false và inPath_u = false theo cách vừa trình bày).
    + visited_u = 1 nếu u đã được duyệt và ta đang duyệt các đỉnh kề với u (visited_u = true và inPath_u = true).
    + visited_u = 2 nếu u đã được duyệt và đã duyệt xong các đỉnh kề với u (visited_u = false và inPath_u = false).

Độ phức tạp: O(V + E) với V,E lần lượt là số lượng đỉnh và số lượng cạnh của đồ thị. Tuy nhiên, cách sử dụng mảng visited 3 giá trị sẽ ít tốn bộ nhớ hơn.
*/
#include <bits/stdc++.h>
#define MAX 10005
using namespace std;

int N, M;
int visited[MAX];
vector<int> graph[MAX];

bool DFS(int u)
{
    visited[u] = 1;

    for (int &v : graph[u])
    {
        if (visited[v] == 1)
        {
            return true;
        }
        else if (visited[v] == 0)
        {
            if (DFS(v))
            {
                return true;
            }
        }
    }

    visited[u] = 2;
    return false;
}

int main()
{
    int T, u, v;
    cin >> T;

    while (T--)
    {
        cin >> N >> M;

        for (int i = 1; i <= N; i++)
        {
            graph[i].clear();
            visited[i] = 0;
        }

        for (int i = 0; i < M; i++)
        {
            cin >> u >> v;
            graph[u].push_back(v);
        }

        bool isCyclic = false;

        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0)
            {
                isCyclic = DFS(i);
                if (isCyclic)
                {
                    break;
                }
            }
        }

        cout << (isCyclic ? "YES" : "NO") << endl;
    }
    return 0;
}

// ---------
import sys
visited = [False] * 10005
graph = [[] for _ in range(10005)]
 
sys.setrecursionlimit(10005)
def DFS(u):
    visited[u] = 1
 
    for v in graph[u]:
        if visited[v] == 1:
            return True
        elif visited[v] == 0:
            if DFS(v):
                return True
     
    visited[u] = 2
    return False
 
T = int(input())
 
for _ in range(T):
    N, M = map(int, input().split())
 
    for i in range(N + 1):
        graph[i].clear()
        visited[i] = 0
     
    for i in range(M):
        u, v = map(int, input().split())
        graph[u].append(v)
     
    isCyclic = False
 
    for i in range(1, N + 1):
        if visited[i] == 0:
            isCyclic = DFS(i)
            if isCyclic:
                break
     
    print("YES" if isCyclic else "NO")