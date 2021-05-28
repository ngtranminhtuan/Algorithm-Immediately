// Problem: Bank and vulnerable passwords
// Link: https://www.codechef.com/DMNT2015/problems/BANKPASS


#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 26

struct Node {
    Node* child[MAX];
    int countWord;

    Node() {
        countWord = 0;
        for (int i = 0; i < MAX; i++)
            child[i] = NULL;
    }
};

bool isWord(Node* root) {
    return root != NULL && root->countWord > 0;
}

// Return false if add failed, else return true
bool addWord(Node* root, const string& s) {
    int ch;
    Node* temp = root;
    bool hasNewChild = false;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = new Node();
            hasNewChild = true;
        }
        temp = temp->child[ch];

        if (!hasNewChild && isWord(temp)) { // $temp word is a prefix of $s word
			return false;
		}
    }
    temp->countWord++;
    return hasNewChild; // if hasNewChild == false -> mean $s word is prefix of another word
}

void destroyTrie(Node* root) {
    if (root == NULL)
        return;

    for (int i = 0; i < MAX; i++) {
        destroyTrie(root->child[i]);
    }
    delete root;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n;

    Node* root = new Node();
    bool failedAddWordOccur = false;
    for (int i = 0; i < n; i++) {
        cin >> s;

        if (!failedAddWordOccur) {
            if (addWord(root, s) == false) {
                failedAddWordOccur = true;
            }
        }
    }

    cout << (failedAddWordOccur ? "vulnerable" : "non vulnerable") << endl;

    destroyTrie(root);

    return 0;
}

//St
#include <iostream>
#include <string>
using namespace std;
#define MAX 26

struct Node {
    Node* child[MAX];
    bool isLeaf;
};

Node *newNode() {
    Node *node = new Node;
    node->isLeaf = false;
    for (int i = 0; i < MAX; i++)
        node->child[i] = NULL;
    return node;
}

bool addWord(Node* root, string s) {
    Node* temp = root;
    bool flag = false;
    for (int i = 0; i < s.length(); i++) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            flag = true;
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        if (temp->isLeaf)
            return false;
    }
    temp->isLeaf = true;
    return flag;
}

int main() {
    int n;
    string s;
    cin >> n;
    Node* root = newNode();
    bool nonVulnerable = true;
    while (n--) {
        cin >> s;
        nonVulnerable &= addWord(root, s);
    }
    if (nonVulnerable)
        cout << "non vulnerable";
    else
        cout << "vulnerable";
    return 0;
}

//Py
class Node:
    def __init__(self):
        self.child = dict()
        self.isLeaf = False

def addWord(root, s):
    flag = False
    temp = root
    for ch in list(s):
        if ch not in temp.child:
            flag = True
            temp.child[ch] = Node()
        temp = temp.child[ch]
        if temp.isLeaf:
            return False
    temp.isLeaf = True
    return flag

n = int(input())
root = Node()
nonVulnerable = True
for i in range(n):
    s = input()
    nonVulnerable &= addWord(root, s)
print(("non " if nonVulnerable else "") + "vulnerable")