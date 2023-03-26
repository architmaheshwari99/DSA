class Solution {
public:

    void solve(string s, vector<string> &ans, int idx){
        if(idx==s.size()){
            ans.push_back(s);
            return;
        }

        if(s[idx]>='0' && s[idx]<='9'){
            return solve(s, ans, idx+1);
        }
        if(s[idx]>='a' && s[idx]<='z'){
            s[idx]-=32;
            solve(s, ans, idx+1);
            s[idx]+=32;
        } else {
            s[idx]+=32;
            solve(s, ans, idx+1);
            s[idx]-=32;
        }

        solve(s, ans, idx+1);

    }


    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        solve(s, ans, 0);
        return ans;
    }
};