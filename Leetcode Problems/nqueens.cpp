class Solution {
public:

    
    bool canPlace(int n,vector<vector<int>> &a,int i,int j){
        for(int row=0;row<i;row++){
            if(a[row][j]==1){
                return false;
            }
        }
        
        int row=i;
        int col=j;
        while(row>=0 && row<n && col>=0 && col<n){
            if(a[row][col]==1){
                return false;
            }
            row--;
            col--;
        }
        row=i,col=j;
         while(row>=0 && row<n && col>=0 && col<n){
            if(a[row][col]==1){
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    
    bool NQueen(int n,vector<vector<int>> &a,int i,vector<int> &res){
        if(i==n){
            res[0]++;
            return false;
        }
        for(int j=0;j<n;j++){
            if(canPlace(n,a,i,j)){
                a[i][j]=1;
                if(NQueen(n,a,i+1,res)){
                    return true;
                }
            }
            a[i][j]=0;
        }
        return false;
    }
    int totalNQueens(int num) {
        
        vector<vector<int> > a(num,vector<int>(num,0));
        vector<int> v{0};
        
        bool r=NQueen(num,a,0,v);
        return v[0];
    }
};