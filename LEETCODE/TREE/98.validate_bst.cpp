/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, long long minVal, long long maxVal) {

        if (root == NULL)
            return true;

        if (root->val <= minVal || root->val >= maxVal)
            return false;

        return dfs(root->left, minVal, root->val) &&
               dfs(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {

        return dfs(root, LLONG_MIN, LLONG_MAX);
    }
};

//ex1:2 ke left walo ka range ab ye hoga ki, ab wo intmin se bade and 2 se chhote honge
//hhar node me syd yeh paas honge .
