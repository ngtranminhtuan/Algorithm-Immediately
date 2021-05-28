/*
Nhận xét:

    Ở mỗi bên bờ sông, quá trình xếp hàng chờ đợi của những chiếc xe có thể được mô phỏng bằng cấu trúc dữ liệu queue. Ta có thể sử dụng 2 queue để mô phỏng quá trình này, với mỗi queue tương ứng với một bên bờ sông.
    Các bước giải quyết bài toán như sau:

        + Bước 1: Khởi tạo 2 queue để lưu trữ tình trạng xếp hàng ở mỗi bên bờ sông.
        + Bước 2: Đọc và xử lí dữ liệu vào, lần lượt tương ứng với từng xe. Với xe thứ i, ta cần đọc các dữ liệu vào:
            * Đọc vào thời gian đến nơi của xe thứ i, tạm gọi là arriveTime[i]
            * Đọc vào vị trí bờ sông của xe thứ i. Nếu bờ sông của xe thứ i là left, ta push dữ liệu của xe thứ i vào queue tương ứng của bờ sông bên trái. Ngược lại, nếu là right, ta push dữ liệu đó vào queue của bờ sông bên phải.
        + Bước 3: khởi tạo một số biến như sau:
            * curTimecurTime: cho biết thời gian hiện tại của quá trình mô phỏng. Giá trị ban đầu bằng 0.
            * curSidecurSide: nhận giá trị 0 và 1, cho biết con tàu hiện tại đang nằm bên bờ sông nào.
            ans[]: mảng có M phần tử (M là số lượng xe), với ans[i] cho biết thời gian cập bến của xe thứ i
        + Bước 4: mô phỏng quá trình xe đang vận chuyển. Ta sẽ thực hiện liên tục như sau:
            * Nếu như cả 2 queue rỗng, tức là tất cả các xe đều đã được vận chuyển, ta kết thúc thuật toán.
            * Ngược lại, nếu ít nhất một queue còn xe, nghĩa là quá trình vận chuyển chưa kết thúc, ta xem xét xe tiếp theo cần được vận chuyển là xe nào. Ta sẽ xét arriveTimearriveTime đầu tiên của 22 queue (nếu queue đó vẫn còn xe), và lấy thời gian đến sớm hơn. Gọi thời gian đó là nextTime:
                * Nếu curTime < nextTime, có nghĩa là xe tiếp theo chưa đến để xếp hàng. Ta sẽ phải đặt curTime = nextTime để tiếp tục quá trình vận chuyển.
            * Xét queue ở bờ sông curSide, mà con thuyền đang neo đậu:
                Chừng nào xe đầu tiên của queue bên curSidecurSide đã đến nơi (tức là arriveTime[i] của xe tiếp theo curTime≤curTime), ta đặt ans[i]=curTime+t (xe thứ i đã được vận chuyển xong), và pop xe đó ra khỏi queue.
            Lưu ý rằng tải trọng tối đa của thuyền là N xe. Vì vậy ta cần đảm bảo rằng ta không pop một lần nhiều hơn N xe ra khỏi queue. Việc này có thể được thực hiện bằng một biến đếm.
            Đặt curTime=curTime+t, và curSide=1−curSide, có nghĩa là thuyền đã di chuyển sang bên kia sông, mất t thời gian.
        + Bước 5: in ra mảng đáp án ans[].

Độ phức tạp: O(T∗M) với M là số lượng xe qua sông, T là số lượng test
*/
#include <iostream>
#include <queue>
#define MAX 10000 + 5
using namespace std;

struct Car
{
    int id, arriveTime;
};

int main()
{
    int n, t, m, Q;
    int res[MAX];
    cin >> Q;

    while (Q--)
    {
        queue<Car> qSide[2];
        int arrived;
        string atBank;

        cin >> n >> t >> m;

        for (int i = 1; i <= m; i++)
        {
            cin >> arrived >> atBank;

            if (atBank == "left")
            {
                qSide[0].push((Car){i, arrived});
            }
            else
            {
                qSide[1].push((Car){i, arrived});
            }
        }

        int curSide = 0, curTime = 0, nextTime;
        int waiting = !qSide[0].empty() + !qSide[1].empty();

        while (waiting)
        {
            if (waiting == 1)
            {
                nextTime = (qSide[0].empty() ? qSide[1].front().arriveTime : qSide[0].front().arriveTime);
            }
            else
            {
                nextTime = min(qSide[0].front().arriveTime, qSide[1].front().arriveTime);
            }

            curTime = max(curTime, nextTime);
            int carried = 0;

            while (!qSide[curSide].empty())
            {
                Car car = qSide[curSide].front();
                if (car.arriveTime <= curTime && carried < n)
                {
                    res[car.id] = curTime + t;
                    carried++;
                    qSide[curSide].pop();
                }
                else
                {
                    break;
                }
            }

            curTime += t;
            curSide = 1 - curSide;
            waiting = !qSide[0].empty() + !qSide[1].empty();
        }

        for (int i = 1; i <= m; i++)
        {
            cout << res[i] << endl;
        }

        if (Q)
        {
            cout << endl;
        }
    }
    return 0;
}

//-------
import queue
 
class Car:
    def __init__(self, _id, _arriveTime):
        self.id = _id
        self.arriveTime = _arriveTime
 
Q = int(input())
 
for _ in range(Q):
    qSide = [[] , []]
    qSide[0] = queue.Queue()
    qSide[1] = queue.Queue()
    res = [0] * 10005
     
    n, t, m = map(int, input().split())
     
    for i in range(m):
        arrived, atBank = input().split()
         
        if atBank == "left":
            qSide[0].put(Car(i, int(arrived)))
        else:
            qSide[1].put(Car(i, int(arrived)))
     
    curTime, curSide = 0, 0
    waiting = (not qSide[0].empty()) + (not qSide[1].empty())
     
    while waiting:
        if waiting == 1:
            nextTime = qSide[1].queue[0].arriveTime if qSide[0].empty() else qSide[0].queue[0].arriveTime
        else:
            nextTime = min(qSide[0].queue[0].arriveTime, qSide[1].queue[0].arriveTime)
         
        curTime = max(curTime, nextTime)
        carried = 0
         
        while not qSide[curSide].empty():
            car = qSide[curSide].queue[0]
            if car.arriveTime <= curTime and carried < n:
                res[car.id] = curTime + t
                carried += 1
                qSide[curSide].get()
            else:
                break
         
        curTime += t
        curSide = 1 - curSide
        waiting = (not qSide[0].empty()) + (not qSide[1].empty())
     
    for i in range(m):
        print(res[i])
     
    if _ < Q - 1:
        print()