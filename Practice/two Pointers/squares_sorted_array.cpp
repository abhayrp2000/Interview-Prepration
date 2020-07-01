class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int j=0;
        while(j<A.size() && A[j]<0){
            j++;
        }
        int i=j-1;
        int k=0;
        vector<int> v(A.size());
        while(i>=0 && j<A.size()){
            if(A[i]*A[i]<A[j]*A[j]){
                v[k]=A[i]*A[i];
                i--;
                k++;
            }else{
                v[k]=A[j]*A[j];
                j++;
                k++;
            }
        }
        
        while(i>=0){
            v[k]=A[i]*A[i];
            i--;
            k++;
        }
        
        while(j<A.size()){
            v[k]=A[j]*A[j];
            j++;
            k++;
        }
        return v;
        
    }
};