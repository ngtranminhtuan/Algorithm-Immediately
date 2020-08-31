// Problem: ABC Path
// Link: https://www.spoj.com/problems/ABCPATH/

/*
Giải thích
Trong ví dụ trên có một vài đường đi từ A đến D nhưng không có đường nào đi từ A đến E, nên đường đi dài nhất là 4 đi từ A đến D.
--------------------------------------------------------------------

Hướng dẫn giải
    Ta có thể nhận thấy rằng việc duyệt A, rồi sau đó duyệt tìm đến B, C, v.v. giống như duyệt theo độ sâu bảng chữ cái dựa trên các chữ cái trong bảng, như vậy ta có thể áp dụng DFS cho bài toán này. Do đường đi cần tìm chỉ có thể bắt đầu từ ‘A’ nên ta sẽ duyệt qua từng phần tử trong bảng, nếu nó là ký tự ‘A’ ta sẽ bắt đầu thực hiện DFS từ đây, trong giải thuật DFS cần chú ý các điểm sau:

        + Để đi qua các điểm liền kề điểm hiện tại (ngang, dọc, chéo) phải thỏa điều kiện: ký tự mới phải liền sau ký tự hiện tại (ví dụ ký tự hiện tại là C thì ký tự kế tiếp phải là D). Ta có thể kiểm tra bằng việc so sánh mã ASCII ký tự sau = mã ASCII ký tự trước + 1.
        + Trong lúc duyệt DFS ta phải lồng ghép vào đếm độ sâu của phép duyệt này được bao nhiêu ký tự. Số lượng lớn nhất trong các lần duyệt chính là kết quả bài toán.

Độ phức tạp: O(n∗m) với n, m lần lượt là kích thước của bảng. Khi sử dụng mảng visited chung cho các lần duyệt dfs thì mỗi ô chỉ đc duyệt tối đa 1 lần.
*/
#include <bits/stdc++.h>
#define MAX 51
using namespace std;

const int dr[] = {0, 0, 1, 1, 1, -1, -1, -1};
const int dc[] = {1, -1, 0, 1, -1, 0, 1, -1};

int W, H, res;
char table[MAX][MAX];
int visited[MAX][MAX];

bool isValid(int r, int c)
{
    return r >= 0 && c >= 0 && r < H && c < W;
}

int DFS(int sr, int sc)
{
    int count = 0;

    for (int i = 0; i < 8; i++)
    {
        int r = sr + dr[i];
        int c = sc + dc[i];

        if (isValid(r, c) && table[r][c] - table[sr][sc] == 1 && visited[r][c] == 0)
        {
            DFS(r, c);
            count = max(count, visited[r][c]);
        }
    }

    visited[sr][sc] = count + 1;
    return visited[sr][sc];
}

int main()
{
    int T = 1;

    while (true)
    {
        int res = 0;
        cin >> H >> W;

        if (H == 0 && W == 0)
        {
            break;
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                cin >> table[i][j];
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (table[i][j] == 'A')
                {
                    res = max(res, DFS(i, j));
                }
            }
        }

        cout << "Case " << T++ << ": " << res << endl;
    }
    return 0;
}