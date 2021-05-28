// Problem: 1129 - Consistency Checker
// Link: http://lightoj.com/volume_showproblem.php?problem=1129


#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX 10

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
        ch = s[i] - '0';
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

    int t;
    cin >> t;

    int n;
    string s;
    for (int c = 1; c <= t; c++) {
        cin >> n;

        Node* root = new Node();
        bool failedAddWordOccur = false;
        for (int i = 0; i < n; i++) {
            cin >> s;

            if (!failedAddWordOccur) {
                if (addWord(root, s) == false)
                    failedAddWordOccur = true;
            }
        }

        cout << "Case " << c << ": " << (failedAddWordOccur ? "NO" : "YES") << endl;

        destroyTrie(root);
    }

    return 0;
}

// St
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 10;

struct Node {
   Node* child[MAX];
   bool end_word;
};

Node *newNode() {
   Node *new_node = new Node;
   new_node->end_word = false;
   for (int i = 0; i < MAX; i++) {
      new_node->child[i] = nullptr;
   }
   return new_node;
}

bool addWord(Node* root, const string& s) {
   Node* temp = root;
   bool s_prefix_other = false;
   bool other_prefix_s = true;

   for (int i = 0; i < s.size(); i++) {
      int ch = s[i] - '0';

      if (temp->child[ch] == nullptr) {
         temp->child[ch] = newNode();
         other_prefix_s = false;
      }

      temp = temp->child[ch];
      if (temp->end_word) {
         s_prefix_other = true;
      }
   }

   temp->end_word = true;
   return (s_prefix_other || other_prefix_s);
}
      
int main() {
   int t, n, tc;
   string s;
   cin >> t;

   for (tc = 1; tc <= t; tc++) {
      cin >> n;
      Node* root = newNode();
      bool is_inconsistent = false;

      for (int i = 0; i < n; i++) {
         cin >> s;
         if (!is_inconsistent) {
            is_inconsistent = addWord(root, s);
         }
      }

      cout << "Case " << tc << ": " << (is_inconsistent ? "NO" : "YES") << endl;
   }
   return 0;
}


// Py
class Node:
   def __init__(self):
      self.end_word = False
      self.child = dict()

def addWord(root, s):
   temp = root
   s_prefix_other = False
   other_prefix_s = True
   
   for ch in s:
      if ch not in temp.child:
         temp.child[ch] = Node()
         other_prefix_s = False
      
      temp = temp.child[ch]
      if temp.end_word:
         s_prefix_other = True
   
   temp.end_word = True
   return s_prefix_other or other_prefix_s

t = int(input())
for tc in range(t):
   n = int(input())
   root = Node()
   is_inconsistent = False

   for _ in range(n):
      if not is_inconsistent:
         is_inconsistent = addWord(root, input())
      else:
         input()

   print('Case {}: {}'.format(tc + 1, 'NO' if is_inconsistent else 'YES'))