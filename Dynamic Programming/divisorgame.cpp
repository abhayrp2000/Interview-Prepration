class Solution {
public:
    bool divisorGame(int N) {
        
        int x=1;
        int count=0;
        
        while(N-x>0){
            for(int i=1;i<N;i++){
                if(N%i==0){
                    cout<<i<<endl;
                    x=i;
                }
            }
            N=N-x;
            count++;
        }
        
        if(count%2!=0){
            return true;
        }
        return false;
        
    }
};