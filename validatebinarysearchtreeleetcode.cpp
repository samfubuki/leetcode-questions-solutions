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
    bool helper(TreeNode* root, long int l, long int r)
   {
    if(root==NULL)
    {
        return true;
    }
    if(root->val<=l || root->val>=r)
    {
        return false;
    }
    bool flag1 = helper(root->left,l,root->val);
    bool flag2 = helper(root->right,root->val,r);
    if(!flag1 || !flag2)
    {
        return false;
    }
    return true;
   }
    bool isValidBST(TreeNode* root) {
      long left = -2147483649; //INT_MIN-1
      long right = 2147483648; //INT_MAX+1
      return helper(root,left,right);
    }
};
