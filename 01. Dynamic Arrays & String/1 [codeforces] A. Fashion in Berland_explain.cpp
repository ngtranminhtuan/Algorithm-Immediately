/*
    - Bước 1: Đưa toàn bộ giá trị đại diện cho trạng thái mỗi nút áo vào trong mảng động.
    - Bước 2: Xét hai trường hợp:
        + Trường hợp 1: Khi áo có 1 nút. Nếu nút đó là “1” thì in ra “YES”, ngược lại in ra “NO” và thoát khỏi chương trình.
        + Trường hợp 2: Với số nút lớn hơn 1, sử dụng một biến để đếm số lượng nút không cài (số 0). Nếu số lượng nút không cài đúng bằng 1 thì in ra “YES”, ngược lại in ra “NO”.
    - Độ phức tạp thời gian: O(N) với N là số lượng nút áo.
*/
#include <iostream>  
#include <vector>  
using namespace std;
 
bool checkJacket(vector<int>& v, int n) {
    if (n == 1) {
        if (v[0] == 1)
            return true;
        else
            return false;
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            count++;
        }
    }
    if (count == 1)
        return true;
    else
        return false;
}
 
int main() {
    int n, value;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> value;
        v.push_back(value);
    }
    bool result = checkJacket(v, n);
    if (result == true)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}