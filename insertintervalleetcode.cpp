class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
       vector<int> currentlimit = newInterval;
       vector<vector<int>> result;
       int high=1;
       int low=0;
       for(int i=0;i<intervals.size();i++)
       {
           vector<int> currentinterval = intervals[i];
           if(currentlimit[low]>currentinterval[high])
           {
               result.push_back(currentinterval);
               continue;
           }
           if(currentlimit[high]<currentinterval[low])
           {
               result.push_back(currentlimit);
               result.insert(result.end(),intervals.begin()+i,intervals.end());
               return result;
           }
           else
           {
               currentlimit[low]=min(currentlimit[low],currentinterval[low]);
               currentlimit[high]=max(currentlimit[high],currentinterval[high]);
           }
       }
       result.push_back(currentlimit);
       return result;
    }
};
