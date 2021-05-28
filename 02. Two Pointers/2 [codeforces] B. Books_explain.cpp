// Problem: B. Books
// Link: https://codeforces.com/problemset/problem/279/B

/*
    Nhận thấy rằng nếu ta có thể duyệt qua từng đoạn liên tiếp 
    có tổng thời gian còn nằm trong T thời gian cho phép thì 
    việc còn lại trở nên vô cùng đơn giản: chọn ra đoạn có chiều dài 
    lớn nhất, tương ứng với số lượng sách đọc được là nhiều nhất.

    Mỗi đoạn thỏa tính chất như trên đều có thể được biểu diễn 
    dưới dạng một đoạn dài nhất có tổng thời không lớn hơn T 
    tính từ quyển sách thứ i trở về trước.

    Lúc này, ta có thể áp dụng kỹ thuật Two Pointers với hai biến 
    chạy i và j như sau:

        Bước 1: Đưa toàn bộ thời gian cần để đọc các quyển sách hiện 
        có vào mảng.

        Bước 2: Duyệt qua lần lượt từng quyển sách thứ i trong mảng, 
        kiểm tra xem thời gian còn lại có đủ để ta đọc hết quyển sách 
        thứ i này không:
            Nếu không, đồng nghĩa với việc đoạn ta đang chọn đọc 
            bắt đầu từ quyển sách thứ j đã tới giới hạn (đã là đoạn 
            lớn nhất có tổng thời gian không quá T tính từ quyển i - 1 
            trở về trước). Ta di chuyển đến đoạn tiếp theo, tức đoạn 
            bắt đầu tại vị trí (j + 1) và xét tiếp cho đến khi nào ta 
            nhận được một vị trí bắt đầu mới mà tại đó ta vẫn có thể 
            đọc được quyển sách thứ i đang xét.

            Ngược lại, nghĩa là ta còn có thể đọc thêm quyển sách thứ 
            i này vào đoạn hiện tại. Ta tiến hành cập nhật lại các 
            thông số tương ứng về thời gian đọc sách còn lại và số 
            lượng sách đã đọc được trong đoạn.
            
            So sánh số sách hiện tại đọc được với số sách tối đa hiện 
            có và cập nhật nếu cần.

        Bước 3: In ra kết quả.
Độ phức tạp: O(N) với N là số lượng quyển sách.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> a(n);

    int j = 0, max_book = 0, read_book = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];

        while (t < a[i])
        {
            t += a[j];
            j++;
            read_book--;
        }

        t -= a[i];
        read_book++;
        max_book = max(max_book, read_book);
    }

    cout << max_book;
    return 0;
}

// python
n, t = map(int, input().split())
a = list(map(int, input().split()))
 
j = 0
read_books = max_books = 0
 
for i in range(n):
    while t < a[i]:
        t += a[j]
        j += 1
        read_books -= 1
 
    t -= a[i] 
    read_books += 1
    max_books = max(max_books, read_books) 
 
print(max_books)