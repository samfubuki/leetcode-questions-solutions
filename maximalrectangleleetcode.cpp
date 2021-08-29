class Solution {
public:
    vector<int> nsl(vector<int> v)
    {
        vector<int> ans;
        stack<pair<int,int>>st;
        for(int i=0;i<v.size();i++)
        {
            if(st.size()==0)
            {
                ans.push_back(-1);
            }
            else if(st.top().first>=v[i])
            {
                while(st.size()!=0 && st.top().first>=v[i])
                {
                    st.pop();
                }
               if(st.size()==0)
               {
                   ans.push_back(-1);
               }
               else
               {
                   ans.push_back(st.top().second);

               }

            }
            else
            {
                ans.push_back(st.top().second);
            }
          st.push({v[i],i});

        }
      return ans;
    }
    vector<int> nsr(vector<int> v)
    {
        vector<int> ans;
        stack<pair<int,int>> st;
        for(int i=v.size()-1;i>=0;i--)
        {
            if(st.size()==0)
            {
                ans.push_back(v.size());
            }
            else if(st.top().first>=v[i])
            {
                while(st.size()!=0 && st.top().first>=v[i])
                {
                    st.pop();
                }
                if(st.size()==0)
                {
                    ans.push_back(v.size());
                }
                else
                {
                    ans.push_back(st.top().second);
                }

            }
            else
            {
                ans.push_back(st.top().second);
            }
          st.push({v[i],i});
        }
       reverse(ans.begin(),ans.end());
       return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       if(matrix.size()==0)
       {
           return 0;
       }
       int n = matrix.size();
       int m = matrix[0].size();
       int ans=0;
       vector<int> v(m),left,right;
       for(int i=0;i<n;i++)
       {
           if(i==0)
           {
               for(int j=0;j<m;j++)
               {
                   if(matrix[i][j]=='1')
                   {
                       v[j]=1;
                   }

               }
             left = nsl(v);
             right = nsr(v);
             for(int k=0;k<m;k++)
             {
                 ans = max(ans,(right[k]-left[k]-1)*v[k]);
             }
           }
             else
             {
                 for(int j=0;j<m;j++)
                 {
                     if(matrix[i][j]=='0')
                     {
                         v[j]=0;
                     }
                     else
                     {
                         v[j]=v[j]+1;
                     }
                 }
             }
             left = nsl(v);
             right = nsr(v);
             for(int k=0;k<m;k++)
             {
                 ans = max(ans,(right[k]-left[k]-1)*v[k]);
             }
           }
      return ans;
    }
};
