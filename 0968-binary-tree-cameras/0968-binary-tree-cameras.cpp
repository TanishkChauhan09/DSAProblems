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
    
    int camera=0;
    
    int mincamera(TreeNode *root)
    {
        if(!root) return 1;

        int Lchild = mincamera(root->left);
        int Rchild = mincamera(root->right);

        if(Lchild==-1 || Rchild==-1)
        {
            camera++;
            return 0;
        }

        if(Lchild==0 || Rchild==0)
        return 1;

        return -1;
    }

    int minCameraCover(TreeNode* root) {
        
        if(mincamera(root)==-1)
        camera++;

        return camera;
    }
};