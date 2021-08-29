class Solution {
public:
    bool isMatch(string str, string pattern) {
       int n = pattern.length();
       int w = str.length();
       int t[n+1][w+1];
    for(int i=n;i>=0;i--)
    {
        for(int j=w;j>=0;j--)
        {
            if(i==n && j==w)
            {
                t[i][j]=1;
            }
            else if(j==w)
            {
                if(pattern[i]=='*')
                {
                    t[i][j]=t[i+1][j];
                }
                else
                {
                    t[i][j]=0;
                }
            }
            else
            {
                if(pattern[i]=='?')
                {
                    t[i][j]=t[i+1][j+1];
                }
                else if(pattern[i]=='*')
                {
                    t[i][j] = t[i+1][j] || t[i][j+1];
                }
                else if(pattern[i]==str[j])
                {
                    t[i][j]=t[i+1][j+1];
                }
                else
                {
                    t[i][j]=0;
                }
            }

        }
    }
 return t[0][0];
    }
};
