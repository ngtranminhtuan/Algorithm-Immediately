// Problem: Monk and Multiplication
// Link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/monk-and-multiplication/

/*
Monk đang tìm hiểu hàng đợi ưu tiên. Cho cậu một mảng số nguyên. Với mỗi phần tử khi thêm vào hàng đợi ưu tiên, Monk muốn tìm tích của ba phần tử lớn nhất hiện có trong hàng đợi. Nếu không có đủ ba số lớn nhất, nhì và ba thì in ra -1−1.

Giải thích ví dụ

Thêm 1 vào hàng đợi ưu tiên → in ra −1.
Thêm 2 vào hàng đợi ưu tiên → in ra −1.
Thêm 3 vào hàng đợi ưu tiên → in ra 3⋅2⋅1=6.
Thêm 4 vào hàng đợi ưu tiên → in ra 4⋅3⋅2=24.
Thêm 5 vào hàng đợi ưu tiên → in ra 5⋅4⋅3=60.

** Hướng dẫn giải
Áp dụng hàng đợi ưu tiên là giải quyết bài này.

Bước 1: Lưu các phần tử đề cho vào một mảng.
Bước 2: Lần lượt duyệt qua các phần tử và bỏ vào hàng đợi ưu tiên.
Nếu như số lượng phần tử trong hàng đợi ưu tiên nhỏ hơn 3 thì ta xuất ra −1.
Mỗi lần bỏ phần tử mới vào thì lấy top 3 để nhân với nhau và in ra kết quả.
Độ phức tạp: O(NlogN) với NN là số lượng phần tử trong mảng.

*/

#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    priority_queue<long long> pq;
    long long x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);

        if (pq.size() < 3)
            cout << "-1" << endl;
        else {
            long long largest = pq.top();
            pq.pop();
            long long secondLargest = pq.top();
            pq.pop();
            long long thirdLargest = pq.top();
            pq.pop();
            cout << largest * secondLargest * thirdLargest << endl;

            pq.push(largest);
            pq.push(secondLargest);
            pq.push(thirdLargest);
        }
    }

    return 0;
}

/*Cách 2*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int x, n;
    priority_queue<int> pq;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);

        if (i < 2) {
            cout << -1 << endl;
        }
        else {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int third = pq.top();
            pq.pop();

            cout << 1LL * first * second * third << endl;

            pq.push(first);
            pq.push(second);
            pq.push(third);
        }
    }
    return 0;
}

// Standard Code
#include <iostream>
#include <queue>
using namespace std;

int main() {
    int x, n;
    priority_queue<int> pq;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x;
        pq.push(x);

        if (i < 2) {
            cout << -1 << endl;
        }
        else {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int third = pq.top();
            pq.pop();

            cout << 1LL * first * second * third << endl;

            pq.push(first);
            pq.push(second);
            pq.push(third);
        }
    }
    return 0;
}

//------------
import queue

n = int(input())
a = list(map(int, input().split()))
pq = queue.PriorityQueue()

for i in range(n):
	pq.put(-a[i])

	if i < 2:
		print(-1)
	else:
		first = -pq.get()
		second = -pq.get()
		third = -pq.get()

		print(first * second * third)

		pq.put(-first)
		pq.put(-second)
		pq.put(-third)