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
bool ans=true;
int left=0;
    int ht(TreeNode* root){
        if (root==NULL) return 0;
        int left=ht(root->left);
        if(left==-1) return -1;//left -1 means it is not balanced
        
        int right=ht(root->right);
        if(right==-1) return -1;

        int k=abs(left-right);
        if(k>1) return -1;//i.e it means not balanced
        // return k<=1?k:-1;
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return ht(root)==-1?false:true;
    }
};
