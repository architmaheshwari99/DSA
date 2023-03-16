//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<pair<int,int>, int>> pq;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    pq.push({{i,j}, 0});
                }
            }
        }
        
        int maxTime = -1;
        while(!pq.empty()){
            auto top = pq.front();
            pq.pop();
            int x = top.first.first;
            int y = top.first.second;
            int t = top.second;
            maxTime=max(maxTime, t);
            if(x>0 && grid[x-1][y]==1){
                grid[x-1][y]=2;
                pq.push({{x-1,y}, t+1});
            }
            if(x<grid.size()-1 && grid[x+1][y]==1){
                grid[x+1][y]=2;
                pq.push({{x+1,y}, t+1});
            }
            if(y>0 && grid[x][y-1]==1){
                grid[x][y-1]=2;
                pq.push({{x,y-1}, t+1});
            }
            if(y<grid[0].size()-1 && grid[x][y+1]==1){
                grid[x][y+1]=2;
                pq.push({{x,y+1}, t+1});
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return maxTime;
        
        
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends