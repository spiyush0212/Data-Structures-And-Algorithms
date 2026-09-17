#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// PREORDER: Root -> Left -> Right
// Process node when popped. Push right before left so that left is popped and processed first.
// Time: O(N) | Space: O(H)

void preorder(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* cur = stk.top();
        stk.pop();

        // Process root before its children.
        cout << cur->val << " ";

        // Stack is LIFO, so push right first.
        if (cur->right)
            stk.push(cur->right);

        if (cur->left)
            stk.push(cur->left);
    }
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    preorder(root);
    cout << '\n';

    return 0;
}