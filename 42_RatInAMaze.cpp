//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    
    void findSol(vector<string> &ans, vector<vector<int>> &mat, int i, int j, string temp){
        

        // DLRU
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || mat[i][j]==0) return;
        
        if(i==mat.size()-1 && j==mat[0].size()-1){
            ans.push_back(temp);
            return;
        }
        
        mat[i][j] = 0;
        
        temp.push_back('D');
        findSol(ans, mat, i+1, j, temp);
        temp.pop_back();
        
        temp.push_back('L');
        findSol(ans, mat, i, j-1, temp);
        temp.pop_back();
        
        temp.push_back('R');
        findSol(ans, mat, i, j+1, temp);
        temp.pop_back();
        
        temp.push_back('U');
        findSol(ans, mat, i-1, j, temp);
        temp.pop_back();
        
        mat[i][j] = 1;
        
    }
    

    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        string temp;
        findSol(ans, m, 0, 0, temp);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends