//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        int T[x+1][y+1];
        memset(T, 0 ,sizeof(T));
        
        for(int i=1;i<=x;i++){
            for(int j=1;j<=y;j++){
                if(s1[i-1]==s2[j-1]){
                    T[i][j] = 1 + T[i-1][j-1];
                } else {
                    T[i][j] = max(T[i-1][j], T[i][j-1]);
                }
            }
        }
        int i=x,j=y;
        string s="";
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                s+=s1[i-1];
                i--;
                j--;
            }
            else if(T[i-1][j]>=T[i][j]){
                i--;
            } else {
                j--;
            }
        }
        cout<<s;
        
        
        return T[x][y];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends