// Problem: B. George and Round
// Link: https://codeforces.com/problemset/problem/224/B

/*
Ý tưởng giải dựa trên kỹ thuật Two Pointers với hai biến chạy i và j:

    Bước 1: Sử dụng biến chạy i để chạy tìm đoạn đầu tiên chứa đủ K số
    phân biệt.
    Bước 2: Sử dụng biến chạy j chạy từ dưới lên nhằm rút ngắn đoạn 
    tìm được, đảm bảo trong [j,i] không còn bất cứ đoạn con nào cũng 
    thỏa yêu cầu.
    Bước 3: In ra kết quả bài toán nằm trong hai biến j và i.

Trong đó, để kiểm soát số phần tử phân biệt đã tìm được,
ta dùng thêm một mảng đếm phân phối fre[] với fre[X] là số lần X 
xuất hiện trong khoảng [j,i]. Với mỗi lần fre[X] thay đổi từ 0 lên 1, 
tức là ta vừa nhận được thêm một số mới không trùng với những số 
trước đó, ta tăng biến đếm số lượng phần tử phân biệt lên 1.

Độ phức tạp: O(N) với N số lượng phần tử trong dãy.
*/

#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1e5 + 5;

int fre[MAX];

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int unique = 0;
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (fre[a[i]] == 0)
        {
            unique++;
        }

        fre[a[i]]++;

        while (unique == k)
        {
            fre[a[j]]--;

            if (fre[a[j]] == 0)
            {
                cout << j + 1 << " " << i + 1;
                return 0;
            }

            j++;
        }
    }

    cout << "-1 -1";
    return 0;
}

// Python
n, k = map(int, input().split())
a = list(map(int, input().split()))
fre = [0] * (10 ** 5 + 5)
unique = 0
j = 0
 
for i in range(n):
    if fre[a[i]] == 0:
        unique += 1
     
    fre[a[i]] += 1
 
    while unique == k:
        fre[a[j]] -= 1
 
        if fre[a[j]] == 0:
            print(j + 1, i + 1)
            exit()
         
        j += 1
 
print('-1 -1')