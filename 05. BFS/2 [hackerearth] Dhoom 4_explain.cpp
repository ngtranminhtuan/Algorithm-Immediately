/*
Nếu xem mỗi giá trị mà chìa khóa có thể nhận được là một đỉnh của đồ thị và mỗi phép nhân chìa khóa với một số bất kỳ trong N số được cho tạo nên một cạnh của đồ thị thì ta có thể sử dụng giải thuật BFS cho bài toán này như sau:

    + Bước 1: Xác định đỉnh xuất phát là giá trị ban đầu của chìa khóa.
    + Bước 2: Xác định đỉnh đích là giá trị khóa cần đạt được.
    + Bước 3: Duyệt BFS từ đỉnh xuất phát. Mỗi lần lấy ra một đỉnh u từ hàng đợi, ta thực hiện phép nhân giá trị của đỉnh đó với lần lượt từng số trong N số được cho. Kết quả thu được từ phép nhân trên được mod cho 100.000 chính là một đỉnh v mới trong đồ thị. Bước làm này chính là ta đang phát sinh các cạnh (u, v) có thể có của đồ thị.

Lưu ý trong quá trình duyệt, ta sử dụng thêm một mảng dist[] với dist[v] là độ dài đường đi ngắn nhất từ đỉnh xuất phát đến đỉnh v. Như vậy khi ta tìm được một đỉnh v có giá trị đúng bằng giá trị đỉnh đích thì ta xuất ra ngay giá trị của dist[v].

Ngoài ra khi thực hiện phép nhân chìa khóa, ta phải cẩn thận vì có thể xảy ra trường hợp bị tràn số.

Độ phức tạp:

Time Complexity: Vì các đỉnh trên đồ thị, khi đã thăm rồi thì không được thăm lại nữa, do đó ta lấy tối đa chỉ có 100.000 đỉnh ra khỏi hàng đợi. Mặt khác, với từng đỉnh ta lấy ra khỏi hàng đợi, ta cần duyệt thêm N khóa nữa để có thể sinh ra các khóa mới. Như vậy, độ phức tạp thuật toán theo lý thuyết là O(100.000∗N).
Space Complexity: O(100.000).
*/

#include <bits/stdc++.h>
#define MAX 100000 + 5
#define MOD 100000
using namespace std;

int N;
int dist[MAX];
int a[MAX];

int BFS(int s, int f)
{
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int i = 0; i < N; i++)
        {
            int v = (1LL * a[i] * u) % MOD;

            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);

                if (v == f)
                {
                    return dist[v];
                }
            }
        }
    }

    return -1;
}

int main()
{
    int s, f;
    cin >> s >> f >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }

    cout << BFS(s, f);
    return 0;
}

//-------
import queue
MAX = 100000 + 5
MOD = 100000
 
def BFS(s, f):
    dist = [-1] * MAX
    q = queue.Queue()
    q.put(s)
    dist[s] = 0
 
    while not q.empty():
        u = q.get()
 
        for x in a:
            v = (x * u) % MOD
 
            if dist[v] == -1:
                dist[v] = dist[u] + 1
                q.put(v)
 
                if v == f:
                    return dist[v]
     
    return -1
 
s, f = map(int, input().split())
N = int(input())
a = list(map(int, input().split()))
print(BFS(s, f))