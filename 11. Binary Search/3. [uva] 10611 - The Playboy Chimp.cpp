// Problem: 10611 - The Playboy Chimp
// Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=316&page=show_problem&problem=1552


#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 50000
int arr[MAX];

int highestShortThanX(int* arr, int n, int x) {
	int l, r, m;
	l = 0;
	r = n - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (arr[m] < x && (m == r || arr[m + 1] >= x)) {
			return m;
		}
		else if (arr[m] >= x) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	return -1;
}

int shortestTallerThanX(int* arr, int n, int x) {
	int l, r, m;
	l = 0;
	r = n - 1;
	while (l <= r) {
		m = (l + r) / 2;
		if (arr[m] > x && (m == l || arr[m - 1] <= x)) {
			return m;
		}
		else if (arr[m] <= x) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	return -1;
}

void printResult(int* arr, int index) {
	if (index == -1) {
		cout << "X";
	} else {
        cout << arr[index];
	}
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int q, x;
	cin >> q;
	for (int i = 0; i < q; i++) {
		cin >> x;
		printResult(arr, highestShortThanX(arr, n, x));
		cout << " ";
		printResult(arr, shortestTallerThanX(arr, n, x));
		cout << endl;
	}

	return 0;
}


// Standard
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	// freopen("test.in", "rt", stdin);
	ios::sync_with_stdio(false);

	int n, q, x, pos;
	vector<int> a;

	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x;
		a.push_back(x);
	}
	cin >> q;
	while (q--){
		cin >> x;
		pos = lower_bound(a.begin(), a.end(), x) - a.begin();
		if (pos == 0)
			cout << "X ";
		else
			cout << a[pos-1] << " ";
		pos = upper_bound(a.begin(), a.end(), x) - a.begin();
		if (pos == n)
			cout << "X\n";
		else
			cout << a[pos] << "\n";
	}

	return 0;
}

// Python
import sys

def inp():
    return map(int, input().split())


def solve():
    n = int(input())
    a = list(inp())

    q = int(input())
    query = list(inp())
    for x in query:
        pos = -1
        l = 0
        r = n-1
        while l <= r:
            mid = int( (l + r) / 2 )
            if a[mid] < x:
                pos = max(pos, mid)
                l = mid + 1
            else:
                r = mid - 1
        if pos == -1:
            ans = "X"
        else:
            ans = str(a[pos])

        pos = n
        l = 0
        r = n - 1
        while l <= r:
            mid = int( (l + r) / 2)
            if a[mid] > x:
                pos = min(pos, mid)
                r = mid - 1
            else:
                l = mid + 1
        if pos == n:
            ans += " X"
        else:
            ans += " " + str(a[pos])

        print(ans)


solve()