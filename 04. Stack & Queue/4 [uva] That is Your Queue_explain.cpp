/*
Nhận xét:

    + Hàng đợi khám bệnh có thể dễ dàng được mô phỏng bằng cấu trúc queue với quy tắc FIFO.
    + Ban đầu, các bệnh nhân xếp hàng theo thứ tự từ nhỏ đến lớn, tương đương với việc ta đưa vào hàng đợi lần lượt các phần tử có giá trị từ 1 đến P. Như vậy đối với truy vấn N, ta chỉ việc lấy phần tử ở đầu hàng đợi ra và đưa lại vào cuối hàng.
    + Đối với truy vấn E x, ta cần đưa phần tử có giá trị đúng bằng x lên đầu hàng đợi. Yêu cầu này có thể được thực hiện thông qua hai bước như sau:

        * Đưa giá trị xx vào cuối hàng.
        * Lần lượt lấy từng giá trị (khác x) ở đầu hàng và đưa vào sau xx.
        * Cụ thể, giả sử hàng đợi lúc này của ta có dạng {1,2,3,x,4,5}. Đầu tiên, ta sẽ đưa x vào cuối hàng đợi, thu được {1,2,3,x,4,5,x}. Lúc này, để x giữ vai trò là phần tử đầu tiên của hàng đợi mới, ta lần lượt đưa các phần tử còn lại (khác x) vào sau x. Hàng đợi trở thành {x,1,2,3,4,5}.

    Tuy nhiên, ta thấy rằng nếu chỉ thực hiện như các bước trên thì độ phức tạp sẽ rất lớn do hàng đợi lúc này có kích thước đúng bằng P với P tối đa là 1.000.000.000 – chi phí lấy ra và đưa ngược lại toàn bộ các phần tử hiện có trong hàng đợi khi xử lý truy vấn Ex là vô cùng tốn kém.

    Mặt khác, ta cũng nhận thấy rằng trong trường hợp C truy vấn đều thuộc N và giá trị của C<P, chẳng hạn ta có một hàng đợi 10 người {1,2,3,4,5,6,7,8,9,10} và chỉ thực hiện 3 truy vấn N thì tối đa ta chỉ thao tác trên 3 phần tử {1,2,3} mà thôi. Nói cách khác, việc khởi tạo một hàng đợi 10 người là không cần thiết. Do đó, để tối ưu ta chỉ cần khởi tạo hàng đợi ban đầu với các giá trị từ 11 đến min(P, C) (với C tối đa chỉ bằng 1.000). (Lưu ý rằng với cách khởi tạo này, khi xuất hiện các truy vấn Ex không làm mất tính chính xác của giải thuật vì nếu x không tồn tại trong các giá trị được khởi tạo ban đầu của hàng đợi thì cũng tự động được thêm vào.)

Tóm lại, ta có các bước giải này như sau:

    Bước 1: Khởi tạo hàng đợi khám bệnh. Đưa vào hàng đợi lần lượt các giá trị từ 11 đến min(PP, CC).
    Bước 2: Duyệt qua từng truy vấn:
    Truy vấn N: In ra phần tử đầu tiên ở đầu hàng đợi, xóa phần tử đó và đưa nó lại vào cuối hàng.
    Truy vấn E x:
        * Gán nn là kích thước hiện tại của hàng đợi.
        * Đưa xx vào cuối hàng đợi.
        * Lặp n lần, đưa lần lượt các phần tử khác x vào cuối hàng.
    Bước 3: Reset các biến, chuẩn bị cho bộ test tiếp theo.

Độ phức tạp: O(T∗C∗(min(P,C)+C)) với T là số lượng bộ test, P là số lượng người đến khám bệnh và C là số lượng truy vấn cần xử lý.
*/

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

int main()
{
    int P, C, x, temp, tc = 1;
    char cmd;
    queue<int> q;

    while (true)
    {
        cin >> P >> C;
        if (P == 0 && C == 0)
        {
            break;
        }

        for (int i = 1; i <= min(P, C); i++)
        {
            q.push(i);
        }

        cout << "Case " << tc++ << ":" << endl;

        for (int i = 0; i < C; i++)
        {
            cin >> cmd;

            if (cmd == 'N')
            {
                temp = q.front();
                cout << temp << endl;
                q.pop();
                q.push(temp);
            }
            else
            {
                cin >> x;
                int n = q.size();
                q.push(x);

                for (int j = 0; j < n; j++)
                {
                    temp = q.front();
                    q.pop();
                    if (temp != x)
                    {
                        q.push(temp);
                    }
                }
            }
        }

        while (!q.empty())
        {
            q.pop();
        }
    }
    return 0;
}