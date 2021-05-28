#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 5;

struct Bill {
    int number, price;
};

struct BillAscendingPrice {
    bool operator() (const Bill &a, const Bill &b) {
        return a.price < b.price;
    }
};

struct BillDescendingPrice {
    bool operator() (const Bill &a, const Bill &b) {
        return a.price > b.price;
    }
};

int main() {
    int n, k, x, nbills = 0;
    long long money = 0;
    bool taken[MAX] = {};
    priority_queue<Bill, vector<Bill>, BillAscendingPrice> maxHeap;
    priority_queue<Bill, vector<Bill>, BillDescendingPrice> minHeap;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        cin >> k;

        for (int j = 0; j < k; j++) {
            cin >> x;
            nbills++;
            maxHeap.push((Bill) {nbills, x});
            minHeap.push((Bill) {nbills, x});
        }

        while (taken[maxHeap.top().number]) {
            maxHeap.pop();
        }

        while (taken[minHeap.top().number]) {
            minHeap.pop();
        }

        money += maxHeap.top().price - minHeap.top().price;
        taken[maxHeap.top().number] = taken[minHeap.top().number] = true;
        maxHeap.pop();
        minHeap.pop();
    }

    cout << money;
    return 0;
}


// ---------
import heapq

taken = [False] * 1000005
maxHeap = []
minHeap = []
money = 0
nbills = 0

n = int(input())

for _ in range(n):
    a = list(map(int, input().split()))
    
    for x in a[1:]:
        nbills += 1
        heapq.heappush(maxHeap, (-x, nbills))
        heapq.heappush(minHeap, (x, nbills))

    while taken[maxHeap[0][1]]:
        heapq.heappop(maxHeap)
    
    while taken[minHeap[0][1]]:
        heapq.heappop(minHeap)
    
    taken[maxHeap[0][1]] = taken[minHeap[0][1]] = True
    money += -heapq.heappop(maxHeap)[0] - heapq.heappop(minHeap)[0]

print(money)