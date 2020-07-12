class Solution {
public:
    int bitwiseComplement(int N) {
        
        int n=N;
        
        if(N==0){
            return 1;
        }
        
        if(N==1){
            return 0;
        }
        
        int bits=0;
        
        while(n>0){
            bits++;
            n=n>>1;
        }
        
        int allsetbits=pow(2,bits)-1;
        
        return N^allsetbits;
        
    }
};