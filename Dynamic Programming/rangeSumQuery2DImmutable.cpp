//https://leetcode.com/problems/range-sum-query-2d-immutable/

class NumMatrix {
public:
    vector<vector<int> > prefix;
    
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==0){
            return;
        }
        int m=matrix[0].size();
        if(m==0){
            return;
        }
            
        
        
        prefix.resize(n,vector<int> (m,0));
        prefix[0][0]=matrix[0][0];
        
        for(int i=1;i<m;i++){
            prefix[0][i]=matrix[0][i]+prefix[0][i-1];
        }
        
        for(int j=1;j<n;j++){
            prefix[j][0]=matrix[j][0]+prefix[j-1][0];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                prefix[i][j]=prefix[i-1][j]+prefix[i][j-1]-prefix[i-1][j-1]+matrix[i][j];
            }
            }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int total=prefix[row2][col2];
        if(row1>0){
            total-=prefix[row1-1][col2];
        }
        if(col1>0){
            total-=prefix[row2][col1-1];
        }
        
        if(row1>0 && col1>0){
            total+=prefix[row1-1][col1-1];
        }
        return total;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */