// Solution: OPCPIZZA - Pizzamania
// Link: https://www.spoj.com/problems/OPCPIZZA

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
long long arr[MAX];

int main() {
    int t;
    cin >> t;

    int n;
    long long m;
    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; i++)
            cin >> arr[i];

        sort(arr, arr + n);

        int i = 0;
        int j = n - 1;
        int cnt = 0;
        while (i < j) {
            if (arr[i] + arr[j] == m) {
                cnt++;
                i++;
                j--;
            } else if (arr[i] + arr[j] > m) {
                j--;
            } else {
                i++;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}

// Standard
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool binarySearch(vector<int> &a, int left, int right, int x) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (a[mid] == x) {
            return true;
        }
        else if (a[mid] > x) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return false;
}

int main() {
    int t, n, m, cnt, comp;
    vector<int> a;
    cin >> t;

    for (int k = 0; k < t; k++) {
        cin >> n >> m;
        a.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());
        cnt = 0;

        for (int i = 0; i < n; i++) {
            comp = m - a[i];
            if (binarySearch(a, i + 1, n - 1, comp)) {
                cnt++;
            }
        }

        cout << cnt << endl;
	}
    return 0;
}

// Python
def BinarySearch(a, left, right, x):
    while left <= right:
        mid = (left + right) // 2
    
        if a[mid] == x:
            return True
        elif a[mid] > x:
            right = mid - 1
        else:
            left = mid + 1
                
    return False

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    cnt = 0
    
    for i in range(n):
        comp = m - a[i]
        if BinarySearch(a, i + 1, n - 1, comp):
            cnt += 1

    print(cnt)