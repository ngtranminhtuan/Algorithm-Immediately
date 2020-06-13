/* Problem: A. Arrays
        time limit per test: 2 seconds
        memory limit per test: 256 megabytes
        inputstandard input
        outputstandard output
https://codeforces.com/problemset/problem/572/A

Nhận xét: Để tăng khả năng hai đoạn con được chọn ở hai mảng thỏa yêu cầu
đề bài, ta ưu tiên chọn K phần tử nhỏ nhất trong A và M phần tử lớn nhất
trong B. Lúc này muốn kiểm tra điều kiện tất cả phần tử trong mảng con A
đều nhỏ hơn tất cả phần tử trong mảng con B, ta chỉ việc so sánh phần tử
lớn nhất trong mảng con A và phần tử nhỏ nhất trong mảng con B.
Nếu kết quả là nhỏ hơn, đồng nghĩa với mọi phần tử trong K phần tử của mảng
A đều nhỏ hơn M phần tử trong mảng B, ta in ra “YES”. Ngược lại, in “NO”.

Hơn nữa, cả hai mảng đều đã được sắp xếp không giảm, do đó với mảng đánh số
bắt đầu từ 00, ta có:

    Phần tử lớn nhất trong K phần tử nhỏ nhất của A sẽ nằm ở vị trí K – 1.
    Phần tử nhỏ nhất trong M phần tử lớn nhất của B nằm ở vị trí N_B – M.

Như vậy, đáp án của ta chỉ cần dựa vào kết quả của phép so sánh A[K – 1] < B[N_B– M].

Độ phức tạp: O(1) */
#include <iostream>
#include <vector>
using namespace std; 
 
int main() {
    int na, nb, k, m;
    cin >> na >> nb;
    cin >> k >> m;
    vector<int> a(na), b(nb);
     
    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
 
    cout << (a[k - 1] < b[nb - m] ? "YES" : "NO");
 
    return 0;
}