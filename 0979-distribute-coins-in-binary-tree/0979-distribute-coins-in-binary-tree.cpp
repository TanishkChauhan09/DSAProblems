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
    
    int moves=0;

    int totalmoves(TreeNode *root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int Lc = totalmoves(root->left);
        int Rc = totalmoves(root->right);

        moves+=abs(Lc)+abs(Rc);

        return (Lc+Rc+root->val)-1;
    }

    int distributeCoins(TreeNode* root) {
        
        totalmoves(root);

        return moves;
    }
};