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

#define MAX 1000
int cards[MAX];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }

    int i = 0;
    int j = n - 1;
    int points[] = {0, 0};
    int turn = 0;
    int take = 0;
    while (i <= j) {
        if (cards[i] >= cards[j]) {
            take = cards[i];
            i++;
        } else {
            take = cards[j];
            j--;
        }

        points[turn] += take;
        turn = 1 - turn;
    }

    cout << points[0] << " " << points[1] << endl;

    return 0;
}
