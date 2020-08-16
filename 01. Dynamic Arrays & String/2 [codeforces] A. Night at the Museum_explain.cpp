/*
Đặt kim đồng hồ của bạn ngay tại vị trí bắt đầu là ký tự ‘a’.

Bạn sẽ cho vòng lặp lấy từng ký tự ra, ký tự đầu tiên sẽ trừ với ký tự ‘a’. 
Nếu từ vị trí ‘a’ đến ký tự đó nhỏ hơn 13 thì bạn sẽ đi theo hướng này. 
Nếu lớn hơn 13 thì bạn sẽ đi ngược hướng lại để đi được gần hơn.

Sau khi chọn bước đi ở trên xong thì bạn sẽ gán ký tự mới này vào thay cho
vị trí bắt đầu (vì theo đề bài mỗi bước đi sẽ cập nhật lại vị trí ban đầu của 
kim đồng hồ).

Chạy lần lượt qua hết các ký tự lấy số bước đi cộng lại là kết quả của bài toán.

Độ phức tạp: O(N) với N là độ dài của chuỗi đầu vào.
*/

#include <iostream>
#include <string>
using namespace std;
 
int main() {
    string wheel;
    cin >> wheel;
 
    char pointer = 'a';
    int dist, count = 0;
 
    for (char &c : wheel) {
        dist = abs(pointer - c);
 
        if (dist < 13) {
            count = count + dist;
        }
        else {
            count = count + (26 - dist);
        }
 
        pointer = c;
    }
 
    cout << count;
    return 0;
}