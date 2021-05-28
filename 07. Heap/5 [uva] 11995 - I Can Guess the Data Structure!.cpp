// Problem: 11995 - I Can Guess the Data Structure!
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3146


#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, c, v;
    while (cin >> n) {
        stack<int> s;
        queue<int> q;
        priority_queue<int> maxHeap;
        bool isStack = true, isQueue = true, isMaxHeap = true;

        while (n--) {
            cin >> c >> v;

            switch (c) {
                case 1: {
                    if (isStack) s.push(v);
                    if (isQueue) q.push(v);
                    if (isMaxHeap) maxHeap.push(v);
                    break;
                }
                case 2: {
                    if (isStack) {
                        if (s.empty() || v != s.top())
                            isStack = false;
                        else
                            s.pop();
                    }

                    if (isQueue) {
                        if (q.empty() || v != q.front())
                            isQueue = false;
                        else
                            q.pop();
                    }

                    if (isMaxHeap) {
                        if (maxHeap.empty() || v != maxHeap.top())
                            isMaxHeap = false;
                        else
                            maxHeap.pop();
                    }
                    break;
                }
            }
        }

        if (isStack && !isQueue && !isMaxHeap) {
            cout << "stack" << endl;
        } else if (!isStack && isQueue && !isMaxHeap) {
            cout << "queue" << endl;
        } else if (!isStack && !isQueue && isMaxHeap) {
            cout << "priority queue" << endl;
        } else if (!isStack && !isQueue && !isMaxHeap) {
            cout << "impossible" << endl;
        } else {
            cout << "not sure" << endl;
        }
    }

    return 0;
}

// Standard
#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, type, x;
    stack<int> s;
    queue<int> q;
    priority_queue<int> pq;
    bool isStack, isQueue, isPQ;
 
    while (cin >> n) {
        while (!s.empty()) s.pop();
        while (!q.empty()) q.pop();
        while (!pq.empty()) pq.pop();
        isStack = isQueue = isPQ = true;
 
        for (int i = 0; i < n; i++) {
            cin >> type >> x;
 
            if (type == 1) {
                s.push(x);
                q.push(x);
                pq.push(x);
            }
            else {
                if (s.empty()) {
                    isStack = isQueue = isPQ = false;
                    continue;
                }
                 
                if (s.top() != x) {
                    isStack = false;
                }
                if (q.front() != x) {
                    isQueue = false;
                }
                if (pq.top() != x) {
                    isPQ = false;
                }
 
                s.pop(); q.pop(); pq.pop();
            }
        }
         
        if (isStack + isQueue + isPQ == 0) {
            cout << "impossible" << endl;
        }
        else if (isStack + isQueue + isPQ > 1) {
            cout << "not sure" << endl;
        }
        else if (isStack) {
            cout << "stack" << endl;
        }
        else if (isQueue) {
            cout << "queue" << endl;
        }
        else {
            cout << "priority queue" << endl;
        }
    }
    return 0;
}

// Python
import queue
s = []
q = queue.Queue()
pq = queue.PriorityQueue()
 
while True:
    try:
        n = int(input())
    except EOFError:
        break
 
    s.clear()
    q.queue.clear()
    pq.queue.clear()    
    isStack = isQueue = isPQ = True
     
    for _ in range(n):
        type, x = map(int, input().split())
        if type == 1:
            s.append(x)
            q.put(x)
            pq.put(-x)
        else:
            if len(s) == 0:
                isStack = isQueue = isPQ = False
            else:
                if x != s.pop():
                    isStack = False
                if x != q.get():
                    isQueue = False
                if x != -pq.get():
                    isPQ = False
 
    if isStack + isQueue + isPQ == 0:
        print("impossible")
    elif isStack + isQueue + isPQ > 1:
        print("not sure")
    elif isStack:
        print("stack")
    elif isQueue:
        print("queue")
    else:
        print("priority queue")