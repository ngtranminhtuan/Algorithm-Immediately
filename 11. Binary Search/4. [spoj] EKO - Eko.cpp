// Problem: EKO - Eko
// Link: https://www.spoj.com/problems/EKO/
// 
// Complexity: O(N * Log(max(hi)))

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 1000000

long long getCutWoodAmount(vector<int>& arr, int h) {
    long long cutWoodAmount = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > h)
            cutWoodAmount += (long long) (arr[i] - h);
    }
    return cutWoodAmount;
}

int solve(vector<int>& arr, int left, int right, int expectAmount) {
    int n = arr.size();
    int mid;
    int height = -1;
	while (left <= right) {
        mid = left + (right-left) / 2;
        long long cutWoodAmount = getCutWoodAmount(arr, mid);

        if (cutWoodAmount >= expectAmount) {
            height = mid; // the higher height the better
            left = mid + 1; // continue search on [mid+1, right]
        } else {
            right = mid - 1; // search on [left, mid - 1]
        }
	}
	return height;
}

int main() {
	int n, m;
	cin >> n >> m;

	int highestTree = 0;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
        highestTree = max(highestTree, arr[i]);
	}

    cout << solve(arr, 0, highestTree, m) << endl;

	return 0;
}

// Standard
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> trees(n);

    for (int i = 0; i < n; i++) {
        cin >> trees[i];
    }

    int hmin = 0, hmax = 1e9 + 7;
    long long sum;
    int res = 0;

    while (hmin <= hmax) {
        int hmid = (hmin + hmax) / 2;
        
        sum = 0;
        for (int &x : trees) {
            sum += max(0, x - hmid);
        }

        if (sum >= m) {
            res = hmid;
            hmin = hmid + 1;
        }
        else {
            hmax = hmid - 1;
        }
    }

    cout << res;
    return 0;
}

// Python
import sys

def inp():
    return map(int, input().split(' '))

def check(a, x):
    sum = 0
    for item in a:
        sum += max(0, item - x)
    return sum

def BS_search(a, l, r, k):
    ans = r
    while l <= r:
        mid = int( (l + r) / 2 )
        if check(a, mid) >= k:
            ans = mid
            l = mid + 1
        else:
            r = mid - 1
    return ans

def solve():
    n, k = inp()
    a = list(inp())
    vmin = 0
    vmax = 1e9
    print (BS_search(a, vmin, vmax, k))

solve()