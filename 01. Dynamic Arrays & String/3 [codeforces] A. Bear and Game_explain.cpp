/*
Bước 1: Đưa toàn bộ các phút gây cấn trong chương trình vào mảng động.

Bước 2: Gọi T = 0 là thời điểm Limak bắt đầu xem chương trình. 
Xét lần lượt các phút gây cấn thứ i:

    + Nếu T + 15 < thời điểm xuất hiện phút gây cấn thứ i, 
    đồng nghĩa với việc đã qua 15 phút mà không xuất hiện đoạn gây cấn mới, 
    thì (T + 15) chính là thời điểm Limak tắt TV -- cũng là số phút tối đa
    mà cậu xem chương trình.
    + Ngược lại, ta cập nhật giá trị T là thời gian phút gây cấn mới xuất hiện.
Bước 3: So sánh giá trị (T + 15) với 90 (số phút tối đa của chương trình) để đưa ra đáp án.

Độ phức tạp: O(N) với N là số lượng đoạn hấp dẫn.
*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int t = 0;
    for (int i = 0; i < n; i++)
    {
        if (t + 15 < v[i])
        {
            cout << t + 15;
            return 0;
        }
        else
        {
            t = v[i];
        }
    }

    cout << min(t + 15, 90);
    return 0;
}

// Python

n = int(input())
v = list(map(int, input().split(' ')))
 
t = 0
for i in range(n):
    if t + 15 < v[i]:
        print(t + 15)
        exit()
    else:
        t = v[i]
         
print(min(90, t + 15))