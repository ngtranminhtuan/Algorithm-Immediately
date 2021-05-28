// Problem: 10954 - Add All
// Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895


#include <iostream>
#include <queue>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    int n, x;
    
    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        for (int i = 0; i < n; i++) {
            cin >> x;
            pq.push(x);
        }

        long long ans = 0;

        while (pq.size() > 1) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }

        cout << ans << endl;
        pq.pop();
    }
    return 0;
}

// ----------
import queue
pq = queue.PriorityQueue()

while True:
    n = int(input())
    
    if n == 0:
        break

    for x in input().split():
        pq.put(int(x))
    
    ans = 0
    
    while pq.qsize() > 1:
        a = pq.get()
        b = pq.get()
        ans += a + b
        pq.put(a + b)

    print(ans)
    pq.get()