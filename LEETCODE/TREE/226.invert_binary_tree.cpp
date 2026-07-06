/**z
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
    TreeNode* invertTree(TreeNode* root) {
          TreeNode* lefty=NULL;
          TreeNode* righty=NULL;
          if(root ==NULL) return NULL;
          if(root->left==NULL and root->right==NULL)return root;
          invertTree(root->left);
          invertTree(root->right);
          lefty=root->left;
          righty=root->right;
          root->left=righty;
          root->right=lefty;

          return root;
    }
};
