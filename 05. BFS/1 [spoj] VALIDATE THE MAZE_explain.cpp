/*
Bài toán này bạn sẽ có hai cách giải:

Cách 1:

    + Bạn sẽ chuyển toàn bộ đồ thị đã cho về ma trận kề hoặc danh sách kề, bằng cách duyệt qua toàn bộ ma trận, hai đỉnh được nối với nhau khi và chỉ khi có thể đi từ “.” này đến “.” kia.

    + Bạn có thể đặt đỉnh ở tọa độ (0,0) là đỉnh 0, (0,1) là đỉnh 1, … lần lượt như vậy. Nếu đồ thị có 4x4 thì bạn sẽ có 16 đỉnh (từ 0 đến 15).

    + Bước tiếp theo bạn sẽ xem đỉnh nào ở rìa ma trận thì sẽ đặt đỉnh đó là đỉnh vào hoặc đỉnh ra, bạn cần tìm đủ 2 đỉnh như vậy rồi chạy BFS. Nếu có đường đi thì bạn sẽ in ra “valid” ngược lại bạn sẽ in ra “invalid”.

    ---→ Nhận xét: Với cách giải này bạn sẽ tốn thời gian chuẩn bị lại đồ thị cho đúng định dạng.

Cách 2:

    Bạn sẽ chạy BFS trên mê cung đã cho mà không cần phải chuyển lại thành dạng ma trận kề hay danh sách kề. Cách này bạn phải thêm và chỉnh lại một số dòng code để chạy phù hợp.

    Ban đầu, bạn cũng sẽ tìm hai điểm đầu vào và đầu ra. Từ điểm đầu ra bạn sẽ xác định 44 hướng đi (lên, xuống, trái, phải). Nếu có đường đi, nghĩa là gặp dấu “.” và nằm trong giới hạn của mê cung thì bạn sẽ dịch chuyển bước đi của mình xuống điểm mới. Lần lượt đi đến khi nào gặp đỉnh đầu ra thì dừng. Lúc này sẽ in ra là “valid”, ngược lại nếu đi mà không thấy đường ra sẽ in ra “invalid”.

Độ phức tạp: O(T∗R∗C) với T,R,C lần lượt là số lượng test, số dòng và số cột của ma trận.
*/

#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define MAX 21

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int n, m;
bool visited[MAX][MAX];
string maze[MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c)
{
    return r >= 0 && r < n && c >= 0 && c < m;
}

bool BFS(Cell s, Cell f)
{
    queue<Cell> q;
    visited[s.r][s.c] = true;
    q.push(s);

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        if (u.r == f.r && u.c == f.c)
        {
            return true;
        }

        for (int i = 0; i < 4; i++)
        {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c])
            {
                visited[r][c] = true;
                q.push((Cell){r, c});
            }
        }
    }

    return false;
}

int main()
{
    int Q;
    cin >> Q;

    while (Q--)
    {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            cin >> maze[i];
        }

        vector<Cell> entrance;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
                if (maze[i][j] == '.' && (i == 0 || j == 0 || i == n - 1 || j == m - 1))
                {
                    entrance.push_back((Cell){i, j});
                }
            }
        }

        if (entrance.size() != 2)
        {
            cout << "invalid" << endl;
        }
        else
        {
            Cell s = entrance[0];
            Cell f = entrance[1];
            cout << (BFS(s, f) ? "valid" : "invalid") << endl;
        }
    }
    return 0;
}

//-------------
import queue
 
dr = [0, 0, 1, -1]
dc = [1, -1, 0, 0]
MAX = 21
visited = [[False] * MAX for _ in range(MAX)]
maze = [None] * MAX
 
class Cell:
    def __init__(self, _r, _c):
        self.r = _r
        self.c = _c
 
def isValid(r, c):
    return r in range(n) and c in range(m)
 
def BFS(s, f):
    q = queue.Queue()
    visited[s.r][s.c] = True
    q.put(s)
 
    while not q.empty():
        u = q.get()
        if u.r == f.r and u.c == f.c:
            return True
 
        for i in range(4):
            r = u.r + dr[i]
            c = u.c + dc[i]
 
            if isValid(r, c) and maze[r][c] == '.' and not visited[r][c]:
                visited[r][c] = True
                q.put(Cell(r, c))
     
    return False
 
Q = int(input())
 
for _ in range(Q):
    n, m = map(int, input().split())
 
    for i in range(n):
        maze[i] = input()
     
    entrance = []
 
    for i in range(n):
        for j in range(m):
            visited[i][j] = False
            if maze[i][j] == '.' and (i == 0 or j == 0 or i == n - 1 or j == m - 1):
                entrance.append(Cell(i, j))
     
    if (len(entrance)) != 2:
        print("invalid")
    else:
        s = entrance[0]
        f = entrance[1]
        print("valid" if BFS(s, f) else "invalid")