// Problem: B. Approximating a Constant Range
// Link: https://codeforces.com/problemset/problem/602/B

/*
Nhận xét:

    Cần chú ý rằng độ chênh lệnh giữa hai điểm dữ liệu liên tục không vượt quá 1. Do đó một đoạn hợp lệ là đoạn liên tục có số lượng phần tử phân biệt không vượt quá 2.
    Để lần lượt duyệt qua từng đoạn liên tục, ta sử dụng kỹ thuật Two Pointers với hai biến chạy i và j. Ban đầu ta sẽ mở rộng đoạn bằng cách sử dụng biến i cho tới khi nào đoạn của ta có số lượng phần tử phân biệt lớn hơn 2, lúc này ta tiến hành rút ngắn đoạn bằng cách đưa j chạy ngược lên. Thực hiện tương tự cho đến hết mảng.
    Sử dụng mảng đếm phân phối để nhanh chóng tìm được số lượng phần tử phân biệt của đoạn đang xét.
Như vậy, ta có cách giải quyết bài toán này như sau:

    Bước 1: Đưa thông tin các điểm dữ liệu vào mảng.
    Bước 2: Khởi tạo biến lưu số lượng phần tử phân biệt của đoạn hiện có và mảng đếm phân phối.
    Bước 3: Khởi tạo biến chạy j ở đầu mảng.
    Bước 4: Cho biến i chạy từ đầu mảng:
        Nếu phần tử hiện tại ở vị trí i lần đầu tiên xuất hiện (giá trị trong mảng phân phối bằng 0) thì tăng biến đếm số lượng phân biệt lên 1.
        Nếu số lượng phần tử phân biệt lúc này lớn hơn 2, thực hiện rút ngắn đoạn bằng biến j. Đồng thời cập nhật số lượng phần tử phân biệt.
        So sánh đoạn hiện tại [j, i] có kích thước i - j + 1 với độ dài lớn nhất hiện có và tiến hành cập nhật.
    Bước 5: In ra kết quả.

Độ phức tạp: O(n) với n là số điểm dữ liệu.

*/

#include <iostream>
#include <vector>
using namespace std;

#define MAX 100000
int arr[MAX];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int i = 0, j = 0;
    int best = 0;
    int maxIndex = 0, minIndex = 0;
    while (i < n) {
        // maxIndex, minIndex as right side as possible
        if (arr[i] >= arr[maxIndex])
            maxIndex = i;
        if (arr[i] <= arr[minIndex])
            minIndex = i;

        if (arr[maxIndex] - arr[minIndex] > 1) {
            // Find alternative minIndex
            if (arr[maxIndex] == arr[i]) {
                j = ++minIndex;
            }
            // Find alternative maxIndex
            else if (arr[minIndex] == arr[i]) {
                j = ++maxIndex;
            }
        } else {
            best = max(best, i - j + 1);
            i++;
        }
    }

    cout << best << endl;

    return 0;
}
