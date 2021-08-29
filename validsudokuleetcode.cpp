class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char c)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col]==c)
            {
                return false;
            }
            if(board[row][i]==c)
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
            {
                return false;
            }
        }
      return true;
    }
    bool solve(vector<vector<char>>& board)
    {
       int n=9;
       int m=9;
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           {
               if(board[i][j]!='.')
               {
                   int c = board[i][j];
                   board[i][j]='$';
                   if(isSafe(board,i,j,c)==false)
                   {
                       return false;
                   }
                   board[i][j]=c;
               }
           }
       }
      return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag = solve(board);
        return flag;
    }


};
