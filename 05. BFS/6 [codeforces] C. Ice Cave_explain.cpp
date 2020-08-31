// Problem: C. Ice Cave
// Link: https://codeforces.com/problemset/problem/540/C
//
// Complexity: O(n * m)

/*
Trong ví dụ trên, ta thấy sẽ có tổng cộng 2 khu vực: các ô ở chính giữa và các ô nằm ngay sát đường biên. Bốn ô ở bốn góc không được tính là một khu vực bởi nó không được bao bởi hàng rào.

    + Khu vực các ô nằm sát đường biên: Gồm 3 cừu và 2 sói, do đó các con sói sẽ chết. Vì thế số lượng cừu còn sống là 3.
    + Khu vực 4 ô ở giữa: Gồm 1 cừu và 1 sói, do đó cừu sẽ bị sói ăn thịt. Vì thế số lượng sói còn sống là 1. Như vậy tổng số lượng cừu còn sống là 3 và sói là 1.
------------------------------------------------------------------------
Bạn bắt đầu đi từ ô bị nứt (X) sau đó bạn phải đi được tới đích bằng những đường đấu “.” (ô nguyên) • Nếu ô đích của bạn là ô X (ô nứt) thì bạn chỉ cần 1 đường đi tới đó. Vì nhiệm vụ của bạn là thoát khỏi Level này nên cần gặp ô nứt để qua Level khác. • Nếu ô đích của bạn là “.” thì phải đi đến được đó và xung quanh của ô đó phải có ít nhất 1 ô “.” Để sau khi bạn nhảy xong 1 lần nó trở thành ô nứt rồi bạn nhảy qua ô khác rồi nhảy lại để qua được Level đó.

Độ phức tạp: O(n * m) với n và m lần lượt là kích thước của bảng.
*/

#include <bits/stdc++.h>
#define MAX 500 + 1
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int n, m;
char level[MAX][MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < n && c < m;
}

bool BFS(Cell s, Cell f)
{
    queue<Cell> q;
    level[s.r][s.c] = 'X';
    q.push(s);

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (r == f.r && c == f.c && level[r][c] == 'X')
            {
                return true;
            }

            if (isValid(r, c) && level[r][c] == '.')
            {
                level[r][c] = 'X';
                q.push((Cell){r, c});
            }
        }
    }

    return false;
}

int main()
{
    Cell s, f;
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> level[i][j];
        }
    }

    cin >> s.r >> s.c >> f.r >> f.c;
    s.r -= 1, s.c -= 1, f.r -= 1, f.c -= 1;

    cout << (BFS(s, f) ? "YES" : "NO");
    return 0;
}