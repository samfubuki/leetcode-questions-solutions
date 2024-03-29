class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int i=0,high=nums.size()-1,low=0;
      while(low<=high)
      {
          int mid = (low+high)/2;
          if(target<nums[mid])
          {
              high=mid-1;
          }
          else if(target>nums[mid])
          {
              low=mid+1;
          }
          else
          {
              return mid;
          }
      }
      return low;
    }
};
