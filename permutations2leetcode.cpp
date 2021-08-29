class Solution {
private:
   void permute(map<int,int>& mp, vector<vector<int>>& result, vector<int>& temp, int start)
   {
       if(start==temp.size())
       {
           result.push_back(vector<int>(temp.begin(),temp.end()));
       }
       else
       {
           for(auto &x:mp)
           {
               if(x.second>0)
               {
                 mp[x.first] = x.second-1;
                 temp[start] = x.first;
                 permute(mp,result,temp,start+1);
                 mp[x.first] = x.second+1;
               }
           }
       }
   }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        map<int,int> mp;
        vector<int> temp(nums.size());
        for(int num:nums)
        {
            mp[num]++;
        }
        permute(mp,result,temp,0);
        return result;
    }
};
