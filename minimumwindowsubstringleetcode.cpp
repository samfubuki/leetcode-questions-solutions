class Solution {
public:
    string minWindow(string s, string t) {
      unordered_map<int,int> mp;
      int ans = INT_MAX;
      int start;
      for(int i=0;i<t.length();i++)
      {
          mp[t[i]]++;
      }
      int dmct = mp.size();
      int i=0;
      int j=0;
      while(j<s.length())
      {
          mp[s[j]]--;
          if(mp[s[j]]==0)
          {
              dmct--;
          }
          if(dmct==0)
          {
              while(dmct==0)
              {
                  if(ans>j-i+1)
                  {
                      ans = min(ans,j-i+1);
                      start=i;
                  }
                  mp[s[i]]++;
                  if(mp[s[i]]>0)
                  {
                      dmct++;
                  }
                  i++;
              }
          }
          j++;
      }
       if(ans!=INT_MAX)
       {
           return s.substr(start,ans);
       }
    return "";
      }
};
