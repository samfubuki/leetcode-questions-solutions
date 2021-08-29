class Solution {
public:

    vector<string> letterCombinations(string digits) {
       vector<string> result;
       if(digits.length()==0)
       {
           return result;
       }
       unordered_map<char,string> mp =
       {
           {'2',"abc"},
           {'3',"def"},
           {'4',"ghi"},
           {'5',"jkl"},
           {'6',"mno"},
           {'7',"pqrs"},
           {'8',"tuv"},
           {'9',"wxyz"}
       };
       string current;
       solverecursive(digits,0,mp,current,result);
       return result;

    }
    private:
      void solverecursive(string digits,int i, unordered_map<char,string> mp, string &current, vector<string>& result)
      {
          if(i==digits.length())
          {
              result.push_back(current);
              return;
          }
          string curr = mp[digits[i]];
          for(int j=0;j<curr.length();j++)
          {
              current.push_back(curr[j]);
              solverecursive(digits,i+1,mp,current,result);
              current.pop_back();
          }
      }
};
