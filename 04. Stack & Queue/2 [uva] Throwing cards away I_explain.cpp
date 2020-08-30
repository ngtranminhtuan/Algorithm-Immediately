/*
Nhận xét:

    Có thể mô phỏng thao tác rút lá bài ra tương tự như thao tác lấy dữ liệu từ queue và đưa lá bài vào giống như thêm dữ liệu vào queue (lá bài được thêm vào sẽ nằm ở cuối).

Ta có các bước thực hiện để giải bài toán như sau:

    Bước 1: Đưa hết các lá bài theo thứ tự từ 11 đến N vào CTDL queue.
    Bước 2: Khi số lượng lá bài trong queue còn ít nhất hai lá:
    Lấy lá bài trên đầu queue ra.
    Lấy lá bài mới trên đầu queue ra và đưa lại vào cuối queue.
    Bước 3: In ra kết quả theo định dạng trong các ví dụ.
    Bước 4: Reset các biến cần thiết, chuẩn bị cho bộ test tiếp theo.
    Lưu ý: Cần cẩn thận trong cách trình bày kết quả. Với trường hợp không rút được lá bài nào ra khỏi chồng bài (N=1), ta chỉ in ra "Discarded cards:" nhưng không có khoảng trắng ở cuối.

Độ phức tạp: O(T∗N) với T là số lượng bộ test và N là số lượng lá bài.
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n;
    queue<int> deck;
    vector<int> discarded_cards;

    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }

        for (int i = 1; i <= n; i++)
        {
            deck.push(i);
        }

        while (deck.size() >= 2)
        {
            discarded_cards.push_back(deck.front());
            deck.pop();
            deck.push(deck.front());
            deck.pop();
        }

        cout << "Discarded cards:";
        for (int i = 0; i < n - 1; i++)
        {
            if (i != 0)
            {
                cout << ",";
            }
            cout << " " << discarded_cards[i];
        }
        cout << endl;
        cout << "Remaining card: " << deck.front() << endl;

        deck.pop();
        discarded_cards.clear();
    }
    return 0;
}