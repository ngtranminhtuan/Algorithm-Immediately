// Problem: B. Tanya and Postcard
// Link: https://codeforces.com/contest/518/problem/B


#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
	string s, t;
	cin >> s >> t;

    unordered_map<char, int> charCounts;
	char ch;
	for (int i = 0; i < t.size(); i++) {
        ch = t[i];
        charCounts[ch]++;
	}

	int yay = 0;
	for (int i = 0; i < s.size(); i++) {
        ch = s[i];
        if (charCounts[ch] > 0) {
            yay++;
            charCounts[ch]--;
            s[i] = '.';
        }
	}

	int whoops = 0;
	for (int i = 0; i < s.size(); i++) {
        ch = s[i];
        if (ch != '.') {
            if (islower(ch)) {
                if (charCounts[toupper(ch)] > 0) {
                    whoops++;
                    charCounts[toupper(ch)]--;
                }
            } else {
                if (charCounts[tolower(ch)] > 0) {
                    whoops++;
                    charCounts[tolower(ch)]--;
                }
            }
        }
	}

	cout << yay << " " << whoops << endl;

	return 0;
}

// St
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    string message, newspaper;
    map<int, int> a, b;
    int n, m, yay = 0, whoops = 0;
    cin >> message >> newspaper;
    
    for (int i = 0; message[i] != 0; i++) {
        int id = message[i] - 'A';
        if (message[i] > 'Z')
            id = message[i] - 'a' + 26;
        a[id]++;
    }
    for (int i = 0; newspaper[i] != 0; i++) {
        int id = newspaper[i] - 'A';
        if (newspaper[i] > 'Z')
            id = newspaper[i] - 'a' + 26;
        b[id]++;
    }
    
    for (int i = 0; i < 52; i++) {
        int tmp = min(a[i], b[i]);
        yay += tmp;
        a[i] -= tmp; b[i] -= tmp;
    }
    for (int i = 0; i < 26; i++) {
        whoops += min(a[i], b[i+26]) + min(a[i+26], b[i]);
    }
    cout << yay << " " << whoops;
    return 0;
}

// Py
message = input()
newspaper = input()
a = dict([ (i, 0) for i in range(52) ])
b = dict([ (i, 0) for i in range(52) ])
for ch in message:
    id = ord(ch) - 65
    if (ch > 'Z'):
        id = ord(ch) - 97 + 26
    if not id in a:
        a[id] = 1
    else:
        a[id] += 1
for ch in newspaper:
    id = ord(ch) - 65
    if (ch > 'Z'):
        id = ord(ch) - 97 + 26
    if not id in b:
        b[id] = 1
    else:
        b[id] += 1
yay = 0
whoops = 0
for i in range(52):
    tmp = min(a[i], b[i])
    yay += tmp
    a[i] -= tmp
    b[i] -= tmp
for i in range(26):
    whoops += min(a[i], b[i+26]) + min(a[i+26], b[i])
print("%d %d" % (yay, whoops))