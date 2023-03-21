class Solution {
public:

    bool isPalindrome(string s){
        int i=0, j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;j--;
        }
        return true;
    }

    void solve(string s, vector<string> &temp, vector<vector<string>> &ans, int idx){

        if(idx==s.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=idx;i<s.size(); i++){
            if(isPalindrome(s.substr(idx, i-idx+1))){
                temp.push_back(s.substr(idx, i-idx+1));
                solve(s, temp, ans, i+1);
                temp.pop_back();
            }
        }

    }



    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        solve(s, temp, ans, 0);

        return ans;
    }
};