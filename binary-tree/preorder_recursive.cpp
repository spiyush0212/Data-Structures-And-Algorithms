#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// PREORDER: Root -> Left -> Right
// Process the node first, then recursively visit the left and right subtrees.
// Time: O(N) | Space: O(H)

void preorder(TreeNode* root) {
    if (!root)
        return;

    // Process root before its children.
    cout << root->val << " ";

    preorder(root->left);
    preorder(root->right);
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