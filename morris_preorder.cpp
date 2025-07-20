vector<int> MorrisInorder(TreeNode* root) {
    vector<int> inorder;
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            inorder.push_back(curr->val);  // No left, visit and move right
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;

            // Find the rightmost node in left subtree (inorder predecessor)
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr;  // Create thread
                inorder.push_back(curr->val);
                curr = curr->left;
            } else {
                prev->right = nullptr;  // Remove thread
                curr = curr->right;
            }
        }
    }

    return inorder;
}
