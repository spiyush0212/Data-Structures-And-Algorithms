#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
 * ============================
 * CUSTOM COMPARATOR WITH SORT
 * ============================
 *
 * Comparator returns true when 'a' should come BEFORE 'b'.
 *
 * a.second > b.second  => descending by second
 * a.second < b.second  => ascending by second
 * a.first  < b.first   => ascending by first
 * a.first  > b.first   => descending by first
 */

void sortExample() {
    vector<pair<int, int>> v = {{1, 50}, {2, 20}, {3, 40}};

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });

    // {1,50}, {3,40}, {2,20}
    for (auto [x, y] : v)
        cout << x << " " << y << '\n';
}


/*
 * =====================================
 * CUSTOM COMPARATOR WITH PRIORITY_QUEUE
 * =====================================
 *
 * Comparator returns true when 'a' has LOWER priority than 'b'.
 *
 * a > b  => min-heap
 * a < b  => max-heap
 *
 * Lambda has an unnamed type, so:
 *
 *     decltype(cmp)
 *
 * gets its type for the priority_queue.
 */

void priorityQueueExample() {
    auto cmp = [](int a, int b) {
        return a > b;
    };

    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);

    pq.push(50);
    pq.push(20);
    pq.push(40);
    pq.push(10);

    // 10 20 40 50
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}


int main() {
    sortExample();
    
    cout << '\n';

    priorityQueueExample();
}