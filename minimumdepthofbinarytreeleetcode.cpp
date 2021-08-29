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
    void helper(TreeNode *root, int &finalans, int cnt)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            finalans = min(finalans,cnt+1);
            return;
        }
        if(root->left!=NULL)
        {
            helper(root->left,finalans,cnt+1);
        }
        if(root->right!=NULL)
        {
            helper(root->right,finalans,cnt+1);

        }
      return;
    }
    int minDepth(TreeNode* root) {
       if(root==NULL)
       {
           return 0;
       }
       int finalans = INT_MAX;
       int cnt=0;
       helper(root,finalans,cnt);
       return finalans;
    }
};
