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
bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true;
        else if(p==NULL and q!=NULL) return false;
        else if(q==NULL and p!=NULL) return false;
        else if(p->val!=q->val) return false;
        // else if(p->data==q->data) return true;
        bool left=isSameTree( p->left, q->left);
        bool right=isSameTree(p->right, q->right);
        return left and right;

    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL and subRoot==NULL) return true;
        else if(root==NULL) return false;
        else if(root->val==subRoot->val and isSameTree(root,subRoot)){
            return true ;
        }
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);

        return left or right;
    }
};
