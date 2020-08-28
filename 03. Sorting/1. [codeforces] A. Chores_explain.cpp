/*
Nhận xét:

    Ta có thể phát biểu lại bài toán trên như sau: Tìm các giá trị x sao cho x có thể tách mảng h ra làm hai phần A và B, trong đó các giá trị trong A luôn lớn hơn x và giá trị trong B luôn nhỏ hơn hoặc bằng x.
    Gọi min(A) là giá trị nhỏ nhất trong phần A và max(B) là giá trị lớn nhất trong phần B. Như vậy, số cách chọn x chính bằng max(B) - min(A).

Ta hình thành cách giải của bài này như sau:

    Bước 1: Đưa thông tin độ phức tạp của từng công việc vào một mảng, tạm gọi là h.
    Bước 2: Sắp xếp mảng h theo thứ tự tăng dần về độ khó. Với mảng được đánh số từ 0, lúc này: 
        + max(B) tương ứng với h_{b - 1}.
        + min(A)min(A) tương ứng với h_b.
        
Bước 3: In ra số cách chọn x bằng công thức h_b - h_{b - 1}.

Độ phức tạp: O(nlogn) với n là số lượng công việc.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> h(n);

    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end());
    cout << h[b] - h[b - 1];
    return 0;
}