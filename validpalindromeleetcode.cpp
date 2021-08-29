class Solution {
public:
    bool checkequal(int l, int r)
    {
      if(l==r || (l>='A' && l<='Z' && r==l+32 ) || (r>='A' && r<='Z' && l==r+32))
      {
          return true;
      }
     return false;
    }
    bool isPalindrome(string s) {
       int n = s.size();
       if(n==0)
       {
           return true;
       }
       vector<int> arr;
       for(int i=0;i<n;i++)
       {
           if((s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z') || (s[i]>='0' && s[i]<='9'))
           {
               arr.push_back(s[i]);
           }
       }
       int l=0;
       int r = arr.size();
       while(l<r)
       {
           if(checkequal(arr[l],arr[r-1])==false)
           {
               return false;
           }
         l++;
         r--;
       }
       return true;
    }
};
