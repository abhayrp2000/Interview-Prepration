class Solution {
public:
    
    bool canPlace(vector<vector<char>> &board,int i,int j,int n,int num){
        char val=num+'0';
        for(int x=0;x<n;x++){
            if(board[i][x]==val || board[x][j]==val){
                return false;
            }
        }
        
        int root=sqrt(n);
        int sx=(i/root)*root;
        int sy=(j/root)*root;
        
        for(int x=sx;x<sx+root;x++){
            for(int y=sy;y<sy+root;y++){
                if(board[x][y]==val){
                    return false;
                }
            }
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>> &board,int i,int j,int n){
        if(i==n){
            return true;
        }
        if(j==n){
            return solveSudoku(board,i+1,0,n);
        }
        if(board[i][j]!='.'){
            return solveSudoku(board,i,j+1,n);
        }else{
            for(int num=1;num<=n;num++){
            if(canPlace(board,i,j,n,num)){
                board[i][j]=num+'0';
                bool canSolve=solveSudoku(board,i,j+1,n);
                if(canSolve){
                    return true;
                }
            }
        }
            board[i][j]='.';
            return false;
        }
        
        
    }
    
    
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        bool res=solveSudoku(board,0,0,n);
        return;
        
    }
};