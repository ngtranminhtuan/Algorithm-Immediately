// Problem: B. Passwords
// Link: http://codeforces.com/problemset/problem/721/b?mobile=true

/*
        Theo cách nhập mật khẩu của Vanya, các mật khẩu có chiều dài
    nhỏ nhất sẽ được nhập trước, rồi đến các mật khẩu có chiều dài 
    nhỏ thứ hai, cứ tiếp tục như vậy. Đến khi chiều dài bằng chiều dài 
    mật khẩu đúng, thì trường hợp tốt sẽ nhập đúng ngay lần đầu tiên, 
    trường hợp xấu sẽ nhập đúng sau khi đã nhập tất cả mật khẩu cùng 
    chiều dài.

        Vậy với N mật khẩu, ta sẽ đếm xem ứng với mỗi chiều dài thì có bao
    nhiêu chuỗi cùng chiều dài đó, lưu lại thông tin này.

        Sau đó, để tìm thời gian cho trường hợp tốt nhất, đi tính tổng số 
    mật khẩu có chiều dài nhỏ hơn chiều dài mật khẩu đúng, đây cũng là 
    thời gian dành để nhập các mật khẩu. Sau k lần nhập sai thì bị chặn 
    5 giây, nên ta lấy tổng vừa tìm được chia cho k ra được số lần bị chặn, 
    rồi nhân cho 5, ta sẽ biết được tổng số thời gian bị chặn. Ta lấy 
    tổng số mật khẩu tìm được trước đó cộng với tổng thời gian bị chặn 
    sẽ biết được tổng thời gian nhập các mật khẩu sai có chiều dài nhỏ hơn 
    chiều dài mật khẩu đúng.
    Thực hiện tương tự để tìm thời gian cho trường hợp xấu nhất, nhưng chỗ 
    tính tổng số mật khẩu, ta cộng thêm số mật khẩu cùng chiều dài với 
    mật khẩu đúng, nhớ trừ đi 1 (trừ mật khẩu đúng).
    Lấy kết quả ở cả hai trường hợp ta đã tính được cộng thêm 1 (thời gian 
    nhập mật khẩu đúng) là ra đáp án cuối cùng.
    Độ phức tạp: O(n + length(s)) với n là số lượng chuỗi nhập và 
    length(s) là độ dài chuỗi s là chuỗi mật khẩu đúng.

*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, k;
    int cnt[101] = {0};
    string s, password;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> s;
        cnt[s.size()]++;
    }

    cin >> password;

    int best_time = 0, worst_time = 0;

    for (int i = 0; i < password.size(); i++)
    {
        best_time += cnt[i];
    }

    worst_time = best_time + cnt[password.size()] - 1;

    best_time += (best_time / k) * 5;
    worst_time += (worst_time / k) * 5;

    cout << best_time + 1 << " " << worst_time + 1;
    return 0;
}