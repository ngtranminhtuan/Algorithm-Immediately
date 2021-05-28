#include <bits/stdc++.h> 

using namespace std; 

const int MAX_N = 100005; 

int a[MAX_N]; 
int n, test; 

int main () {
	scanf("%d", &test); 

	for (int t = 1; t <= test; t++) {
		printf("Case %d: ", t); 
		scanf("%d", &n); 

		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]); 
		}

		int l = 1; int r = a[n] + 1; 

		int res; 

		while (l <= r) {
			int mid = (l + r) >> 1;
			int k = mid; 

			bool check = true; 
			for (int i = 1; i <= n; i++) {
				if (a[i] - a[i - 1] > k) {
					check = false;
					break; 	
				}	
				else {
					if (a[i] - a[i - 1] == k) {
						k--; 
					}
				}
			}

			if (check == true) {
				res = mid; 
				r = mid - 1; 
			}
			else {
				l = mid + 1; 
			}
		}

		printf("%d\n", res); 
	}
	return 0; 
}


// Python
T = int(input())
for tc in range(1, T + 1):
    print('Case %d: ' % tc, end = '')
    n = int(input())
    a = [0] + list(map(int, input().split()))
    l = 1
    r = a[-1] + 1
    res = 0
    
    while l <= r:
        mid = (l + r) // 2
        k = mid
        check = True
       
        for i in range(n + 1):
            if a[i] - a[i - 1] > k:
                check = False
                break
            else:
                if a[i] - a[i - 1] == k:
                    k -= 1
        
        if check:
            res = mid
            r = mid - 1
        else:
            l = mid + 1

    print(res)