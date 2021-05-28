/*
Bạn có thể thấy rằng hai ô (x, y) và ô (i, j) sẽ đi được với nhau nếu chúng có chung cạnh. Do đó, nếu bạn có thể xem mỗi ô trên bảng là một đỉnh của một đồ thị, thì hai đỉnh trên đồ thị sẽ có một cạnh nối với nhau nếu chúng thỏa mãn ba tính chất sau đây:

    + Hai ô được biểu diễn bởi hai đỉnh của đồ thị phải nằm trong bảng đầu vào.

    + Hai ô, không ô nào được phép biểu diễn bởi ký tự ‘#’.

    + Hai ô phải chung cạnh với nhau.

Như vậy, sau khi ta xây dựng được một đồ thị vô hướng, cách đơn giản để giải quyết bài này là:

    + Ta đi xác định vị trí của ô ‘@’, giả sử là ô (sx, sy)(sx,sy).

    + Sau đó, với mỗi ô (i, j) trong bảng được biểu diễn bằng dấu ‘.’, ta sẽ sử dụng kỹ thuật duyệt BFS/DFS từ ô (i, j) để xác định xem có thể đến được ô (sx, sy) hay không. Nếu có, ta tăng biến kết quả ans lên 1.

    + Kết quả là ans + 1 (Tính cả ô (sx, sy)).

Phải xét mỗi ô (i, j) có đến được ô (sx, sy) hay không như vậy khá tốn thời gian, ta có một cách khác để cải tiến thuật toán ở trên:

    + Dựa vào một nhận xét tự nhiên, ta thấy mọi ô giả sử có đường đi đến ô (sx, sy)(sx,sy) thì chúng đều sẽ tập trung lại tại ô (sx , sy). Do đó, nếu như ta nhìn nhận bài toán ở một khía cạnh khác, chúng ta sẽ phát hiện rằng: thay vì với mỗi ô (i, j), ta kiểm tra xem có đường đi tới (sx,sy), thì bây giờ ta sẽ xuất phát từ ô (sx , sy), đi loang ra các đỉnh khác, mỗi lần ta tiếp cận được với một đỉnh mà chưa được xét thì ta sẽ tăng biến ans lên 1 đơn vị. Kết quả là ans.

Độ phức tạp:

Cách chưa cải tiến:

    + Time Complexity: O(T∗W∗W∗H∗H)

    + Space Complexity: O(W∗H)

    + W và H không quá 20 nên độ phức tạp O(T∗W∗W∗H∗H) vẫn có thể chấp nhận được.

Cách cải tiến:

    + Time Complexity: O(T∗W∗H) với W và H lần lượt là chiều rộng và chiều cao của bảng, còn T là số lượng bộ test đầu vào.

*/
#include <bits/stdc++.h>
#define MAX 21
using namespace std;
 
const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int W, H;
bool visited[MAX][MAX];
char maze[MAX][MAX];
 
struct Cell {
    int r, c;
};
 
bool isValid(int r, int c) {
    return r >= 0 && c >= 0 && r < H && c < W;
}
 
int BFS(Cell s) {
    queue<Cell> q;
    q.push(s);
    visited[s.r][s.c] = true;
    int count = 1;
 
    while (!q.empty()) {
        Cell u = q.front();
        q.pop();
 
        for (int i = 0; i < 4; i++) {
            int r = u.r + dr[i];
            int c = u.c + dc[i];
 
            if (isValid(r, c) && maze[r][c] == '.' && !visited[r][c]) {
                visited[r][c] = true;
                q.push((Cell) {r, c});
                count++;
            }
        }
    }
 
    return count;
}
 
int main() {
    Cell s;
    int Q;
    cin >> Q;
 
    for (int k = 1; k <= Q; k++) {
        cin >> W >> H;
 
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> maze[i][j];
                 
                if (maze[i][j] == '@') {
                    s.r = i;
                    s.c = j;
                }
                 
                visited[i][j] = false;
            }
        }
 
        cout << "Case " << k << ": " << BFS(s) << endl;
    }
    return 0;
}

// -------------
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
    return r in range(H) and c in range(W)
 
def BFS(s):
    q = queue.Queue()
    q.put(s)
    visited[s.r][s.c] = True
    count = 1
 
    while not q.empty():
        u = q.get()
 
        for i in range(4):
            r = u.r + dr[i]
            c = u.c + dc[i]
 
            if isValid(r, c) and maze[r][c] == '.' and not visited[r][c]:
                visited[r][c] = True
                q.put(Cell(r, c))
                count += 1
     
    return count
 
Q = int(input())
 
for k in range(1, Q + 1):
    W, H = map(int, input().split())
 
    for i in range(H):
        maze[i] = input()
     
    for i in range(H):    
        for j in range(W):
            if maze[i][j] == '@':
                s = Cell(i, j)
            visited[i][j] = False
 
    print("Case {}: {}".format(k, BFS(s)))