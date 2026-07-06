// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         //will use bfs
//         int level=0;
//         if(root==NULL) return 0;
        
//         queue<TreeNode*>q;
//         q.push(root);

//         while(q.size()){
//            int size=q.size();
//            while(size--){
//             TreeNode* front=q.front();
//             q.pop();
//             if(front->left!=NULL) q.push(front->left);
//             if(front->right!=NULL) q.push(front->right);
//            }
//            level+=1;
            
//         }
//       return level;
//     }  
// };

//dfs code 
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
