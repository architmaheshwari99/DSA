class Solution {
public:

    void solve(int left, int right, vector<string> &ans, string temp){

        if(left==0 && right==0){
            ans.push_back(temp);
            return;
        }
        if(left==-1 || right==-1){
            return;
        }
        solve(left-1, right, ans, temp+'(');
        if(right>left){
            solve(left, right-1, ans, temp+')');
        }

    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, n, ans, "");
        return ans;
    }
};