// Problem: 10341 - Solve It
// Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1282
// 
// Complexity:

#include <iostream>
#include <algorithm>
#include <math.h>       /* exp */
using namespace std;
#define EPSILON 1e-5

int p, q, r, s, t, u;

// f is a non-increasing function on [0,1]
double f(double x) {
    return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

void solve() {
    double left = 0;
    double right = 1.0d;
    while (left < right) {
        double mid = left + (right - left) / 2;
        double f0 = f(mid);
        if (abs(f0) < EPSILON) {
            cout.precision(5);
            cout << mid << endl;
            return;
        } else if (f0 > 0) { // -> since f is a non-increasing function -> so we find x on [0, mid]
            right = mid;
        } else {
            left = mid;
        }
    }

    cout << "No solution" << endl;
}

int main() {
    while (cin >> p) {
        cin >> q >> r >> s >> t >> u;

        solve();
    }

	return 0;
}

// Standard
#include <bits/stdc++.h> 

using namespace std; 

const double eps = 1e-8; 

double f(double p , double q , double r , double s , double t , double u , double x) {
	return (p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);  
}

double p , q , r , s , t , u; 

int main () {
	while (cin >> p >> q >> r >> s >> t >> u) {
		double lo = 0.000; 
		double hi = 1.000;

		if (f(p , q , r , s , t , u , 1.0) > 1e-9 || p + r + u < 0) {
			cout << "No solution" << endl; 
			continue; 
		}

		double res = -1;  

		for (int i = 0; i <= 1000; i++) {
			double x = (lo + hi) / 2.0; 
			double F = f(p , q , r , s , t , u , x);

			if (F > 0) lo = x; 
			else hi = x; 
		}

		cout << fixed << setprecision(4) << lo << endl;  
	}
	return 0; 
}

// Python
import math

def inp():
    return map(int, input().split(' '))

def f(p , q , r , s , t , u , x):
    return p * math.exp(-x) + q * math.sin(x) + r * math.cos(x) + s * math.tan(x) + t * x * x + u

def solve():
    while True:
        try:
            p, q, r, s, t, u = map(float, input().split(' '))

            if f(p, q, r, s, t, u, 1.0) > 1e-9 or p + r + u < 0:
                print("No solution")
                continue

            res = -1
            lo = 0.000
            hi = 1.000
            for i in range(100):
                mid = (lo + hi) / 2.0
                F = f(p, q, r, s, t, u, mid)
                if F > 0:
                    lo = mid
                else:
                    hi = mid
            print('{:0.4f}'.format(lo))
        except EOFError:
            break

solve()