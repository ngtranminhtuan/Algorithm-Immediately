/*
Nhận xét:

    Vì càng về sau tốc độ đọc càng được cải thiện, do đó để tối ưu thời gian học ta sẽ ưu tiên đọc các môn có ít chương trước và để dành các môn nhiều chương hơn học sau.

Như vậy, cách giải của bài này như sau:

    + Bước 1: Đưa thông tin số chương mỗi môn cần đọc vào một mảng.
    + Bước 2: Sắp xếp mảng tăng dần.
    + Bước 3: Lần lượt duyệt qua các môn học với số chương từ nhỏ đến lớn:
    Ở mỗi môn, ta cần một khoảng thời gian bằng (X x số chương của môn đó) để hoàn tất. Cộng dồn thời gian này vào một biến kết quả lưu tổng thời gian tối thiểu.
    Sau khi học xong một môn thì tốc được cải thiện, do đó ta giảm x đi 1 giờ. Tuy nhiên, ta cần kiểm tra xem x đã đạt mức tối thiểu là 1 giờ/(trên một)chương chưa. Nếu rồi thì ta không cần phải giảm thêm nữa.
    + Bước 4: In kết quả.

Độ phức tạp: O(nlogn) với n là số môn học.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> c(n);

    for (int i = 0; i < n; i++)
    {
        cin >> c[i];
    }

    sort(c.begin(), c.end());

    long long min_time = 0;

    for (int chapters : c)
    {
        min_time += 1LL * chapters * x;
        if (x > 1)
        {
            x--;
        }
    }

    cout << min_time;
    return 0;
}