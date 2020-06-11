/*
- Chạy ngược chuỗi S từ ký tự cuối về ký tự đầu, xét hai trường hợp sau:
    + Nếu gặp ký tự ‘z’ thì biến ký tự này thành ký tự ‘a’.
    + Nếu gặp ký tự khác ‘z’ thì tăng ký tự này lên một bậc, 
    nghĩa là nếu gặp ký tự ‘b’ thì biến thành ‘c’, 
    ký tự là ‘g’ thì biến thành ‘h’. Ngay sau tăng ký tự lên một bậc
    thì dừng vòng lặp.

- Sau khi biến đổi xong hãy so sánh giữa chuỗi kết quả và T, 
nếu chuỗi kết quả khác chuỗi T (nghĩa là chuỗi nhỏ hơn T) thì in ra chuỗi
kết quả, ngược lại in “No such string”.

Độ phức tạp: O(N) với N là độ dài của 2 chuỗi.
*/

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string s, t;
    cin >> s >> t;
 
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == 'z') {
            s[i] = 'a';
        }
        else {
            s[i]++;
            break;
        }
    }
 
    cout << (s == t ? "No such string" : s);
    return 0;
}