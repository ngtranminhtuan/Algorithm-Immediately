// Problem: C. Sheep
// Link: https://www.spoj.com/problems/KOZE/cstart=20
//
// Complexity: O(n * m)

/*
Giải thích
    Trong ví dụ trên, ta thấy sẽ có tổng cộng 2 khu vực: các ô ở chính giữa và các ô nằm ngay sát đường biên. Bốn ô ở bốn góc không được tính là một khu vực bởi nó không được bao bởi hàng rào.

        + Khu vực các ô nằm sát đường biên: Gồm 3 cừu và 2 sói, do đó các con sói sẽ chết. Vì thế số lượng cừu còn sống là 3.
        + Khu vực 4 ô ở giữa: Gồm 1 cừu và 1 sói, do đó cừu sẽ bị sói ăn thịt. Vì thế số lượng sói còn sống là 1. Như vậy tổng số lượng cừu còn sống là 3 và sói là 1.
------------------------------------------------------------------------

Ta sẽ lần lượt kiểm tra từng khu vực, tại mỗi khu vực, ta dùng BFS và làm 2 điều sau:
    + Kiểm tra xem có 1 ô nào nằm trên đường biên hay ko. Nếu như có 1 ô nằm trên đường biên thì khu vực này có đường thoát và cừu có thể chạy đi hết. Trong trường hợp này thì mọi con cừu và mọi con sói trong trong "khu vực" mở này sẽ sống.
    + Đếm số lượng cừu và sói trong khu vực.
        + Nếu như số cừu lớn hơn số sói thì mọi con cừu đều sẽ sống và mọi con sói chết.
        + Nếu như ngược lại thì mọi con cừu sẽ chết và mọi con sói sống.

Độ phức tạp: O(n * m) với n và m lần lượt là kích thước của khu vườn.
*/

#include <bits/stdc++.h>
#define MAX 500 + 1
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int N, M;
int nsheeps, nwolves;
string backyard[MAX];

struct Cell
{
    int r, c;
};

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < N && c < M;
}

void BFS(Cell s)
{
    queue<Cell> q;
    q.push(s);

    int sheep = (backyard[s.r][s.c] == 'k');
    int wolf = (backyard[s.r][s.c] == 'v');

    bool canEscape = false;
    backyard[s.r][s.c] = '#';

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (!isValid(r, c))
            {
                canEscape = true;
                continue;
            }

            if (backyard[r][c] != '#')
            {
                sheep += (backyard[r][c] == 'k');
                wolf += (backyard[r][c] == 'v');
                backyard[r][c] = '#';
                q.push((Cell){r, c});
            }
        }
    }

    if (canEscape)
    {
        nsheeps += sheep;
        nwolves += wolf;
    }
    else
    {
        sheep > wolf ? nsheeps += sheep : nwolves += wolf;
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
    {
        cin >> backyard[i];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (backyard[i][j] != '#')
            {
                BFS((Cell){i, j});
            }
        }
    }

    cout << nsheeps << " " << nwolves;
    return 0;
}