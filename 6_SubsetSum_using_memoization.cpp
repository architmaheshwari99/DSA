//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:

    bool isSubsetSum(vector<int>arr, int sum){
        bool T[101][10001];
        memset(T, false, sizeof(T));
        for(int i=0;i<=arr.size();i++){
            for(int j=0;j<=sum;j++){
                if(j==0)
                    T[i][j] = true;
                else if(i==0)
                    T[i][j] = false;
                else if(arr[i-1]<=sum)
                    T[i][j] = T[i-1][j] || T[i-1][j-arr[i-1]];
                else
                    T[i][j] = T[i-1][j];
            }
        }
        return T[arr.size()][sum];
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