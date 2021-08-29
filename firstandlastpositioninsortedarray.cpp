class Solution {
public:
    int firstoccurence(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low=0,high=n-1,res=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                res=mid;
                high=mid-1;
            }
        }
       return res;
    }
    int lastoccurence(vector<int> &nums, int target)
    {
        int n = nums.size();
        int low=0,high=n-1,res=-1;
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]>target)
            {
                high=mid-1;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                res=mid;
                low=mid+1;
            }
        }
       return  res;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> ans;
       int ind1 = firstoccurence(nums,target);
       ans.push_back(ind1);
       int ind2 = lastoccurence(nums,target);
       ans.push_back(ind2);
       return ans;

    }
};
