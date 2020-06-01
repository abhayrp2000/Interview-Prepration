//https://leetcode.com/problems/minimum-path-sum/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        
        int n=grid.size();
        if(n==0){
            return 0;
        }
        int m=grid[0].size();
        if(m==0){
            return 0;
        }
        vector<vector<int> > v(n,vector<int> (m,0));
        
        v[0][0]=grid[0][0];
        for(int i=1;i<n;i++){
            v[i][0]=v[i-1][0]+grid[i][0];
        }
        
        for(int i=1;i<m;i++){
            v[0][i]=v[0][i-1]+grid[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                v[i][j]=min(v[i-1][j],v[i][j-1])+grid[i][j];
            }
        }
        
        return v[n-1][m-1];
        
    }
};