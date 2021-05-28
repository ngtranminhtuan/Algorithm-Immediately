// Problem: QHEAP1
// Link: https://www.hackerrank.com/challenges/qheap1/problem

/*
***************************************Giải thích ví dụ**************************************
After the first 2 queries, the heap contains 4,9. Printing the minimum gives 4 as the output. Then, the 4th query deletes 4 from the heap, and the 5th query gives 9 as the output.

Tóm tắt đề

Cho bạn các truy vấn như sau:

"1 v": Thêm một phần tử vv vào heap.
"2 v": Xóa một phần tử vv khỏi heap.
"3": In phần tử nhỏ nhất trong heap.
Chú ý: các phần tử cần xóa luôn có trong heap và các phần tử trong heap là phân biệt nhau.

Input:

Dòng đầu tiên chứa số Q (1 ≤ Q ≤ 10^5) – số lượng truy vấn cần thực hiện.
Q dòng tiếp theo chứa một trong ba loại truy vấn đề cập ở trên (−10^9 ≤ v ≤ 10^9).

Output:

Với truy vấn loại 3 in phần tử nhỏ nhất trong heap trên một dòng.

Ví dụ:

Input	    Output
5
1 4      
1 9         4
3           9
2 4
3

	
Giải thích ví dụ:

Thêm 4 vào hàng đợi ưu tiên → 4.
Thêm 9 vào hàng đợi ưu tiên → 4,9.
In phần tử nhỏ nhất ra → in ra 4.
Xóa phần tử 4 khỏi heap → 9.
In phần tử nhỏ nhất ra → in ra 9.


************************************** Tutorial *********************************************************
Trong ba loại truy vấn thì loại 2 là cần lưu ý nhất. Vì để xóa 1 phần tử bất kỳ trong hàng đợi ưu tiên chúng ta sẽ phải pop toàn bộ các giá trị từ đầu cho đến khi nào gặp phần tử cần xóa thì ta sẽ ngưng.

Lúc này chúng ta sẽ phải lưu lại toàn bộ giá trị đã lấy ra, để push lại vào trong hàng đợi ưu tiên.

Ví dụ: hàng đợi ưu tiên đang có 3 8 9 12 15. Chúng ta muốn xóa giá trị 9 thì phải đem 3 và 8 ra ngoài. Sau đó, xóa 9 đi, rồi thêm 3 và 8 vào lại hàng đợi ưu tiên. Khi thao tác như vậy, nếu phần tử cần xóa nằm ở vị trí cuối cùng của hàng đợi ưu tiên vậy ta phải sử dụng hai vòng lặp, một vòng lặp để xóa và một vòng lặp để thêm lại.

==> Không khả thi vì số lượng phần tử tối đa là 10^5.


    * Cách cải tiến:

Để việc xóa không trở nên phức tạp, bạn sẽ dùng thêm một hàng đợi ưu tiên khác (tạm đặt tên là pqRemove). Khi gặp một truy vấn loại 2 thay vì xóa bạn sẽ thêm phần tử cần xóa này vào hàng đợi pqRemove.

Lúc này ở thao tác in phần tử ra màn hình (truy vấn loại 33), mỗi lần in bạn cần phải kiểm tra xem phần tử ở hàng đợi ban đầu có trùng với phần tử ở hàng đợi pqRemove không. Nếu trùng nhau nghĩa là phần tử này trước đó đã bị xóa đi. Lúc này bạn mới xóa phần tử này đi trong hàng đợi ban đầu. Còn nếu không trùng nhau thì bạn vẫn in ra giá trị ra bình thường.

Ví dụ: hàng đợi ban đầu 3 8 9 12 15. Bạn có một truy vấn xóa phần tử số 9. Thay vì xóa trong hàng đợi ban đầu bạn thêm số 9 vào pqRemove: 9.

Khi đề bài có thao tác in giá trị phần tử ra thì bạn kiểm tra phần tử trên cùng của pq có trùng với pqRemove hay không, nếu không trùng thì in phần tử trên cùng của pq (ở ví dụ trên là số 3). Còn nếu trùng thì đơn giản là chỉ việc xóa phần tử 9 ra khỏi pq và pqRemove.

Độ phức tạp: O(QlogN) với Q là số lượng truy vấn, N là số lượng phần tử được add vào hàng đợi ưu tiên.
*/


#include <iostream>
#include <queue>

using namespace std;

int main() {
    int q;
	cin >> q;
    priority_queue<int, vector<int>, greater<int>> pq;
    priority_queue<int, vector<int>, greater<int>> removePq;
    int c, v;
    for (int i = 0; i < q; i++) {
        cin >> c;

        switch (c) {
            case 1:
                cin >> v;
                pq.push(v);
                break;
            case 2:
                cin >> v;
                removePq.push(v); // later remove
                // check and remove elements from pq
                while (!removePq.empty() && removePq.top() == pq.top()) {
                    pq.pop();
                    removePq.pop();
                }
                break;
            case 3:
                cout << pq.top() << endl;
                break;
        }
    }

    return 0;
}


/*Cách 2 - Standard Code*/

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq, pqRemove;
    int Q;
    cin >> Q;

    int type, value;

    for (int k = 0; k < Q; k++) {
        cin >> type;

        if (type == 1) {
            cin >> value;
            pq.push(value);
        }
        else if (type == 2) {
            cin >> value;
            pqRemove.push(value);
        }
        else {
            while (!pqRemove.empty() && pq.top() == pqRemove.top()) {
                pq.pop();
                pqRemove.pop();
            }

            cout << pq.top() << endl;
        }
    }
    return 0;
}

/*Python*/
import queue

q = int(input())
pq = queue.PriorityQueue()
pqRemove = queue.PriorityQueue()

for i in range(q):
    line = input()

    if line[0] == '1':
        value = int(line.split()[1])
        pq.put(value)
    elif line[0] == '2':
        value = int(line.split()[1])
        pqRemove.put(value)
    else:
        while not pqRemove.empty() and pq.queue[0] == pqRemove.queue[0]:
            pq.get()
            pqRemove.get()

        print(pq.queue[0])


// java

import java.util.Scanner;
import java.util.PriorityQueue;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int Q = sc.nextInt();
        PriorityQueue<Integer> pq = new PriorityQueue<>(), pqRemove = new PriorityQueue<>();

        int type, value;

        for (int k = 0; k < Q; k++) {
            type = sc.nextInt();

            if (type == 1) {
                value = sc.nextInt();
                pq.add(value);
            }
            else if (type == 2) {
                value = sc.nextInt();
                pqRemove.add(value);
            }
            else {
                while (!pqRemove.isEmpty() && (int)pq.peek() == (int)pqRemove.peek()) {
                    pq.remove();
                    pqRemove.remove();
                }

                System.out.println(pq.peek());
            }
        }
    }
}

//------------
import queue

q = int(input())
pq = queue.PriorityQueue()
pqRemove = queue.PriorityQueue()

for i in range(q):
    line = input()

    if line[0] == '1':
        value = int(line.split()[1])
        pq.put(value)
    elif line[0] == '2':
        value = int(line.split()[1])
        pqRemove.put(value)
    else:
        while not pqRemove.empty() and pq.queue[0] == pqRemove.queue[0]:
            pq.get()
            pqRemove.get()

        print(pq.queue[0])