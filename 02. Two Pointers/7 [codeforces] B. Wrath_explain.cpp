// Problem: B. George and Round
// Link: https://codeforces.com/problemset/problem/892/B

/*
Nhận xét:

    Số người sống sót bằng hiệu giữa số phạm nhân ban đầu với số người 
    bị giết.
    Số người bị giết bởi người thứ i chính bằng hiệu giữa vị trí của 
    người i và vị trí cuối cùng móng vuốt chạm tới.
    Để tránh một người bị giết bị đếm nhiều lần, trước khi quyết định 
    cộng dồn số người bị giết bởi người thứ i vào tổng số người 
    bị giết, ta cần lưu lại mốc vị trí cuối cùng của người bị giết 
    trước đó. Nếu vị trí mà móng vuốt chạm tới không vượt qua mốc cuối 
    cùng này tức là số người này đã được đếm rồi. Như vậy, ta 
    hình thành các bước giải bài này như sau:
        Bước 1: Đưa toàn bộ độ dài móng vuốt của n phạm nhân vào mảng.
        Bước 2: Khởi tạo biến j với ý nghĩa là vị trí cuối cùng của 
        người bị giết trước đó.
        Bước 3: Duyệt ngược từ vị trí thứ i về đầu mảng để đếm số lượng 
        người bị giết bởi người thứ i:
    Cập nhật j theo i khi i<j, tức những người bị giết sắp tới 
    chắc chắn sẽ nằm ngoài khoảng bị đếm trùng.
    Xác định vị trí xa nhất mà móng vuốt có thể chạm tới.
    Nếu vị trí này bé hơn j, tức đã có thêm những người bị giết mới, 
    ta cộng dồn số lượng mới này vào biến lưu tổng người bị giết.
    Bước 4: In ra số người còn sống bằng công thức nêu trên.

Độ phức tạp O(n) với n số lượng phạm nhân.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int count = 0, j = n - 1, last_kill_pos = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        j = min(j, i);
        last_kill_pos = max(0, i - a[i]);

        if (j > last_kill_pos)
        {
            count += (j - last_kill_pos);
            j = last_kill_pos;
        }
    }

    cout << n - count;
    return 0;
}

// Python
n = int(input())
a = list(map(int, input().split()))

count = 0
j = n - 1

for i in range(n - 1, -1, -1):
    j = min(j, i)
    last_kill_pos = max(0, i - a[i])

    if j > last_kill_pos:
        count += (j - last_kill_pos)
        j = last_kill_pos
    
print(n - count)