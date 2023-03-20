//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void findPermutations(string S, vector<bool> &visited,vector<string> &ans, string temp){
	        if(temp.size()==S.size()){
	            ans.push_back(temp);
	            return;
	        }
	        
	        for(int i=0;i<S.size();i++){
	            if(visited[i]==false){
	                temp.push_back(S[i]);
    	            visited[i] = true;
    	            findPermutations(S, visited,ans, temp);
    	            visited[i] = false;
    	            temp.pop_back();
	            }
	        }
	    }
	
	    
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<bool> visited(S.size(), false);
		    vector<string> ans;
		    sort(S.begin(), S.end());
		    findPermutations(S, visited, ans, "");
		    set<string> s(ans.begin(), ans.end());
		    return vector<string> (s.begin(), s.end());
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends