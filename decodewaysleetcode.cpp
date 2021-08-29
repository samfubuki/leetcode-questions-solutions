class Solution {
public:
    int numDecodings(string s) {
     if(s.length()==0 || s[0]=='0')
     {
         return 0;
     }
     if(s.length()==1)
     {
         return 1;
     }
     int cnt1=1, cnt2=1;
     for(int i=1;i<s.length();i++)
     {
         int d = s[i]-'0';
         int dd = (s[i-1]-'0')*10+d;
         int cnt=0;
         if(d>0)
         {
             cnt=cnt+cnt2;
         }
         if(dd>=10 && dd<=26)
         {
             cnt=cnt+cnt1;
         }
         cnt1=cnt2;
         cnt2=cnt;
     }
     return cnt2;
    }
};