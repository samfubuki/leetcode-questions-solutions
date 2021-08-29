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
    void generatebst(vector<TreeNode *> &res, int left, int right)
    {
        if(left>right)
        {
            res.push_back(NULL);
            return;
        }
       for(int i=left;i<=right;i++)
       {
           vector<TreeNode *> lefts;
           generatebst(lefts,left,i-1);
           vector<TreeNode *> rights;
           generatebst(rights,i+1,right);
           for(int m=0;m<lefts.size();m++)
           {
               for(int n=0;n<rights.size();n++)
               {
                   TreeNode *root = new TreeNode(i);
                   root->left = lefts[m];
                   root->right = rights[n];
                   res.push_back(root);
               }
           }
       }
    }
    vector<TreeNode*> generateTrees(int n) {
      vector<TreeNode *> res;
      generatebst(res,1,n);
      return res;
    }
};
