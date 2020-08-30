/*
Nhận xét:

    + Xét trên phạm vi một biểu thức lớn có thể có nhiều ngoặc lồng nhau, ta thấy rằng dấu mở ngoặc chính là báo hiệu bắt đầu của một biểu thức con mới, còn dấu đóng ngoặc chính là báo hiệu kết thúc của một biểu thức con liền kề trước nó --→ Gần với nguyên tắc hoạt động LIFO của stack.
    + Hơn nữa, khác với biểu thức thông thường có phép toán được đặt giữa hai toán hạng thì trong cách biểu diễn theo ký pháp Ba Lan ngược, phép toán được thực hiện trên hai toán hạng liền trước nó. Như vậy, với một biểu thức a + b, ta có thể chuyển qua dạng ab++ dễ dàng bằng cách in ra các toán hạng trước, sau đó sẽ in ra phép toán ++.
    + Từ những nhận định trên, ta nảy ra ý tưởng chuyển từ biểu thức có dạng ((a ++ b)) sang ab++ bằng cách: Duyệt qua chuỗi ký tự, nếu gặp dấu ngoặc “((“ thì ta bỏ qua, gặp ký tự chữ cái thì in thẳng ra màn hình, còn gặp phép toán thì bỏ nó vào stack. Như vậy, khi gặp được dấu “))” tiếp theo, ta chắc chắn phép toán trên đầu stack thuộc về biểu thức đang được in ra trên màn hình, ta in phép toán này ra và xóa nó ra khỏi stack.
    + Trường hợp các dấu ngoặc lồng nhau chỉ là một trường hợp đặc biệt có thể giải quyết bằng ý tưởng trên.

Như vậy, ta có cách giải của bài này như sau:

    Bước 1: Đọc vào biểu thức cần chuẩn hóa.
    Bước 2: Duyệt qua từng ký tự từ đầu tới cuối chuỗi, nếu ký tự đó là:
        * Ký tự chữ cái: in ra màn hình.
        * Dấu đóng ngoặc “))”: in phép toán đầu tiên trong stack ra màn hình.
        * Phép toán hợp lệ: đưa vào stack.
    Bước 3: Reset các biến, chuẩn bị cho bộ test tiếp theo.

Độ phức tạp: O(T∗len(expression)) với T là số lượng bộ test và len(expression) là độ dài biểu thức.
*/
#include <iostream>
#include <stack>
#include <string>
using namespace std;

void transform(string expression)
{
    stack<char> s;

    for (char symbol : expression)
    {
        if (isalpha(symbol))
        {
            cout << symbol;
        }
        else if (symbol == ')')
        {
            cout << s.top();
            s.pop();
        }
        else if (symbol != '(')
        {
            s.push(symbol);
        }
    }
    cout << endl;
}

int main()
{
    int t;
    string expression;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> expression;
        transform(expression);
    }
    return 0;
}