// Problem: A. Towers
// Link: https://codeforces.com/problemset/problem/37/A

/*
Nhận xét:

    + Số tòa tháp chính bằng số chiều dài phân biệt và chiều cao của tòa tháp cao nhất bằng số lượng lớn nhất các thanh gỗ cùng chiều dài.
    + Để đếm số chiều dài phân biệt, ta có thể sắp xếp lại mảng theo thứ tự tăng dần hoặc giảm dần. So sánh lần lượt từng cặp phần tử kề nhau và tăng biến đếm số phần tử phân biệt nếu hai phần tử đó khác nhau.
    + Đồng thời, với mỗi lần ta duyệt đến một phần tử phân biệt mới, ta bắt đầu đếm số lần xuất hiện của phần tử ấy và liên tục cập nhật với số lần xuất hiện lớn nhất.
Tóm lại, ta có cách làm như sau:

    + Bước 1: Đưa thông tin chiều dài các thanh gỗ vào mảng.
    + Bước 2: Sắp xếp mảng tăng dần.
    + Bước 3: Lấy thanh gỗ đầu tiên làm gốc, ta sử dụng một biến đếm số lượng thanh gỗ phân biệt, khởi tạo bằng 11 (tức xem phần tử ở đầu mảng là phần tử phân biệt đầu tiên). Biến đếm số lượng thanh gỗ có cùng chiều dài với thanh gỗ đang xét, khởi tạo bằng 11.
    + Bước 4: Lần lượt duyệt qua các thanh gỗ có chiều dài từ bé đến lớn, không tính thanh đầu tiên:
    Nếu thanh gỗ này có cùng chiều dài với thanh trước đó thì ta tăng biến đếm số lượng thanh gỗ có cùng chiều dài lên 11. Đồng thời, so sánh số lượng thanh gỗ có cùng chiều dài hiện tại với số lượng lớn nhất và liên tục cập nhật lại.
    Ngược lại, tăng biến đếm số lượng phần tử phân biệt lên 11 và cập nhật lại số lượng thanh gỗ có cùng chiều dài với thanh gỗ đang xét bằng 11.
    + Bước 5: In kết quả. 

Độ phức tạp: O(NlogN) với NN là số lượng thanh gỗ.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> bars(n);

    for (int i = 0; i < n; i++)
    {
        cin >> bars[i];
    }

    sort(bars.begin(), bars.end());
    int n_towers = 1, max_height = 1, cur_height = 1;

    for (int i = 1; i < n; i++)
    {
        if (bars[i] == bars[i - 1])
        {
            cur_height++;
            max_height = max(max_height, cur_height);
        }
        else
        {
            n_towers++;
            cur_height = 1;
        }
    }

    cout << max_height << " " << n_towers;
    return 0;
}