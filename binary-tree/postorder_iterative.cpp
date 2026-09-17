#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// POSTORDER: Left -> Right -> Root
// Keep the node on the stack until its right subtree is done.
// lastVisited tells us whether the right subtree was already processed.
// Time: O(N) | Space: O(H)

void postorder(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> stk;
    TreeNode* cur = root;
    TreeNode* lastVisited = nullptr;

    while (cur || !stk.empty()) {

        // Keep going left before processing the node.
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }

        TreeNode* node = stk.top();

        // Right subtree still needs to be processed.
        if (node->right && lastVisited != node->right) {
            cur = node->right;
        }
        else {
            // Both subtrees are done, so process root.
            cout << node->val << " ";

            lastVisited = node;
            stk.pop();
        }
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

    postorder(root);
    cout << '\n';

    return 0;
}