//https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        
        //Construct prexif sum array 
        int m=mat.size();
        int n=mat[0].size();
        
        vector<vector<int> > v(m,vector<int> (n,0));
        v[0][0]=mat[0][0];
        
        //fill the first row
        for(int i=1;i<n;i++){
            v[0][i]=mat[0][i]+v[0][i-1];
        }
        //fill col 0
        for(int i=1;i<m;i++){
            v[i][0]=mat[i][0]+v[i-1][0];
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                v[i][j]=v[i-1][j]+v[i][j-1]+mat[i][j]-v[i-1][j-1];
            }
        }
        
        vector<vector<int> > answer(m,vector<int>(n,0));
        //using prefix sum array with constant query time find all elements of the answer matrix
        
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int p,q,r,s;
                p=i-K;
                q=j-K;
                r=i+K;
                s=j+K;
                if(p<0){
                    p=0;
                }
                if(q<0){
                    q=0;
                }
                if(r>=m){
                    r=m-1;
                }
                if(s>=n){
                    s=n-1;
                }
                
                answer[i][j]=v[r][s];
                if(p>0){
                    answer[i][j]-=v[p-1][s];
                }
                if(q>0){
                    answer[i][j]-=v[r][q-1];
                }
                if(p>0 && q>0){
                    answer[i][j]+=v[p-1][q-1];
                }
                
            }
        }
        
        return answer;
        
        
        
    }
};