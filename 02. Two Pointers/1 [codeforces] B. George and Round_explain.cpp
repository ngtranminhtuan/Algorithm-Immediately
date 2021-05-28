// Problem: B. George and Round
// Link: https://codeforces.com/problemset/problem/387/B

/*
    Ta có các nhận xét sau:

        Giả sử chúng ta đang chọn bài tập cho đề thứ i, nhưng 
        trong số bài tập đã chuẩn bị có nhiều hơn 2 bài có thể dùng 
        cho đề bài đó. Thì ta sẽ chọn bài tập có độ khó nhỏ nhất 
        cho đề thứ i, vì những bài tập có độ khó cao hơn sẽ dành cho 
        những đề bài có độ khó cao hơn trong kì thi.

        Nếu chúng ta đang chọn bài tập cho đề bài thứ i của kì thi, 
        nhưng đã không chọn được bài tập nào thỏa mãn rồi. 
        Thì đương nhiên là đề bài thứ i+1 với độ khó lớn hơn đề bài 
        thứ i cũng sẽ không chọn được bài tập nào thỏa mãn cho nó. 
        Như vậy trong quá trình chọn bài tập, xét đến đề bài thứ i 
        đã không chọn được bài tập nào thỏa mãn thì sẽ dừng không 
        chọn nữa.

        Giả sử chúng ta đã chọn bài tập thứ j cho đề bài i của kì thi, 
        lúc này nếu xét chọn bài tập cho đề bài thứ i+1, thì tất cả 
        những bài tập trước bài thứ j sẽ không thể chọn được (vì nó 
        đã không được chọn cho đề bài thứ i thì đề bài thứ i+1 với độ 
        khó lớn hơn cũng sẽ không chọn được).
    
    Với các nhận xét trên, chúng ta có thể sử dụng kĩ thuật Two-Pointer 
    để giải quyết bài này như sau:

        Bước 1: Bỏ độ khó được quy định trong kỳ thi vào mảng A, 
        độ khó của các bài đã được George chuẩn bị vào mảng B.

        Bước 2: Sử dụng hai biến i, j chạy song song trên hai mảng, 
        biến count để đếm số lượng đề bài đã chuẩn bị được cho kì thi.

            * Biến i chạy trên mảng A, biến j chạy trên mảng B.
            * Nếu Ai≤Bj nghĩa là bài đã chuẩn bị thứ j có thể sử dụng 
            làm đề bài thứ i trong kỳ thi, ta tăng biến i, j, 
            count lên 1 đơn vị để tìm bài tập cho đề bài i+1.
            * Ngược lại, nếu Ai>Bj ta tăng biến j lên 1 đơn vị để \
            tiếp tục tìm kiếm bài có độ khó ≤Ai
            trong khoảng (j+1) trở về sau.
        Bước 3: In ra đáp án của bài toán: n−count 
        (với count là số đề bài đã chuẩn bị được cho kì thi).

Độ phức tạp: O(max(N,M)) với N, M lần lượt là số bài kỳ thi cần 
và số bài hiện có.

*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    int count = 0;
    for (int i = 0, j = 0; i < n && j < m; j++)
    {
        if (b[j] >= a[i])
        {
            count++;
            i++;
        }
    }

    cout << n - count;
    return 0;
}

// Python
n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
 
count = i = 0
 
for j in range(m):
    if i >= n:
        break
 
    if b[j] >= a[i]:
        count += 1
        i += 1
 
print(n - count)