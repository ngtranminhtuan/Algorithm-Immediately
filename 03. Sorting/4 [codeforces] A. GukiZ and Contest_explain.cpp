/*
Nhận xét:

    + Ta thấy rằng vì những người có cùng điểm số sẽ cùng hạng, do đó tương ứng với mỗi giá trị điểm số, ta sẽ chỉ có một giá trị thứ hạng cố định.
    + Để nhanh chóng truy xuất được thứ hạng của một học sinh, hay nói cách khác là trả lời cho câu hỏi với điểm số như vậy thì học sinh đó sẽ được hạng bao nhiêu, ta lập bằng lưu thứ hạng theo điểm số.
    + Nếu sắp điểm số theo thứ tự từ cao đến thấp, thì thứ hạng của một điểm số chính bằng vị trí mà điểm số đó xuất hiện lần đầu tiên (vị trí tính từ 11).

Ta có cách giải của bài này như sau:

    + Bước 1: Đưa thông tin điểm số vào một mảng - mảng này sẽ là mảng gốc mà ta sẽ duyệt lại cuối cùng để đưa ra kết quả.
    + Bước 2: Sao chép thông tin điểm số trong mảng gốc vào một mảng mới và sắp xếp theo thứ tự từ cao đến thấp.
    + Bước 3: Khởi tạo mảng lưu thứ hạng theo điểm số với giá trị mặc định bằng 0.
    + Bước 4: Sử dụng vòng lặp i duyệt qua điểm số đã được sắp xếp trên:
    Nếu thứ hạng của điểm số hiện tại chưa được ghi nhận (tức thứ hạng bằng 0):
        Cập nhật thứ hạng của điểm số đó bằng (1+i).
    Ngược lại, không làm gì.

    + Bước 5: Duyệt lại mảng gốc ban đầu, in ra thứ hạng theo điểm số tương ứng.

Độ phức tạp: O(nlogn) với n là số lượng sinh viên tham gia kiểm tra.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2005;

int ranked[MAX];

int main()
{
    int n, rating;
    cin >> n;
    vector<int> ratings(n), sorted_ratings(n);

    for (int i = 0; i < n; i++)
    {
        cin >> rating;
        ratings[i] = sorted_ratings[i] = rating;
    }

    sort(sorted_ratings.begin(), sorted_ratings.end(), greater<int>());

    for (int i = 0; i < n; i++)
    {
        rating = sorted_ratings[i];

        if (!ranked[rating])
        {
            ranked[rating] = i + 1;
        }
    }

    for (int &rating : ratings)
    {
        cout << ranked[rating] << " ";
    }

    return 0;
}