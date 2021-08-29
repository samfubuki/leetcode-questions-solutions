class Solution {
public:
    bool go(string fs,string ss,string is,unordered_map<string,bool> &dp)
   {
        if(fs.empty() && ss.empty() && is.empty())
            return true;
        if(is.empty())
            return false;
        string str=fs+"|"+ss+"|"+is;
        if(dp.count(str))
            return dp[str];
        bool first=(!fs.empty() and fs[0]==is[0]) and go(fs.substr(1),ss,is.substr(1),dp);
        bool second=(!ss.empty() and ss[0]==is[0]) and go(fs,ss.substr(1),is.substr(1),dp);
        return dp[str]=(first || second);
    }
    bool isInterleave(string s1, string s2, string s3) {
      unordered_map<string,bool> dp;
      return go(s1,s2,s3,dp);
    }
};
