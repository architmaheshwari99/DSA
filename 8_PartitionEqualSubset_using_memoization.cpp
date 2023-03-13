//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int T[101][10001];
    int subsetExists(int arr[], int N, int sum){
        if(sum==0) return true;
        if(N==0) return false;
        if(T[N][sum]!=-1) return T[N][sum]==1;
        
        if(arr[N-1]<=sum){
            return T[N][sum] = subsetExists(arr, N-1, sum-arr[N-1]) || subsetExists(arr, N-1, sum);
        } else {
            return T[N][sum] = subsetExists(arr, N-1, sum);
        }
    }


    int equalPartition(int N, int arr[])
    {
        memset(T, -1, sizeof(T));
        int sum = 0;
        
        for(int i=0;i<N;i++)
            sum+=arr[i];
            
        if(sum%2!=0) return false;
        
        sum=sum/2;
        
        return subsetExists(arr, N, sum);
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends