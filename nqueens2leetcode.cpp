class Solution {
public:
    int res;
    bool isSafe(vector<vector<int>> &chess, int row, int col)
    {
       for(int i=row-1;i>=0;i--)
       {
           if(chess[i][col]==1)
           {
               return false;
           }

       }
       for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
       {
           if(chess[i][j]==1)
           {
               return false;
           }
       }
       for(int i=row-1,j=col+1;i>=0 && j<=chess.size()-1;i--,j++)
       {
           if(chess[i][j]==1)
           {
               return false;
           }
       }
     return true;
    }
    void getsolutionscount(vector<vector<int>> &chess, int row, int count)
    {
        if(row==chess.size())
        {
            res++;
            return;
        }
        for(int i=0;i<chess.size();i++)
        {
            if(isSafe(chess,row,i)==true)
            {
                chess[row][i]=1;
                getsolutionscount(chess,row+1,count+1);
                chess[row][i]=0;
            }
        }
    }
    int totalNQueens(int n) {
     vector<vector<int>> chess(n,vector<int> (n,0));
     getsolutionscount(chess,0,0);
     return res;
    }
};
