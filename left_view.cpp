#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Fixed: Pass 'res' by reference
void view(TreeNode* root, vector<int>& res, int level) {
    if (root == nullptr) return;

    // If this is the first node at this level, add it
    if (res.size() == level) res.push_back(root->val);

    // Right first, then left

    view(root->left, res, level + 1);
    view(root->right, res, level + 1);
}

vector<int> rightView(TreeNode* root) {
    vector<int> res;
    view(root, res, 0);
    return res;
}

// Helper function to print a vector
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// 🚀 Example usage
int main() {
    /*
        Tree Structure:
                1
               / \
              2   3
               \   \
                5   4
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(4);

    vector<int> view = rightView(root);

    cout << "Right view of the binary tree: ";
    printVector(view);

    return 0;
}
