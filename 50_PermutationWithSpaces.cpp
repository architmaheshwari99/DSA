//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:

    void solve(string S, vector<string> &ans, int idx){
        if(idx>S.size()) return;
        if(idx==S.size()-1){
            ans.push_back(S);
            return;
        }
        S.insert(idx+1, " ");
        solve(S, ans, idx+2);
        S.erase(idx+1,1);
        
        
        solve(S, ans, idx+1);
        
    }

    vector<string> permutation(string S){
        // Code Here
        
        vector<string> ans;
        solve(S, ans, 0);
        return ans;
        
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends