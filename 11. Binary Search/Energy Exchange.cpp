#include <iostream>
#include <cstdio>
using namespace std;
#define MAX 10000
#define MAX_A 1000
int n, k, A[MAX];
double sumEnergy, sumTransfer, _left, _right, mid;

int main() {
    scanf("%d %d", &n, &k);
    sumEnergy = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        sumEnergy += A[i];
    }
    
    _left = 0;
    _right = MAX_A;
    while (_right - _left > 1e-7) {
        mid =(_left + _right) / 2;
        sumTransfer = 0;
        for (int i = 0; i < n; i++) {
            if (A[i] > mid)
                sumTransfer += A[i] - mid;
        }
        if (mid * n < sumEnergy - sumTransfer*k/100) {
        	_left = mid;
        }
        else {
        	_right = mid;
        }
    }
    printf("%.9f", _left);
    return 0;
}

// Python
n, k = map(int, input().split())
a = list(map(int, input().split()))

sum_energy = sum(a)

left = 0
right = 1000
while right - left > 1e-7:
    mid = (left + right) / 2
    sum_transfer = 0
    for x in a:
        if x > mid:
            sum_transfer += x - mid
    if mid * n < sum_energy - sum_transfer * k / 100:
        left = mid
    else:
        right = mid

print('%.9f' % left)