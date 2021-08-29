class Solution {
public:
    vector<string> helper(int n)
    {
        if(n==1)
        {
            return {"0","1"};
        }
        vector<string> temp = helper(n-1);
        vector<string> res;
        for(int i=0;i<temp.size();i++)
        {
            res.push_back("0"+temp[i]);
        }
        for(int i=temp.size()-1;i>=0;i--)
        {
            res.push_back("1"+temp[i]);
        }
      return res;
    }
    vector<int> grayCode(int n) {
       vector<string> result = helper(n);
       vector<int> finalres;
       for(string &s: result)
       {
           bitset<32> bt(s);
           finalres.push_back(bt.to_ulong());
       }
      return finalres;
    }
};
