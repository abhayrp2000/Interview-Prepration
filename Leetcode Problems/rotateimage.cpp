class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int j=0;
        int k=matrix.size()-1;
        for(int i=0;i<matrix[0].size();i++){
            while(j<=k){
                swap(matrix[j][i],matrix[k][i]);
                j++;
                k--;
            }
            j=0;
            k=matrix.size()-1;
        }
        
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(i<j){
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
        }
    }
};