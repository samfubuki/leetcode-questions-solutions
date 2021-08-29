class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
        {
            return s;
        }
        vector<string> v(numRows,"");
        int k=0,flag=0;
        for(int i=0;i<s.size();i++)
        {
            v[k]=v[k]+s[i];
            if(!k)
            {
                flag=1;
            }
            if(k==numRows-1)
            {
                flag=0;
            }
            if(flag)
            {
                k++;
            }
            else
            {
                k--;
            }
        }
        string ret = "";
        for(int i=0;i<v.size();i++)
        {
            ret = ret + v[i];
        }
        return ret;

    }
};
