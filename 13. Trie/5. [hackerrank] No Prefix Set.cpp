// Problem: No Prefix Set
// Link: https://www.hackerrank.com/challenges/no-prefix-set/problem


#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 'j'-'a'+1 // lowercase letters from a->j (both inclusive).

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
	string firstFailedStr;
	for (int i = 0; i < n; i++) {
		cin >> s;

		if (!failedAddWordOccur) {
			if (!addWord(root, s)) {
				failedAddWordOccur = true;
				firstFailedStr = s;
			}
		}
	}

	if (failedAddWordOccur) {
		cout << "BAD SET" << endl;
		cout << firstFailedStr << endl;
	} else {
		cout << "GOOD SET" << endl;
	}

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
    bool countWord;
};

Node *newNode() {
    Node *node = new Node;
    node->countWord = 0;
    for (int i = 0; i < MAX; i++)
        node->child[i] = NULL;
    return node;
}

bool addWord(Node* root, string s) {
    Node* temp = root;
    for (int i = 0; i < s.length(); i++) {
        int ch = s[i] - 'a';
        if (temp->child[ch] == NULL) {
            temp->child[ch] = newNode();
        }
        temp = temp->child[ch];
        if (temp->countWord > 0) // có 1 từ là tiền tố của từ đang thêm vào trie
            return false; 
    }
    temp->countWord++;
    for (int i = 0; i < MAX; i++) {
        if (temp->child[i] != NULL) // từ vừa thêm vào trie là tiền tố của 1 từ khác
            return false;
    }
    return true;
}

int main() {
    int n;
    string s;
    cin >> n;
    Node* root = newNode();
    bool nonVulnerable = true;
    while (n--){
        cin >> s;
        if (!addWord(root, s)){
            cout << "BAD SET\n";
            cout << s << "\n";
            return 0;
        }
    }
    cout << "GOOD SET";
    return 0;
}

//Py
class Node:
    def __init__(self):
        self.child = dict()
        self.countWord = 0

def addWord(root, s):
    temp = root
    for ch in list(s):
        if ch not in temp.child:
            temp.child[ch] = Node()
        temp = temp.child[ch]
        if temp.countWord > 0:
            return False
    temp.countWord += 1
    return len(temp.child) == 0

n = int(input())
root = Node()
nonVulnerable = True
for i in range(n):
    s = input()
    if not addWord(root, s):
        print('BAD SET')
        print(s)
        exit()
print('GOOD SET')