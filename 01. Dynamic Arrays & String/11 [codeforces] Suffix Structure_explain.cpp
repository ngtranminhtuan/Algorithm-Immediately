// Problem: B. Suffix Structures
// Link: https://codeforces.com/problemset/problem/448/B?mobile=false

/*
    Trước tiên ta có nhận xét như sau:

        Nếu có một ký tự nào trong t mà không có trong s thì chắc chắn ta 
        không thể biến đổi chuỗi s thành chuỗi t được -> “need tree”.
        Nếu có một ký tự nào trong s mà không có ký tự trong t thì ta phải 
        bỏ đi ký tự đó -> “automaton”.
        Phép biến đổi “array” hoán đổi vị trí của hai ký tự chỉ cần thiết 
        nếu thứ tự xuất hiện của các ký tự trong chuỗi t không trùng khớp 
        với thứ tự của các ký tự đó trong chuỗi s.
    Để giải quyết trường hợp 1 và 2, ta sử dụng một mảng đếm tần suất 
    xuất hiện của từng ký tự trong chuỗi s và chuỗi t. Sau đó duyệt 
    từng ký tự trong bảng chữ cái gồm 26 chữ:

        * Nếu tần suất xuất hiện của ký tự đó trong chuỗi t lớn hơn chuỗi 
        s, nghĩa là chuỗi s không đủ ký tự để ta biến đổi thành 
        chuỗi t -> “need tree”.
        * Nếu tần suất xuất hiện của ký tự đó trong chuỗi t nhỏ hơn 
        chuỗi s, nghĩa là sẽ có một số ký tự thừa -> “automaton”.
    Ta cần giải quyết trường hợp 3 để có thể đưa ra kết luận là “array” 
    hay “both”.

    Bằng cách duyệt qua từng ký tự trong chuỗi t, ta tìm vị trí của 
    ký tự tương ứng trong chuỗi s. Nếu các vị trí này tăng dần nghĩa 
    là các ký tự này đã đúng vị trí, ta không cần đổi chỗ. 
    Ngược lại ta kết luận “array”.

    Xem xét liệu “automaton” và “array” có cùng thỏa hay không để đưa 
    ra kết luận là “both”.

Độ phức tạp: O(max(length(s), length(t))    

*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int sCount[26] = {0}, tCount[26] = {0};
    string s, t;
    bool need_tree = false, array = false, automaton = false;

    cin >> s >> t;

    for (int i = 0; i < s.size(); i++)
    {
        sCount[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        tCount[t[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (tCount[i] > sCount[i])
        {
            need_tree = true;
        }
        else if (tCount[i] < sCount[i])
        {
            automaton = true;
        }
    }

    int index_found = 0, match = -1;

    for (int i = 0; i < t.size(); i++)
    {
        index_found = s.find_first_of(t[i], match + 1);

        if (index_found > match)
        {
            match = index_found;
        }
        else
        {
            array = true;
            break;
        }
    }

    if (need_tree)
    {
        cout << "need tree";
    }
    else if (automaton && array)
    {
        cout << "both";
    }
    else if (automaton)
    {
        cout << "automaton";
    }
    else
    {
        cout << "array";
    }

    return 0;
}

// Python

def getChar(x):
    return chr(x + ord('a'))

s = input()
t = input()

need_tree = array = automaton = False

for i in range(26):
    t_count = t.count(getChar(i))
    s_count = s.count(getChar(i))

    if t_count > s_count:
        need_tree = True
    elif t_count < s_count:
        automaton = True

index_found, match = 0, -1

for i in range(len(t)):
    index_found = s.find(t[i], match + 1)
    if index_found > match:
        match = index_found
    else:
        array = True
        break

if need_tree:
    print("need tree")
elif automaton and array:
    print("both")
elif automaton:
    print("automaton")
else:
    print("array")