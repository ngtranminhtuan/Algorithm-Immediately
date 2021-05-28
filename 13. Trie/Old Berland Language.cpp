//St
#include <iostream>
#include <bits/stdc++.h>
#define maxn 1000001
#define MAX 2
using namespace std;
struct node
{
    struct node *child[MAX];
    int isblock;
    struct node *pre;
};
struct node *newNode()
{
    struct node *Node = new struct node;
    Node->isblock = 0;
    Node->pre = NULL;
    for (int i = 0; i < MAX; i++)
    {
        Node->child[i] = NULL;
    }
    return Node;
}
string ans[10001],s;
node *root = newNode();
bool add(int l){
    node *tmp = root;
    if (root->isblock == 1) return false;
    s = "";
    for (int i = 0; i < l; i++){
        int check_1 = -1;
        bool canmove = false;
        for (int j = MAX-1; j >= 0; j--){
            if (tmp->child[j] != NULL) {
                    if (tmp->child[j]->isblock == 0) {
                        s = s + (char)('0' + j);
                        tmp = tmp->child[j];
                        canmove = true;
                        break;
                    }
            }
            if (tmp->child[j] == NULL)
                check_1 = j;
        }
        if (!canmove){
            if (check_1 == -1){
                return false;
            }
			else
			{
			s = s + char('0' + check_1);

			tmp->child[check_1] = newNode();
			tmp->child[check_1]->pre = tmp;
			tmp = tmp->child[check_1];
			}
        }
    }
    tmp->isblock = 1;
    while (tmp != NULL){
        if (tmp->child[0] != NULL && tmp->child[1] != NULL)
        if (tmp->child[0]->isblock * tmp->child[1]->isblock == 1)
            tmp->isblock = 1;
        tmp = tmp->pre;
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    pair<int, int> a[10000];
    for (int i = 0; i < n ; i++){
           int l;
           cin >> l;
           a[i] = {l,i};
    }
    sort(a, a + n);
    for (int i = 0; i < n ; i++){
        int l = a[i].first;
        if (add(l)== false) {
                cout << "NO";
                return 0;
        } else
        {
            ans[a[i].second] = s;
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << '\n';
    return 0;
}

//Py
import sys
sys.setrecursionlimit(1000000)

class Node:
    def __init__(self, val):
        self.child = dict()
        self.is_blocked = False
        self.val = val

class Trie:
    def __init__(self):
        self.root = Node('')
    
    def add(self, length, id, res):
        st = [self.root]
        while length and len(st):
            u = st[-1]
            length -= 1
            if 0 not in u.child:
                u.child[0] = Node('0')
            if not u.child[0].is_blocked:
                st.append(u.child[0])
            else:
                if 1 not in u.child:
                    u.child[1] = Node('1')
                if not u.child[1].is_blocked:
                    st.append(u.child[1])
                else:
                    u.is_blocked = True
                    length += 2
                    st.pop()
        if length == 0:
            st[-1].is_blocked = True
            res[id] = ''.join(node.val for node in st)
            return True
        return False
        
if __name__ == "__main__":
    n = int(input())
    a = list(map(int, input().split()))
    a = sorted([(a[i], i) for i in range(n)])

    trie = Trie()
    res = [None] * n
    for length, i in a:
        if not trie.add(length, i, res):
            print('NO')
            exit()

    print('YES')
    for length in res:
        print(length)