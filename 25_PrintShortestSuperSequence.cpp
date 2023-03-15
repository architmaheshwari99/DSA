//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        
        int T[m+1][n+1];
        memset(T, 0, sizeof(T));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1])
                    T[i][j] = 1+T[i-1][j-1];
                else{
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                }
            }
        }
        
        
        
        int i=m,j=n;
        string s="";
        while(i>0 && j>0){
            if(X[i-1]==Y[j-1]){
                s+=X[i-1];
                i--;j--;
            } 
            else if(T[i-1][j]>T[i][j-1]){
                s+=X[i-1];
                i--;
            } else {
                s+=Y[j-1];
                j--;
            }
        }
        if(i>0){
            string left = X.substr(0,i);
            reverse(left.begin(), left.end());
            cout<<s+left;
        }
            
        else{
            string left = Y.substr(0,j);
            reverse(left.begin(), left.end());
            cout<<s+left;
        }
            
        
        return m+n - T[m][n];
        
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends