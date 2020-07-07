/*
- Nhận xét: Đoạn thẳng có thể bao phủ tất cả các đoạn thẳng còn lại trong N đoạn thẳng đã cho phải có:

	+ Đầu mút trái là giá trị nhỏ nhất trong tất cả các giá trị đầu mút trái của N đoạn thẳng.
	+ Đầu mút phải là giá trị lớn nhất trong tất cả các giá trị đầu mút phải của N đoạn thẳng.

- Ý tưởng: Đi tìm cặp [L_i, R_i] biễu diễn đoạn thẳng lớn nhất này. Sau đó kiểm tra xem có
đoạn thẳng nào như vậy trong N đoạn thẳng được cho hay không. Nếu có đoạn nào trùng khớp thì đó
chính là đoạn thẳng cần tìm, ta in ra số thứ tự của đoạn thẳng đó. Ngược lại, in ra −1.

Ta có các bước giải bài này như sau:

	+ Bước 1: Đưa cặp L_i, R_i biểu diễn đoạn thẳng thứ i vào hai mảng động chứa đầu mút trái và đầu mút phải.
	+ Bước 2: Tìm giá trị nhỏ nhất trong mảng chứa đầu mút trái và giá trị lớn nhất trong mảng chứa đầu mút phải.
	+ Bước 3: Duyệt lại từng đoạn thẳng thứ i trong N đoạn thẳng:
		. Nếu đoạn thẳng đó có L_i bằng giá trị đầu mút trái nhỏ nhất và R_i bằng giá trị đầu mút phải lớn nhất vừa tìm được:
			. In ra số thứ tự của đoạn thẳng đó và thoát chương trình.
	+ Bước 4: Không có đoạn thẳng nào trùng khớp, do đó in ra −1.
- Độ phức tạp: O(N) với N là số lượng đoạn thẳng.
*/

#include <iostream>
#include <vector>
using namespace std;
const int INF = 1e9 + 5;
 
int main() {
    int n;
    cin >> n;
    vector<int> L(n), R(n);
     
    int left = INF, right = 0;                  // Sentinal values
 
    for (int i = 0; i < n; i++) {
        cin >> L[i] >> R[i];
        left = min(left, L[i]);
        right = max(right, R[i]);
    }
 
    for (int i = 0; i < n; i++) {
        if (left == L[i] && right == R[i]) {
            cout << i + 1;
            return 0;
        }
    }
 
    cout << -1;
    return 0;
}