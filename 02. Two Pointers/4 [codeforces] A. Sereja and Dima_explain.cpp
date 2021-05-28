// Problem: A. Sereja and Dima
// Link: https://codeforces.com/problemset/problem/381/A

/*
Sử dụng kỹ thuật Two Pointers với hai biến chạy i và j đại diện cho vị trí của hai thẻ bài ngoài cùng mà người chơi hiện tại có thể chọn.

    Bước 1: Đưa thông tin số điểm ghi trên thẻ bài vào một mảng.

    Bước 2: Gọi i là vị trí của thẻ bài ngoài cùng bên trái (tức i = 0), j là vị trí của thẻ bài ngoài cùng bên phải (tức j = n - 1).

    Bước 3: Sử dụng thêm một biến đánh dấu lượt chơi hiện tại là của Sereja hay Dima.
    
    Bước 4: Lần lượt so sánh số điểm ghi trên thẻ bài i và thẻ bài j:
    Nếu i và j chưa gặp nhau, tức còn thẻ bài có thể được lật, ta lấy thẻ bài lớn hơn và cộng dồn vào biến kết quả của người chơi thích hợp.
    Tăng biến i nếu thẻ bài vừa lật nằm ở ngoài cùng bên trái, ngược lại giảm biến j.
    Bước 5: In ra kết quả.

Độ phức tạp: O(n) với n là số lượng thẻ bài.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cards(n);

    for (int i = 0; i < n; i++)
    {
        cin >> cards[i];
    }

    int res[2] = {0};
    int player = 0;
    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (cards[i] > cards[j])
        {
            res[player] += cards[i];
            i++;
        }
        else
        {
            res[player] += cards[j];
            j--;
        }

        player = 1 - player;
    }

    cout << res[0] << " " << res[1];
    return 0;
}

// Python
n = int(input())
cards = list(map(int, input().split()))
res = [0, 0]
player = 0
i, j = 0, n - 1
 
while i <= j:
    if cards[i] > cards[j]:
        res[player] += cards[i]
        i += 1
    else:
        res[player] += cards[j]
        j -= 1
     
    player = 1 - player
 
print(res[0], res[1])