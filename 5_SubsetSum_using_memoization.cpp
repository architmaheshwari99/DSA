//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int T[101][10001];

    bool findSubset(vector<int> arr, int sum, int n){
        
        if(sum==0) return true;
        if(n==0) return false;
        if(T[n][sum]!=-1) return T[n][sum]==1;

        if(arr[n-1]<=sum) {
            bool res = findSubset(arr, sum, n-1) || findSubset(arr, sum-arr[n-1], n-1);
            T[n][sum] = (int)(res==true);
            return res;
        } else {
            bool res = findSubset(arr, sum, n-1);
            T[n][sum] = (int)(res==true);
            return res;
        }
    }


    bool isSubsetSum(vector<int>arr, int sum){
        memset(T, -1, sizeof(T));
        return findSubset(arr, sum, arr.size());

    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends