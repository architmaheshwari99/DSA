//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i=0;i<N;i++)
            sum+=arr[i];
            
        if(sum%2!=0) return false;
        
        sum=sum/2;
        
        bool T[sum+1] = {1};
        
        for(int i=0;i<=N;i++){
            for(int j=sum;j>0;j--){
                if(arr[i-1]<=j) 
                    T[j] = T[j] || T[j-arr[i-1]];
            }
        }
        
        return T[sum];
        
        
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