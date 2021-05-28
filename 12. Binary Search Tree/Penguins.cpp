#include <bits/stdc++.h> 
  
using namespace std; 
  
int n; 
map <string , int> mymap; 
string s; 
  
int main () {
    cin >> n; 
  
    cin.ignore(); 
  
    while (n--) {
        getline(cin , s); 
        mymap[s]++; 
    }
  
    string res; 
    int maxi = -1; 
  
    for (map <string , int> :: iterator it = mymap.begin(); it != mymap.end(); it++) 
        if (maxi < it->second) {
            maxi = it->second; 
            res = it->first; 
        }
  
    cout << res; 
    return 0; 
}

// Python
def solve():
    n = int(input())
    S = dict()
    for i in range(n):
        name = input()
        if name in S:
            S[name] = S[name] + 1
        else:
            S[name] = 1
    ans = ""
    max = 0
    for item in S:
        if S[item] > max:
            max = S[item]
            ans = item
    print (ans)
 
solve()