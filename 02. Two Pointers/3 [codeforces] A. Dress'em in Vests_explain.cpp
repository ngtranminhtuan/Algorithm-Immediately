// Problem: A. Dress'em in Vests!
// Link: https://codeforces.com/problemset/problem/161/A

/*
Nhận xét:

        Để tối ưu số người lính có thể có áo, với mỗi chiếc áo từ bé 
        đến lớn ta sẽ lần lượt dành cho những người lính có kích thước 
        nhỏ nhất mang vừa chiếc áo đó. Bằng cách này, những áo có 
        kích cỡ lớn hơn sẽ có cơ hội vừa với những người lính khác 
        có kích thước lớn hơn.

        Hơn nữa, nếu người lính i được chọn mang bộ vest j, thì người 
        lính (i + 1) trở về sau chắc chắn chỉ có thể mang áo từ (j + 1) 
        trở về sau. Bởi nếu những chiếc áo từ j trở về trước mà có 
        thể dùng được thì người lính i đã dùng rồi. Như vậy nghĩa là 
        các bộ vest từ 1 đến j hoặc đã được dùng, hoặc không thể dùng, 
        nên ta không cần kiểm tra lại.

Từ đó, ta hình thành các bước giải quyết bài toán như sau:

    Bước 1: Đưa thông tin về kích thước của mỗi người lính 
    và kích cỡ của các áo hiện có vào 2 mảng.

    Bước 2: Sử dụng hai biến chạy i và j, trong đó biến i sẽ 
    chạy trên mảng chứa kích thước các người lính, còn biến j sẽ 
    chạy trên mảng còn lại. Đặt i = j = 0 (tức xét người lính đầu tiên và chiếc áo đầu tiên).

    Bước 3: Sử dụng vòng lặp, kết thúc khi không còn lính hoặc 
    không còn chiếc áo nào có thể phát:

        Nếu chiếc áo nằm trong khoảng kích thước có thể chấp nhận 
        được của người lính, ta nhận được một cặp (người lính - áo) 
        hợp lệ và đưa vào mảng kết quả, đồng thời ta chuyển sang 
        chiếc áo và người lính tiếp theo, tức tăng biến i và j lên 1.

        Nếu kính cỡ tối đa mà người lính có thể mang nhỏ hơn kích cỡ 
        của chiếc áo, ta cần tìm một người lính có kích thước lớn hơn 
        có khả năng mang vừa chiếc áo đó, tức tăng i lên 1.

        Nếu kính cỡ tối thiểu mà người lính có thể mang vượt quá 
        kích cỡ của chiếc áo, ta cần tìm một chiếc áo có kích thước 
        lớn hơn có khả năng mang vừa chiếc áo đó, tức tăng j lên 1

    Bước 4: In đáp án dựa trên mảng kết quả

Độ phức tạp: O(max(n, m)) với n là số lượng người lính và m là 
số lượng áo.

*/

#include <iostream>
#include <vector>
using namespace std;

struct Vest
{
    int u, v;
};

int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    vector<Vest> v;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] - x <= b[j] & b[j] <= a[i] + y)
        {
            v.push_back({i + 1, j + 1});
            i++;
            j++;
        }
        else if (a[i] + y < b[j])
        {
            i++;
        }
        else if (a[i] - x > b[j])
        {
            j++;
        }
    }

    cout << v.size() << endl;
    for (Vest &vest : v)
    {
        cout << vest.u << " " << vest.v << endl;
    }

    return 0;
}

// Python
n, m, x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
v = []
i = j = 0

while i < n and j < m:
   if a[i] - x <= b[j] <= a[i] + y:
      v.append((i + 1, j + 1))
      i += 1
      j += 1
   elif a[i] + y < b[j]:
      i += 1
   elif a[i] - x > b[j]:
      j += 1

print(len(v))
for vest in v:
    print(vest[0], vest[1])