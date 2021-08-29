class Solution {
public:
    bool valid(string s, unordered_map<string, int> wordcnt, int n)
    {
        string temp="";
        for(int i=0;i<n;i++)
        {
            temp = temp + s[i];
        }
        for(int i=n;i<s.size();i++)
        {
            if(temp.size()%n==0)
            {
                if(wordcnt.find(temp)==wordcnt.end())
                {
                    return false;
                }
                else
                {
                    if(wordcnt[temp]==1)
                    {
                        wordcnt.erase(temp);
                        temp="";
                    }
                    else
                    {
                        wordcnt[temp]--;
                        temp="";
                    }
                }
            }
           temp=temp+s[i];
        }
        if(wordcnt.find(temp)==wordcnt.end())
        {
            return false;
        }
        else
        {
            if(wordcnt[temp]==1)
            {
                wordcnt.erase(temp);
                temp="";
            }
            else
            {
                wordcnt[temp]--;
                temp="";
            }
        }
       return wordcnt.size()==0;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.size()==0 || words.size()==0)
        {
            return {};
        }
        unordered_map<string,int> wordcnt;
        for(int i=0;i<words.size();i++)
        {
            wordcnt[words[i]]++;
        }
        vector<int> ans;
        int window = words.size()*words[0].size();
        string temp = "";
        for(int i=0;i<window;i++)
        {
            temp=temp+s[i];
        }
        for(int i=window;i<s.size();i++)
        {
            if(temp.size()%window==0 && valid(temp,wordcnt,words[0].size()))
            {
                ans.push_back(i-window);
            }
            temp=temp+s[i];
            if(temp.size()>window)
            {
                temp.erase(0,1);
            }

        }
        if(temp.size()%window==0 && valid(temp,wordcnt,words[0].size()))
        {
            ans.push_back(s.size()-window);
        }
        return ans;
    }
};
