/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* target=NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return target= NULL;
        if(p==root or q==root)return target=root;
        //mtlv dno me se ye ek mil gya , to dusra left ya right me hoga , pas lca to yhi hoga
        if((p->val<root->val and q->val>root->val)or (p->val>root->val and q->val<root->val))return target=root;
        if(p->val<root->val and q->val<root->val) lowestCommonAncestor(root->left,p,q);
        else if(p>root and q>root) lowestCommonAncestor(root->right,p,q);
        return target;
    }
};
