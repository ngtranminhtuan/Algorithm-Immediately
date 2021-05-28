#include <iostream>
#include <set>
using namespace std;
 
int main() {
    int T, N, X, temp;
    set<int> s;
    cin >> T;
 
    while (T--) {
        s.clear();
        cin >> N >> X;
 
        for (int i = 0; i < N; i++) {
            cin >> temp;
            s.insert(temp);
        }
 
        int diff = s.size();
 
        if (diff == X) {
            cout << "Good" << endl;
        }
        else {
            cout << (diff < X ? "Bad" : "Average") << endl;
        }
    }
    return 0;
}

// Python
def inp():
    return map(int, input().split())
 
 
def solve():
    testcase = int(input())
    for t in range(testcase):
        n, x = inp()
        s = set()
        for a in list(inp()):
            s.add(a)
        unique = len(s)
        if unique == x:
            print("Good");
        elif unique < x:
            print("Bad")
        else:
            print("Average")
 
 
if __name__ == '__main__':
    solve()