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
        
        bool T[101][10001];
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=sum;j++){
                if(j==0) T[i][j]=true;
                else if(i==0) T[i][j]=false;
                else if(arr[i-1]<=j) 
                    T[i][j] = T[i-1][j] || T[i-1][j-arr[i-1]];
                else 
                    T[i][j] = T[i-1][j];
            }
        }
        
        return T[N][sum];
        
        
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