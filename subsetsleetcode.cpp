class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int> &v, vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(v);
            return;
        }
       solve(i+1,v,nums);
       v.push_back(nums[i]);
       solve(i+1,v,nums);
       v.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {

      vector<int> v;
      solve(0,v,nums);
      return ans;
    }
};
