class Solution {
public:
    void dfs(vector<vector<int>> & board,int i,int j){
        if(i<0 || j<0 ||i>=board.size() || j>=board[0].size() || board[i][j]!=1){
            return;
        }
        board[i][j]='#';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
    

    
    int numEnclaves(vector<vector<int>>& board) {
   
        
        
        int n=board.size();
        if(n==0){
            return 0;
        }
        
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            if(board[i][0]==1){
                dfs(board,i,0);
            }
            if(board[i][m-1]==1){
                dfs(board,i,m-1);
            }
        }
        
        for(int i=0;i<m;i++){
            if(board[0][i]==1){
                dfs(board,0,i);
            }
            
            if(board[n-1][i]==1){
                dfs(board,n-1,i);
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1){
                    count++;
                }
                
            }
        }
            
            return count;
        
        
    
        
    }
};