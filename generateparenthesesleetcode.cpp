class Solution {
public:
     vector<string> v;
     void solve(int open,int close,string op)
    {
        if(open==0 && close==0)
        {
            v.push_back(op);
            return;
        }
        if(open!=0)
        {
            string op1=op;
            op1 = op1+'(';
            solve(open-1,close,op1);
        }
        if(close>open)
        {
            string op2=op;
            op2 = op2+')';
            solve(open,close-1,op2);
        }
    }
    vector<string> generateParenthesis(int n) {

        int close = n;
        int open = n;
        string op = "";
        solve(open,close,op);
        return v;
    }

};
