// Problem: Compilers and parsers
// Link: https://www.codechef.com/MAY14/problems/COMPILER

/*
Với mỗi biểu thức, ta bắt đầu duyệt lần lượt từng kí tự trong chuỗi: Gặp kí tự ‘<’ ta bỏ vào stack, ngược lại:

    + Xét xem stack có rỗng không: nếu rỗng nghĩa là có dấu ‘>’ nhưng không có dấu ‘<’ nào trước nó nên ta ngưng duyệt chuỗi.
    + Ngược lại, ta lấy phần đầu của stack ra và một lần nữa kiểm tra xem stack có rỗng không, nếu có ta cập nhật kết quả là i+1.

Độ phức tạp: O(T∗N) với T là số lượng test case và N là số lượng biểu thức.
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    int T, ans;
    string s;
    cin >> T;

    for (int k = 0; k < T; k++)
    {
        cin >> s;
        stack<char> expr;
        ans = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '<')
            {
                expr.push(s[i]);
            }
            else if (expr.empty())
            {
                break;
            }
            else
            {
                expr.pop();
                ans = (expr.empty() ? i + 1 : ans);
            }
        }

        cout << ans << endl;
    }
    return 0;
}

//---------
T = int(input())
 
for _ in range(T):
    s = input()
    expr = []
    ans = 0
 
    for i in range(len(s)):
        if s[i] == '<':
            expr.append(s[i])
        elif len(expr) == 0:
            break
        else:
            expr.pop()
            ans = i + 1 if len(expr) == 0 else ans
     
    print(ans)