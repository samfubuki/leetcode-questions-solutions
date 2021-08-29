 int cnt=0;
    int n = digits.size();
    for(int i=0;i<n;i++)
    {
        if(digits[i]==9)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    if(cnt==n)
    {
        vector<int> ans;
        ans.push_back(1);
        for(int i=0;i<n;i++)
        {
            ans.push_back(0);
        }
     return ans;
    }
    else if(digits[n-1]==9)
    {
        int carry=1;
        for(int i=n-1;i>=0 && carry==1;i--)
        {
            if(digits[i]==9)
            {
                digits[i]=0;
            }
            else
            {
                digits[i]++;
                carry=0;
            }
        }
    }
    else
    {
        digits[n-1]++;
    }
        reverse(digits.begin(),digits.end());
        for(int i=n-1;i>=0 && digits[i]==0;i--)
        {
            digits.pop_back();
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
