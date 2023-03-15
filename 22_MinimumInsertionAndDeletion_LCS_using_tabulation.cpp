//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int m=str1.size(), n=str2.size();
	    int T[m+1][n+1];
	    memset(T, 0, sizeof(T));
	    
	    for(int i=1;i<=m;i++){
	        for(int j=1;j<=n;j++){
	            if(str1[i-1]==str2[j-1])
	                T[i][j] = 1+T[i-1][j-1];
	            else {
	                T[i][j] = max(T[i-1][j], T[i][j-1]);
	            }
	        }
	    }
	    
	    return n-T[m][n] + m-T[m][n];
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends