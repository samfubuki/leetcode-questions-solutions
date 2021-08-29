class Solution {
public:
    vector<int> helper(vector<vector<int>>& matrix, int r, int c)
    {
        int top=0;
     int down = r-1;
     int left=0;
     int right = c-1;
     int dir=0;
     vector<int> ans;
     while(top<=down && left<=right)
     {
         if(dir==0)
         {
           for(int i=left;i<=right;i++)
           {
               ans.push_back(matrix[top][i]);
           }
          top=top+1;
         }
         else if(dir==1)
         {
             for(int i=top;i<=down;i++)
             {
                 ans.push_back(matrix[i][right]);
             }
        right=right-1;
         }
         else if(dir==2)
         {
             for(int i=right;i>=left;i--)
             {
                 ans.push_back(matrix[down][i]);
             }
          down=down-1;
         }
         else if(dir==3)
         {
             for(int i=down;i>=top;i--)
             {
                 ans.push_back(matrix[i][left]);
             }
          left=left+1;
         }
         dir = (dir+1)%4;
     }
     return ans;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       int r = matrix.size();
       int c = matrix[0].size();
       vector<int> result = helper(matrix,r,c);
       return result;
    }
};
