class Solution {
public:
    int maxArea(vector<int>& height) {
      int n = height.size();
      int maxarea = INT_MIN;
      int i=0;
      int j= n-1;
      while(i<j)
      {
          int minele = min(height[i],height[j]);
          maxarea = max(maxarea,minele*(j-i));
          if(height[i]<height[j])
          {
              i++;
          }
          else
          {
              j--;
          }
      }
      return maxarea;
    }
};
