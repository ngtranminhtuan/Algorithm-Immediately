// Problem: Roy and Trending Topics
// Link: https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1/description/


#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Record {
    long long id;
    long long change;
    long long newScore;
};

struct greaterComparator {
    bool operator() (const Record& r1, const Record& r2) const {
    if (r1.change != r2.change)
        return r1.change > r2.change;
    else
        return r1.id > r2.id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
	cin >> n;
    priority_queue<Record, vector<Record>, greaterComparator> minHeap;
    long long topicId, currentScore, posts, likes, comments, shares;
    long long newScore, change;
    for (int i = 0; i < n; i++) {
        cin >> topicId >> currentScore >> posts >> likes >> comments >> shares;
        newScore = posts * 50 + likes * 5 + comments * 10 + shares * 20;
        change = newScore - currentScore;

        if (minHeap.size() < 5) {
            minHeap.push((Record) {topicId, change, newScore});
        }
        // if we found a greater record, remove current min record, push new one to our minHeap
        else if ((minHeap.top().change < change) || (minHeap.top().change == change && minHeap.top().id < topicId)) {
            minHeap.pop();
            minHeap.push((Record) {topicId, change, newScore});
        }
    }

    // convert heap to vector for sorting
    vector<Record> records;
    while (!minHeap.empty()) {
        records.push_back(minHeap.top());
        minHeap.pop();
    }

    // Sort in decreasing by change, id
    sort(records.begin(), records.end(), greaterComparator());

    // print results
    for (int i = 0; i < records.size(); i++) {
        cout << records[i].id << " " << records[i].newScore << endl;
    }

    return 0;
}


// Standard Code
#include <iostream>
#include <queue>
using namespace std;

struct Topic {
    int id;
    long long old_score, new_score, change;

    Topic(int _id, long long _old_score, long long _new_score) {
        id = _id;
        old_score = _old_score;
        new_score = _new_score;
        change = new_score - old_score;
    }

    bool operator<(const Topic &other) const {
        return change < other.change || (change == other.change && id < other.id);
    }
};

int main() {
    int n;
    cin >> n;
    int id;
    long long old_score, new_score, post, like, comment, share;
    priority_queue<Topic> pq;

    while (n--) {
        cin >> id >> old_score >> post >> like >> comment >> share;
        new_score = post * 50 + like * 5 + comment * 10 + share * 20;
        pq.push(Topic(id, old_score, new_score));
    }

    for (int i = 0; i < 5; i++) {
        Topic t = pq.top();
        pq.pop();
        cout << t.id << " " << t.new_score << endl;
    }
    return 0;
}

// ----------
import queue

class Topic:
    def __init__(self, _id, _old_score, _new_score):
        self.id = _id
        self.old_score = _old_score
        self.new_score = _new_score
        self.change = self.new_score - self.old_score
    
    def __lt__(self, other):
        return self.change > other.change or (self.change == other.change and self.id > other.id)

n = int(input())
pq = queue.PriorityQueue()

for _ in range(n):
    id, old_score, post, like, comment, share = map(int, input().split())
    new_score = post * 50 + like * 5 + comment * 10 + share * 20
    pq.put(Topic(id, old_score, new_score))

for i in range(5):
    t = pq.get()
    print(t.id, t.new_score)