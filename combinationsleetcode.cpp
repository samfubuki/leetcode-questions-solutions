class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> finalans;
        solve(n,1,k,ans,finalans);
        return ans;
    }
private:
    void solve(int n, int start, int k, vector<vector<int>> &ans, vector<int> &finalans)
    {
        if(finalans.size()==k)
        {
            ans.push_back(finalans);
            return;
        }
        for(int i=start;i<=n;i++)
        {
            finalans.push_back(i);
            solve(n,i+1,k,ans,finalans);
            finalans.pop_back();
        }
    }
};
