// Problem: 10226 - Hardwood Species
// Link: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167

#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int main() {
	int t;
	scanf("%d\n\n", &t);

	string s;
	map<string, int> mymap;
	while (t--) {
		mymap.clear();
		int n = 0;
		while (getline(cin, s)) {
			if (s == "")
				break;

			n++;
			mymap[s]++;
		}

		for (map<string, int>::iterator it = mymap.begin(); it != mymap.end(); ++it) {
			cout << it->first << " " << fixed << setprecision(4) << (it->second * 100.0f / n) << endl;
		}

		if (t > 0) {
            cout << endl;
		}
	}

	return 0;
}

// St
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// freopen("INPUT.INP", "rt", stdin);
	string s;
	set<pair<string, int> > myset;
	set< pair<string, int> >::iterator it;
	int test;
	cin >> test;
	getline(cin, s);
	getline(cin, s);
	while (test--)
	{
		int count = 0;
		while (getline(cin, s))
		{
			if (s.size() < 1)
				break;
			count++;
			it = myset.lower_bound(make_pair(s, 0));
			if (it == myset.end() || it->first != s)
				myset.insert(make_pair(s, 1));
			else
			{
				int number = (it->second) + 1;
				myset.erase(it);
				myset.insert(make_pair(s, number));
			}
		}
		
		for (it = myset.begin(); it != myset.end(); it++)
		{
			cout << (it->first).c_str() << " ";
			cout << fixed << setprecision(4) << (100.0*(it->second) / count) << endl;
		}
		if (test)
			cout << endl;
		myset.clear();
	}
	
	return 0;
}

// Python
import sys

class Node:
    def __init__(self, key = 0, value = 0, left = None, right = None):
        self.key = key
        self.value = value
        self.left = left
        self.right = right
   
    def insert(self, x):
        if x < self.key:
            if self.left:
                return self.left.insert(x)
            else:
                self.left = Node(x)
                return self.left
        elif x > self.key:
            if self.right:
                return self.right.insert(x)
            else:
                self.right = Node(x)
                return self.right
        return self
    
class Set:
    def __init__(self):
        self.root = None
        
    def insert(self, x):
        if self.root:
            return self.root.insert(x)
        else:
            self.root = Node(x)
            return self.root

def print_trees(root, total):
    if root:
        print_trees(root.left, total)
        print('%s %.4f' % (root.key, 100 * root.value / total))
        print_trees(root.right, total)

T = int(input())
try:
    input()
    for tc in range(T):
        species = Set()
        total = 0
        while True:
            specie = input()
            if specie == '':
                break
            total += 1
            cur = species.insert(specie)
            cur.value += 1
        print_trees(species.root, total)
        if tc < T - 1:
            print()
except EOFError:
    print_trees(species.root, total)
    sys.exit(0)