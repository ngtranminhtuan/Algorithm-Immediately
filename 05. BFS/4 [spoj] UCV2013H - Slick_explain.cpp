/*
Ta có thể thấy rằng hai ô (x, y) và ô (i,j) sẽ đi được với nhau nếu chúng có chung cạnh. Do đó, nếu có thể xem mỗi ô trên ma trận là một đỉnh của một đồ thị, thì hai đỉnh trên đồ thị sẽ có một cạnh nối với nhau nếu chúng thỏa mãn ba tính chất sau đây:

    + Hai ô được biểu diễn bởi hai đỉnh của đồ thị phải nằm trong phạm vi ma trận NxM.
    + Hai ô, không ô nào được phép biểu diễn bởi số 0 (cả hai ô đều là số 1).
    + Hai ô phải chung cạnh với nhau.
    Vì số lượng ô tối đa của một vũng dầu là NxM, nên để sắp xếp kích thước các vũng dầu theo thứ tự tăng dần và số vũng dầu của kích thước đó, ta chỉ cần tạo một mảng đếm NxM phần tử, sau đó chỉ cần duyệt từ 1 đến NxM và in số lượng vũng dầu có kích thước tương ứng.

Như vậy, sau khi ta xây dựng được một đồ thị vô hướng, ý tưởng của ta sẽ như sau:

    + Xác định vị trí của ô số 1, giả sử là ô (sx, sy).
    + Với mỗi ô (i, j) trong ma trận mà được biểu diễn bằng số 1, ta sẽ sử dụng kỹ thuật duyệt DFS hoặc BFS từ ô (i, j) để xem có thể đến được ô (sx, sy) hay không, nếu có thì ta sẽ cập nhật kích thước của vũng dầu đó lên 1. Sau khi duyệt hết tất cả ô liền kề có số 1, ta cập nhật số lượng vũng dầu có kích thước tương ứng lên 1.
    Lưu ý: với Python để tăng tốc độ xử lý, ta tự cài đặt queue sử dụng trong thuật toán BFS bằng list với hai con trỏ left để lấy phần tử đầu tiên và right để thêm phần tử vào cuối queue.

Độ phức tạp:

    Time Complexity: O(N∗M) với NN và MM lần lượt là độ dài của 2 cạnh của bảng.
    Space Complexity: O(N∗M).
*/
#include <bits/stdc++.h>
#define MAX 251
using namespace std;

const int dr[] = {0, 0, 1, -1};
const int dc[] = {1, -1, 0, 0};
int N, M;
int slick[MAX * MAX];
int table[MAX][MAX];

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
    table[s.r][s.c] = 0;
    int count = 1;

    while (!q.empty())
    {
        Cell u = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int r = u.r + dr[i];
            int c = u.c + dc[i];

            if (isValid(r, c) && table[r][c] == 1)
            {
                table[r][c] = 0;
                q.push((Cell){r, c});
                count++;
            }
        }
    }

    slick[count]++;
}

int main()
{
    while (true)
    {
        cin >> N >> M;

        if (N == 0 && M == 0)
        {
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> table[i][j];
                slick[i * M + j + 1] = 0;
            }
        }

        int nslicks = 0;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (table[i][j] == 1)
                {
                    nslicks++;
                    BFS((Cell){i, j});
                }
            }
        }

        cout << nslicks << endl;

        for (int i = 1; i <= N * M; i++)
        {
            if (slick[i])
            {
                cout << i << " " << slick[i] << endl;
            }
        }
    }

    return 0;
}