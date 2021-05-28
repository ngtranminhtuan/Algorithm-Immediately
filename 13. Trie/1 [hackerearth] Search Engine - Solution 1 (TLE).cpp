// Problem: Search Engine
// Link: https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/?fbclid=IwAR0h_gLNfeHAz4w1c9KRRoAU6OFfln-p-urZCilCsK_vvUqF1ZGhVw4Q5vM


#include <iostream>
#include <string>
using namespace std;

#define MAX 26

struct Node {
    Node* child[MAX];
    int countWord;
    int priority;

    Node() {
        countWord = 0;
        priority = -1;
        for (int i = 0; i < MAX; i++)
            child[i] = NULL;
    }
};

void addWord(Node* root, const string& s, int priority) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            temp->child[ch] = new Node();
        temp = temp->child[ch];
    }
    temp->countWord = 1; // 1 word only
    temp->priority = priority;
}

bool isWord(Node* root) {
    return root != NULL && root->countWord > 0;
}

Node* maxPriorityWord = NULL;
void findMaxPriorityWordChild(Node* root) {
    if (root == NULL)
        return;

    if (isWord(root) && (maxPriorityWord == NULL || root->priority > maxPriorityWord->priority)) {
        maxPriorityWord = root;
        return;
    }

    for (int i = 0; i < MAX; i++) {
        if (root->child[i] != NULL)
            findMaxPriorityWordChild(root->child[i]);
    }
}

Node* findMaxPriorityWord(Node* root, const string& s) {
    int ch;
    Node* temp = root;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i] - 'a';
        if (temp->child[ch] == NULL)
            return NULL; // not found
        temp = temp->child[ch];
    }

    maxPriorityWord = NULL;
    findMaxPriorityWordChild(temp);
    return maxPriorityWord;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    Node* root = new Node();
    string s;
    int priority;
    for (int i = 0; i < n; i++) {
        cin >> s >> priority;
        addWord(root, s, priority);
    }

    for (int i = 0; i < q; i++) {
        cin >> s;
        Node* res = findMaxPriorityWord(root, s);
        if (res == NULL)
            cout << -1 << endl;
        else
            cout << res->priority << endl;
    }

    return 0;
}

//St
#include <bits/stdc++.h>
#define ALPHABET_SIZE 26
using namespace std;

struct Node {
    struct Node *child[ALPHABET_SIZE];
    int maxValue;
};

struct Node *newNode() {
    struct Node *pNode = new struct Node;
    pNode->maxValue = -1;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->child[i] = nullptr;
    }
    
    return pNode;
}

void addWord(struct Node *root, string s, int value) {
    struct Node *tmp = root;
    
    for (char &c : s) {
        int pos = c - 'a';
        if (!tmp->child[pos]) {
            tmp->child[pos] = newNode();
        }
        
        tmp = tmp->child[pos];
        tmp->maxValue = max(tmp->maxValue, value);
    }
}

int getHighestMatching(struct Node *root, string s) {
    struct Node *tmp = root;

    for (char &c : s) {
        int pos = c - 'a';
        if (!tmp->child[pos]) {
            return -1;
        }
        tmp = tmp->child[pos];
    }
    
    return tmp->maxValue;
}

int main() {
    int n, q, value;
    string s;
    cin >> n >> q;
    struct Node *root = newNode();

    for (int i = 0; i < n; i++) {
        cin >> s >> value;
        addWord(root, s, value);
    }

    for (int i = 0; i < q; i++) {
        cin >> s;
        cout << getHighestMatching(root, s) << endl;
    }

    return 0;
}


//Py
class Node:
    def __init__(self):
        self.child = dict()
        self.maxValue = -1

def addWord(root, s, value):
    tmp = root
    for c in s:
        if c not in tmp.child:
            tmp.child[c] = Node()
        tmp = tmp.child[c]
        tmp.maxValue = max(tmp.maxValue, value)

def getHeighestMatching(root, s):
    tmp = root
    for c in s:
        if c not in tmp.child:
            return -1
        tmp = tmp.child[c]
    return tmp.maxValue

n, q = map(int, input().strip().split())
root = Node()

for _ in range(n):
    line = input().strip().split()
    addWord(root, line[0], int(line[1]))

for _ in range(q):
    s = input().strip()
    print(getHeighestMatching(root, s))