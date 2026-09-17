#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// BFS LEVEL ORDER
// Process exactly `levelSize` nodes at each iteration.
// Time: O(N) | Space: O(W)

vector<vector<int>> bfs(TreeNode* root) {
    vector<vector<int>> result;

    if (!root)
        return result;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        vector<int> level;

        // Process only nodes belonging to the current level.
        for (int i = 0; i < levelSize; i++) {
            TreeNode* cur = q.front();
            q.pop();

            level.push_back(cur->val);

            // Add children for the next level.
            if (cur->left)
                q.push(cur->left);

            if (cur->right)
                q.push(cur->right);
        }

        result.push_back(level);
    }

    return result;
}

int main() {
    //        1
    //       / \
    //      2   3
    //     / \   \
    //    4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    vector<vector<int>> result = bfs(root);

    for (const auto& level : result) {
        for (int val : level)
            cout << val << " ";

        cout << '\n';
    }

    return 0;
}