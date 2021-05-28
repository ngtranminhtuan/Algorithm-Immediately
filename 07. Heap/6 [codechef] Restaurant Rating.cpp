// Problem: Restaurant Rating
// Link: https://www.codechef.com/problems/RRATING


#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, type, nreviews = 0;
    priority_queue<int, vector<int>, greater<int>> top3;
    priority_queue<int> rest;
    cin >> n;

    while (n--) {
        cin >> type;
    
        if (type == 1) {
            cin >> x;
            nreviews++;
    
            if (!top3.empty() && top3.top() < x) {
                rest.push(top3.top());
                top3.pop();
                top3.push(x);
            }
            else {
                rest.push(x);
            }
    
            if (nreviews % 3 == 0) {
                top3.push(rest.top());
                rest.pop();
            }
        }
        else {
            if (top3.empty()) {
                cout << "No reviews yet" << endl;
            }
            else {
                cout << top3.top() << endl;
            }
        }
    }
    return 0;
}

// ----------
import heapq
top3 = []
rest = []
nreviews = 0

n = int(input())

for _ in range(n):
    line = list(map(int, input().split()))
    type = line[0]
    
    if type == 1:
        x = line[1]
        nreviews += 1

        if len(top3) != 0 and top3[0] < x:
            heapq.heappush(rest, -heapq.heappop(top3))
            heapq.heappush(top3, x)
        else:
            heapq.heappush(rest, -x)

        if nreviews % 3 == 0:
            heapq.heappush(top3, -heapq.heappop(rest))
    else:
        if len(top3) == 0:
            print("No reviews yet")
        else:
            print(top3[0])