class Solution {
public:
    
    void markIslands(int i,int j,vector<vector<char> >& grid,int n,int m ){
        if(i>=0 && i<=n && j>=0 && j<=m && grid[i][j]=='1'){
            grid[i][j]='0';
            markIslands(i+1,j,grid,n,m);
            markIslands(i,j+1,grid,n,m);
            markIslands(i-1,j,grid,n,m);
            markIslands(i,j-1,grid,n,m);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size()==0){
            return 0;
        }
        
        int n=grid.size()-1;
        int m=grid[0].size()-1;
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    markIslands(i,j,grid,n,m);
                }
            }
        }
        return count;
        
    }
};