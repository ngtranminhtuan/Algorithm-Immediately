#include <bits/stdc++.h> 

using namespace std; 
const int MAX_N = 100005; 

int n, m; 
int root[MAX_N];
int cnt[MAX_N];  
int maxi = 0; 
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq; 

int findRoot(int u) {
	if (u == root[u]) {
		return u; 
	}

	return root[u] = findRoot(root[u]); 
}

void unionSet(int u, int v) {
	int uu = findRoot(u); 
	int vv = findRoot(v); 

	if (uu != vv) {
		cnt[uu] += cnt[vv];
		root[vv] = uu;
		pq.push(make_pair(cnt[uu], uu));  
		maxi = max(maxi, cnt[uu]); 
	}
}

int main () {
	//freopen("input.txt", "r", stdin); 
	//freopen("output.txt", "w", stdout); 

	scanf("%d %d", &n, &m); 
	for (int i = 1; i <= n; i++) {
		cnt[i] = 1; 
		root[i] = i; 
		pq.push(make_pair(1, i)); 
	}
	
	maxi = 1; 

	for (int i = 1; i <= m; i++) {
		int u, v; 
		scanf("%d %d", &u, &v); 
		unionSet(u, v);
		while (true) {
			pair <int, int> tmp = pq.top(); 
			int r = findRoot(tmp.second); 
			if (r != tmp.second) {
				pq.pop();
				continue; 
			}

			if (cnt[r] != tmp.first) {
				pq.pop();
				continue; 
			}

			break; 
		}

		printf("%d\n", maxi - pq.top().first); 
	}

	return 0; 
}

//Python
from queue import PriorityQueue

MAX_N = 100005

root = [0] * MAX_N
cnt = [0] * MAX_N
maxi = 1
pq = PriorityQueue()

def findRoot(u):
    if u == root[u]:
        return u
    root[u] = findRoot(root[u])

    return root[u]

def unionSet(u, v):
    global maxi

    uu = findRoot(u)
    vv = findRoot(v)

    if uu != vv:
        cnt[uu] += cnt[vv]
        root[vv] = uu
        pq.put((cnt[uu], uu))
        maxi = max(maxi, cnt[uu])

def main():
    n, m = map(int, input().split())

    for i in range(1, n + 1):
        cnt[i] = 1
        root[i] = i
        pq.put((1, i))

    for i in range(m):
        u, v = map(int, input().split())
        unionSet(u, v)
        while True:
            tmp = pq.queue[0]
            r = findRoot(tmp[1])
            if r != tmp[1]:
                pq.get()
                continue

            if cnt[r] != tmp[0]:
                pq.get()
                continue

            break

        print(maxi - pq.queue[0][0])

if __name__ == "__main__":
    main()