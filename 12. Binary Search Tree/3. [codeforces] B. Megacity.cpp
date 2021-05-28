// Problem: B. Megacity
// Link: https://codeforces.com/problemset/problem/424/B


#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;

#define MEDACITY_PEOPLE_REQUIRE 1000000

int main() {
	int n, s;
	cin >> n >> s;

	map<int, int> mapRadiusToPeople;
	int x, y, k;
	for (int i = 0; i < n; i++) {
        cin >> x >> y >> k;
        mapRadiusToPeople[x*x + y*y] += k;
	}

	int population = s;
	int minRadius = -1;
	for (map<int, int>::iterator it = mapRadiusToPeople.begin(); it != mapRadiusToPeople.end(); ++it) {
        population += it->second;
        if (population >= MEDACITY_PEOPLE_REQUIRE) { // can become megacity
            minRadius = it->first;
            break;
        }
	}

	if (minRadius == -1)
        cout << -1 << endl;
    else
        cout << fixed << setprecision(6) << sqrt(minRadius) << endl;

	return 0;
}


// Standard
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
using namespace std;
 
int main() {
    int numLocation, totalPeople, people;
    double x, y;
    cin >> numLocation >> totalPeople;
    map<double, int> location;
    for (int i = 0; i < numLocation; ++ i) {
        cin >> x >> y;
        cin >> people;
        /*
        Tính bán kính của đường tròn, do tâm thành phố là (0, 0) 
        nên để tính bán kính thì chỉ cần công thức bên dưới là đủ 
        thay cho công thức sqrt((x1-x0)*(x1-x0) + (y1-y0)*(y1-y0))
        */
        double r = x * x + y * y;
        if (location.find(r) != location.end()) 
            location[r] += people;
        else
            location[r] = people;
    }
    for (map<double, int>::iterator it = location.begin(); it != location.end(); ++it) {
        totalPeople += it->second;
        if (totalPeople >= 1000000) {
            cout << fixed << setprecision(6) << sqrt(it->first) << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}

// Python
import math
 
def solve():
    numLocation, totalPeople = map(int, input().split())
    location = dict()
    for i in range(numLocation):
        x, y, people = map(int, input().split())
        r = x * x + y * y
        if r in location:
            location[r] += people
        else:
            location[r] = people
    radius = []
    for r in location:
        radius.append(r)
    radius.sort()
    for r in radius:
        totalPeople += location[r]
        if totalPeople >= 1000000:
            print(math.sqrt(r))
            return
    print("-1")
     
solve()