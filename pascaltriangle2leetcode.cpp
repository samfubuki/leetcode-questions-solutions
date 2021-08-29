class Solution {
public:
    vector<int> getRow(int rowIndex) {
       int numrows = rowIndex+1;
       vector<vector<int>> r(numrows);
       for(int i=0;i<numrows;i++)
       {
           r[i].resize(i+1);
           r[i][0]=1;
           r[i][i]=1;
           for(int j=1;j<i;j++)
           {
               r[i][j]=r[i-1][j-1]+r[i-1][j];
           }
       }
      return r[rowIndex];
    }
};
