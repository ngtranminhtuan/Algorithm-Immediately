// Problem: B. George and Round
// Link: https://codeforces.com/problemset/problem/892/B

/*
Sử dụng kỹ thuật Two Pointers với hai biến chạy i và j tương ứng 
với vị trí mà Alice và Bob đang ăn. Đồng thời dùng thêm hai biến 
lưu thời điểm ăn của cả hai.

    Bước 1: Đưa thông tin về thời gian ăn các thanh chocolate vào một 
    mảng.
    Bước 2: Khởi tạo thời điểm ăn của cả hai là 0.
    Bước 3: Sử dụng hai biến chạy i đầu mảng (Alice) và j cuối 
    mảng (Bob).
        
        * So sánh thời điểm ăn của Alice và Bob:
            Nếu thời điểm Alice bắt đầu ăn thanh chocolate tại 
            vị trí i nhỏ hơn hoặc bằng thời điểm Bob ăn thanh 
            chocolate thứ j thì Alice sẽ ăn thanh chocolate tại 
            vị trí i.
            Ngược lại Bob sẽ ăn thanh chocolate tại vị trí j.
        * Cập nhật thời điểm ăn của từng người và hai biến chạy ii, jj.
    
    Bước 4: Số thanh chocolate mà Alice đã ăn được chính bằng giá 
    trị của i và của Bob là (n−i).
    
Độ phức tạp O(n) với nn là số lượng thanh chocolate.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> chocolate(n);

    for (int i = 0; i < n; i++)
    {
        cin >> chocolate[i];
    }

    int t_alice = 0, t_bob = 0;
    int i = 0, j = n - 1;

    while (i <= j)
    {
        if (t_alice + chocolate[i] <= t_bob + chocolate[j])
        {
            t_alice += chocolate[i];
            i++;
        }
        else
        {
            t_bob += chocolate[j];
            j--;
        }
    }

    cout << i << " " << n - i;
    return 0;
}