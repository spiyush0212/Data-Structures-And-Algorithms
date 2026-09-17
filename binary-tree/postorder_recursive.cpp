#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// POSTORDER: Left -> Right -> Root
// Recursively process both children before processing the current node.
// Time: O(N) | Space: O(H)

void postorder(TreeNode* root) {
    if (!root)
        return;

    postorder(root->left);
    postorder(root->right);

    // Root is processed after both children.
    cout << root->val << " ";
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