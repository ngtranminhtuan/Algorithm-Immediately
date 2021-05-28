// Problem: ALL IZZ WELL
// Link: https://www.spoj.com/problems/ALLIZWEL/cstart=20

/*
Để kiểm tra xem có đường đi nào tạo thành chuỗi ALLIZZWELL hay không, ta sẽ thực hiện chạy DFSDFS từ tất cả các ô chứa ký tự A - ký tự bắt đầu của chuỗi đề cho. Với mỗi bước đi, ta chọn các ô có chứa ký tự tiếp theo trong chuỗi ALLIZZWELL. Nếu đạt tới ký tự cuối cùng trong chuỗi nghĩa là ta đã có một đường đi hợp lệ tạo thành chuỗi đề cho.

Ta lưu ý rằng nếu có bất cứ ô nào thỏa điều kiện là ký tự kế tiếp trong chuỗi, ta chưa thể kết luận là toàn bộ đường đi đó không thể tạo thành chuỗi ALLIZZWELL, hay nói cách khác là ta không thể duyệt qua một lần đỉnh u và đánh dấu visited_u = truevisited
​u
​​ =true.

Chẳng hạn nếu ta đã tìm được một đường đi A→L→L→I→Z→Z→W nhưng ô tiếp theo ta xét lại là ô có ký tự L - không giống ký tự ta mong đợi là E. Tuy nhiên ta cần hiểu rằng ta không thể loại bỏ ký tự L này được vì rất có thể về sau khi ta đã tìm được một đường đi A→L→L→I→Z→Z→W→E thì ký tự L đó có thể là một đỉnh hợp lệ trong đường đi của ta.

Do đó, ta sẽ sử dụng kỹ thuật Backtracking (quay lui) như sau:

    + Với mỗi đỉnh u = s_i, ta đánh dấu u là một đỉnh trong đường đi visited_u = true.
    + Chạy DFS từ ký tự i+1 về sau.
    + Đánh dấu lại visited_u = false để tái sử dụng (nếu có thể) trong những đường đi khác.

Độ phức tạp: O(t*(R^2*C^2)) với t là số lượng bộ test,R,C là số dòng và số cột của từng ma trận trong mỗi testcase.
*/

#include <bits/stdc++.h>
#define MAX 101
using namespace std;

const string term = "ALLIZZWELL";
int R, C;
bool found;
int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};
bool visited[MAX][MAX];
char table[MAX][MAX];

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < R && c < C;
}

void DFS(int sr, int sc, int count)
{
    if (count == term.size())
    {
        found = true;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        int r = sr + dr[i];
        int c = sc + dc[i];

        if (isValid(r, c) && table[r][c] == term[count] && !visited[r][c])
        {
            visited[r][c] = true;
            DFS(r, c, count + 1);
            visited[r][c] = false;
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        cin >> R >> C;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> table[i][j];
                visited[i][j] = false;
            }
        }

        found = false;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (table[i][j] == term[0] && !found)
                {
                    DFS(i, j, 1);
                }
            }
        }

        cout << (found ? "YES" : "NO") << endl;
    }
    return 0;
}

// -------
import sys
sys.setrecursionlimit(100000)

dr = [0, 0, 1, 1, 1, -1, -1, -1]
dc = [1, -1, 0, 1, -1, 0, 1, -1]
term = "ALLIZZWELL"

def DFS(sr, sc, count):
    global found, table, visited
    if count == len(term):
        found = True
        return
    
    for i in range(8):
        r = sr + dr[i]
        c = sc + dc[i]

        if r in range(R) and c in range(C) and table[r][c] == term[count] and not visited[r][c]:
            visited[r][c] = True
            DFS(r, c, count + 1)
            visited[r][c] = False
    
T = int(input())

for _ in range(T):
    R, C = map(int, input().split())
    table = []
    visited = [[False] * C for _ in range(R)]

    for i in range(R):
        table.append(input())
    
    found = False

    for i in range(R):
        for j in range(C):
            if table[i][j] == term[0] and not found:
                DFS(i, j, 1)
    
    print("YES" if found else "NO")
    input()

