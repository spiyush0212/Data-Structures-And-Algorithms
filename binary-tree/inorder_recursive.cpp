#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// INORDER: Left -> Root -> Right
// Recursively visit the left subtree, process the root, then recursively visit the right subtree.
// Time: O(N) | Space: O(H)

void inorder(TreeNode* root) {
    if (!root)
        return;

    // Root is processed between left and right.
    inorder(root->left);

    cout << root->val << " ";

    inorder(root->right);
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