class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int rows = grid.size();
       if(rows==0)
       {
           return 0;
       }
       int cols = grid[0].size();
       vector<vector<int>> dp(rows,vector<int>(cols,0));
       int i,j;
       dp[0][0]=grid[0][0];
       //Filling 1st row
       for(int i=1;i<cols;i++)
       {
           dp[0][i]=dp[0][i-1]+grid[0][i];
       }
       //Filling 1st col
       for(int i=1;i<rows;i++)
       {
           dp[i][0]=dp[i-1][0]+grid[i][0];
       }
       for(int i=1;i<rows;i++)
       {
           for(int j=1;j<cols;j++)
           {
               dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
           }
       }
       return dp[rows-1][cols-1];
    }
};
