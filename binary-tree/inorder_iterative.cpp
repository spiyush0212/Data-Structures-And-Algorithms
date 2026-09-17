#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// INORDER: Left -> Root -> Right
// Keep pushing left nodes until reaching the leftmost node.
// Pop/process the node, then move to its right subtree.
// Time: O(N) | Space: O(H)

void inorder(TreeNode* root) {
    stack<TreeNode*> stk;
    TreeNode* cur = root;

    while (cur || !stk.empty()) {

        // Delay processing and keep going left.
        while (cur) {
            stk.push(cur);
            cur = cur->left;
        }

        // Left subtree is done, so process the root.
        cur = stk.top();
        stk.pop();

        cout << cur->val << " ";

        // Now explore the right subtree.
        cur = cur->right;
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

    inorder(root);
    cout << '\n';

    return 0;
}