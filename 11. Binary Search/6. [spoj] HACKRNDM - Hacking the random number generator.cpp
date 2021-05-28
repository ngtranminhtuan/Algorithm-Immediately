// Problem: HACKRNDM - Hacking the random number generator
// Link: https://www.spoj.com/problems/HACKRNDM/
// 
// Complexity: O(NlogN)

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
int arr[MAX];

int binarySearch(int* arr, int l, int r, int x) {
    int m;
    while (l <= r) {
        m = (l + r) / 2;
        if (arr[m] == x)
            return m;
        else if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return -1;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int countPairs = 0;
    for (int i = 0; i < n; i++) {
        if (binarySearch(arr, i + 1, n, arr[i] + k) != -1) {
            countPairs++;
        }
    }

    cout << countPairs << endl;

	return 0;
}


// Standard

#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    vector<int> a;

    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    long long count = 0;
    vector<int>::iterator it;
    for (int i = 0; i < n; i++) {
        it = lower_bound(a.begin(), a.end(), a[i] + k);
        if (it != a.end() && *it == a[i] + k) {
            count++;
        }        
    }
    cout << count;
    return 0;
}

// Python
import sys
class Scanner:
    def __init__(self, istream):
        self.tokenizer = Scanner.__tokenizer__(istream)
    def __tokenizer__(istream):
        for line in istream:
                for token in line.strip().split():
                        yield token
    def next(self):
        return self.tokenizer.__next__()

def BS_search(a, l, r, value):
    while l <= r:
        mid = int( (l + r) / 2 )
        if a[mid] == value:
            return True
        if a[mid] > value:
            r = mid - 1
        else:
            l = mid + 1
    return False

def solve():
    sc = Scanner(sys.stdin)
    n = int(sc.next())
    k = int(sc.next())
    a = []
    for i in range(n):
        x = int(sc.next())
        a.append(x)
    a.sort()
    ans = 0
    j = 0
    for i in range(n):
        while j < i and  a[i] - a[j] > k:
            j += 1
        if a[i] - a[j] == k:
            ans += 1
    print(ans)

solve()