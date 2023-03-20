//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:


    void checkBoard(vector<vector<char>> &board, int x, vector<vector<int>> &ans, int *uphash, int *upDiagonal, int *downDiagonal){
        if(x==board.size()){
            vector<int> temp;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board.size();j++){
                    if(board[i][j]=='Q'){
                        temp.push_back(j+1);
                    }
                }
            }
            ans.push_back(temp);
            return;
        }
        
        for(int j=0;j<board.size();j++){
            if( !uphash[j] && !upDiagonal[x+j] && !downDiagonal[(board.size()-1)+(j-x)]){
                uphash[j] = 1;
                upDiagonal[x+j]=1;
                downDiagonal[(board.size()-1)+(j-x)]=1;
                board[x][j] = 'Q';
                checkBoard(board, x+1,ans, uphash, upDiagonal, downDiagonal);
                board[x][j] = '.';
                uphash[j] = 0;
                upDiagonal[x+j]=0;
                downDiagonal[(board.size()-1)+(j-x)]=0;
            }
        }
        
    }
    

    
    vector<vector<int>> nQueen(int n) {
        vector<vector<char>> board(n, vector<char> (n)); 
        int uphash[2*n+1]={0}, downDiagonal[2*n+1]={0}, upDiagonal[2*n+1]={0};
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                board[i][j] = '.';
        vector<vector<int>> ans; 
        
        checkBoard(board, 0, ans, uphash, upDiagonal, downDiagonal);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends