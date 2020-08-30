/*
Duyệt từng ký tự trong chuỗi hóa chất:

Nếu ký tự đó là chữ ‘C’, ‘H’, hoặc ‘O’ thì bỏ lần lượt số 12, 1, 16 vào stack.

Nếu ký tự là số thì lấy phần tử đầu stack ra và nhân với số này, rồi bỏ lại vào trong stack.

Nếu ký tự đó là mở ngoặc ‘(‘ thì bỏ vào −1 stack giống ‘C’, ‘H’, ‘O’.

Nếu ký tự đó là đóng ngoặc ‘)’ thì lấy các số trong stack ra và cộng lại với nhau cho đến khi nào gặp −1 (nghĩa là dấu mở ngoặc) thì ngưng.

Khi duyệt xong toàn bộ chuỗi hóa chất thì lấy toàn bộ số trong stack ra cộng lại và đó là kết quả của bài toán cần tìm.

Độ phức tạp: O(N) với N là độ dài của chuỗi hóa chất.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int mass(char c)
{
    return c == 'H' ? 1 : (c == 'C' ? 12 : 16);
}

int main()
{
    string s;
    cin >> s;

    stack<int> atom;
    int w, mol;

    for (char c : s)
    {
        if (isalpha(c))
        {
            atom.push(mass(c));
        }
        else if (isdigit(c))
        {
            mol = atom.top() * (c - '0');
            atom.pop();
            atom.push(mol);
        }
        else if (c == '(')
        {
            atom.push(-1);
        }
        else if (c == ')')
        {
            w = 0;
            while (atom.top() != -1)
            {
                w += atom.top();
                atom.pop();
            }
            atom.pop();
            atom.push(w);
        }
    }

    int sum = 0;
    while (!atom.empty())
    {
        sum += atom.top();
        atom.pop();
    }

    cout << sum;
    return 0;
}