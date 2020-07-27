class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        if(n==0){
            return;
        }
        
        int m=matrix[0].size();
        
        map<pair<int,int>,int> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0 && mp.find({i,j})==mp.end()){
                    mp.insert(make_pair(make_pair(i,j),1));
                    
                    for(int k=0;k<n;k++){
                        if(matrix[k][j]!=0){
                            matrix[k][j]=0;
                            mp.insert(make_pair(make_pair(k,j),1));
                        }
                    }
                    
                    for(int k=0;k<m;k++){
                        if(matrix[i][k]!=0){
                            matrix[i][k]=0;
                            mp.insert(make_pair(make_pair(i,k),1));
                        }
                    }
                }
            }
        }
        
        
        return;
    }
};