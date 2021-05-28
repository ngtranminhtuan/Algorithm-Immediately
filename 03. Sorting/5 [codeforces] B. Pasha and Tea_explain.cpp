/*
Nhận xét:

    + Vì lượng trà châm cho khách nam luôn nhiều hơn nữ, do đó để tối ưu lượng trà mà mỗi vị khách nhận được, ta sẽ dành n ly có dung tích nhỏ nhất cho khách nữ và n ly còn lại có dung tích lớn hơn cho khách nam.
    + Mặt khác, mỗi khách nữ đều nhận được một lượng trà như nhau, do đó lượng trà tối đa mà ta có thể châm cho khách nữ sẽ bằng dung tích của ly trà nhỏ nhất trong số n ly nhỏ nhất - ta tạm gọi là x. Tương tự, lượng trà tối đa có thể châm cho khách nam sẽ bằng dung tích của ly trà nhỏ nhất trong số n ly lớn hơn - tạm gọi là y.
    + Gọi m là lượng trà mà ta sẽ rót cho mỗi khách nữ. Lượng trà được châm cho nam phải nhiều gấp đôi nữ nên có thể được biểu diễn là 2∗m. Ta có điều kiện sau: m≤x và 2∗m≤y. Từ đây suy ra được m lớn nhất khi m=min(x,y/2).
    + Với m vừa tìm được, ta suy ra tổng lượng trà cần chuẩn bị chính bằng m∗n + 2∗m∗n = 3∗m∗n. Tuy nhiên, tổng lượng trà vừa tính có thể vượt quá dung tích tối đa của ấm trà, do đó ta cần phải so sánh để đưa ra kết quả phù hợp.

Như vậy, ta hình thành các bước giải của bài này như sau:

    + Bước 1: Đưa thông tin của 2∗n ly trà vào một mảng.
    + Bước 2: Sắp xếp mảng các ly trà theo dung tích tăng dần. Như vậy, x sẽ nằm ở vị trí đầu tiên và y sẽ nằm ở vị trí thứ nn trong dãy.
    + Bước 3: Tính lượng trà tối đa mà ta có thể rót cho mỗi khách nữ là m = min(x,y/2). Dựa vào m, tính tổng lượng trà cần chuẩn bị bằng công thức 3∗m∗n.
    Bước 4: So sánh tổng lượng trà đã tính được ở trên với dung tích tối đa của ấm và in kết quả.

Độ phức tạp: O(nlogn) với n là số lượng khách nam/nữ.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main()
{
    int n, w;
    cin >> n >> w;
    vector<int> cups(n * 2);

    for (int i = 0; i < n * 2; i++)
    {
        cin >> cups[i];
    }

    sort(cups.begin(), cups.end());

    double m = min(1.0 * cups[0], 1.0 * cups[n] / 2);
    double total = 3 * m * n;
    cout << setprecision(9) << min(total, 1.0 * w);
    return 0;
}

//--------
n, w = map(int, input().split())
cups = list(map(int, input().split()))
cups.sort()

m = min(cups[0], cups[n] / 2)
total = 3 * m * n
print(min(total, w))