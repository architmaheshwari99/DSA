//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:

    void subset(vector<int> &ans, int idx, int sum, int N, vector<int> arr){
        if(idx==N){
            ans.push_back(sum);
            return;
        }
        
        subset(ans, idx+1, sum+arr[idx], N, arr);
        
        subset(ans, idx+1, sum, N, arr);
        
    }



    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        sort(arr.begin(), arr.end());
        vector<int> ans;
        subset(ans, 0, 0, N, arr);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends