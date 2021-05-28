#include <iostream>
#include <set>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int T, N, M;
    long long temp;
    set<long long> s;
    cin >> T;
    while (T--) {
        s.clear();
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            s.insert(temp);
        }
        for (int i = 0; i < M; i++) {
            cin >> temp;
            cout << (s.find(temp) != s.end() ? "YES" : "NO") << endl;
            s.insert(temp);
        }
    }
    return 0;
}

// Python
import sys
  
lines = sys.stdin.readlines()
testcase = int(lines[0])
l = 1
for t in range(testcase):
    n, m = map(int, lines[l].split())
    l += 1
    s = set()
    a = list(map(int, lines[l].split()))
    l += 1
    for x in a[:n]:
        s.add(x)
    for x in a[n:]:
        if x in s:
            print("YES")
        else:
            print("NO")
        s.add(x)