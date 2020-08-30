/*
Sử dụng hàng đợi để xử lí bài toán này.

Bước 1: Khởi tạo

    * Khởi tạo hàng đợi Q, ta sẽ đẩy truy vấn đầu tiên vào hàng đợi.
    * Khởi tạo biến s=t[0], với ý nghĩa s là thời điểm mà ta đang xét đến.
    * Mảng lưu kết quả res[i]=−1 với 0≤i≤n.

Bước 2: Lặp khi hàng đợi truy vấn khác rỗng

    * Gán i=front, giá trị đầu trong hàng đợi, đồng thời lấy giá trị đó ra khỏi hàng đợi. Việc này đồng nghĩa với việc ta sẽ cho máy chủ xử lí truy vấn thứ i.
    * Cập nhật kết quả res[i]=s+d[i], là thời điểm kết thúc quá trình xử lí truy vấn i. Cập nhật lại thời gian hiện tại s=res[i].
    * Tiếp theo ta tìm những truy vấn jj xuất hiện trong khi máy chủ đang xử lí truy vấn i, t[j]<s. Kiểm tra nếu kích thước hàng đợi nhỏ hơn b cho trước thì đẩy j vào hàng đợi.
    * Ngoài ra, ta phải xét đến trường hợp nếu hàng đợi truy vấn rỗng và ta không có truy vấn j nào xuất hiện trước thời điểm s. Trong trường hợp đó, ta sẽ đẩy truy vấn j đang xét đến vào hàng đợi và nếu t[j]>s thì sẽ cập nhật lại s=t[j].
    
Độ phức tạp: O(n) với n là số lượng truy vấn cần xử lý.
*/
#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, b;
    long long t, d, processing = 0;
    queue<long long> q;

    cin >> n >> b;

    for (int i = 0; i < n; i++)
    {
        cin >> t >> d;

        while (!q.empty() && q.front() <= t)
        {
            q.pop();
        }

        if (q.size() <= b)
        {
            processing = max(processing, t) + d;
            cout << processing << " ";
            q.push(processing);
        }
        else
        {
            cout << -1 << " ";
        }
    }
    return 0;
}