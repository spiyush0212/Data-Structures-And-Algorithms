#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) : val(x), next(nullptr) {}
};

// Floyd's Cycle Detection
// TIME:  O(N)
// SPACE: O(1)

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* turtle = head;
        ListNode* rabbit = head;

        while (rabbit && rabbit->next) {
            turtle = turtle->next;
            rabbit = rabbit->next->next;

            // If both pointers meet, a cycle exists.
            if (turtle == rabbit)
                return true;
        }

        // Fast pointer reached nullptr, so no cycle exists.
        return false;
    }
};

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    // Create a cycle: 4 -> 2
    head->next->next->next->next = head->next;

    Solution solution;

    cout << boolalpha << solution.hasCycle(head) << endl;

    return 0;
}