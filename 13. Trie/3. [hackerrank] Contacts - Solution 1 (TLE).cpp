// Problem: Contacts
// Link: https://www.hackerrank.com/challenges/contacts/problem


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

void addWord(Node* root, const string& s) {
	int ch;
	Node* temp = root;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL)
			temp->child[ch] = new Node();
		temp = temp->child[ch];
	}
	temp->countWord++;
}

Node* findNodeStartWith(Node* root, const string& s) {
	Node* temp = root;

	int ch;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i] - 'a';
		if (temp->child[ch] != NULL)
			temp = temp->child[ch];
		else
			return NULL;
	}

	return temp;
}

int countWords(Node* root) {
	if (root == NULL)
		return 0;

	int res = 0;
	for (int i = 0; i < MAX; i++) {
		if (root->child[i] != NULL)
			res += countWords(root->child[i]);
	}

	if (isWord(root))
		res += 1;

	return res;
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
	string s, opt;
	cin >> n;

	Node* root = new Node();
	for (int i = 0; i < n; i++) {
		cin >> opt >> s;
		if (opt == "add")
			addWord(root, s);
		else if (opt == "find") {
			Node* startWithNode = findNodeStartWith(root, s);
			if (startWithNode == NULL)
				cout << 0 << endl;
			else 
				cout << countWords(root) << endl;
		}
	}
	destroyTrie(root);

	return 0;
}
// Python
class TrieNode:
    def __init__(self, c):
        self.count = c
        self.child = dict()
        self.child.clear()

def addContact(root, s):
    for c in list(s):
        if c in root.child:
            root = root.child[c]
        else:
            root.child[c] = TrieNode(0)
            root = root.child[c]
        root.count += 1
        

def countContacts(root, s):
    
    for c in list(s):
        if c in root.child:
            root = root.child[c]
        else:
        	return 0
    return root.count

n = int(input())
root = TrieNode(0)
while (n > 0):
    n -= 1
    opt, arg = input().split()
    
    if opt[0] == 'a':
        addContact(root, arg)
    else:
        print(countContacts(root, arg))

//St
#include <iostream>
#include <string>
#define K 26
using namespace std;
typedef struct Node* ref;
struct Node {
	ref child[K];
	int count;
	Node() {
		for (int i = 0; i < K; i++)
			child[i] = NULL;
		count = 0;
	}
}* root;
void addContact(string& s) {
	ref p = root;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i] - 'a';
		if (!p->child[c])
			p->child[c] = new Node;
		p = p->child[c];
		p->count++;
	}
}
int countContacts(string& s) {
	ref p = root;
	for (int i = 0; i < s.length(); i++) {
		int c = s[i] - 'a';
		if (!p->child[c])
			return 0;
		p = p->child[c];
	}
	return p->count;
}
int main() {
	int n;
	cin >> n;
	root = new Node;
	while (n--) {
		string opt, arg;
		cin >> opt >> arg;
		if (opt[0] == 'a')
			addContact(arg);
		else
			cout << countContacts(arg) << endl;
	}
	delete root;
}