class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        
        vector<string> permu;
        
        if(S.size()==0){
            return permu;
        }
        
        permu.push_back(S);
        for(int i=0;i<S.size();i++){
            if(isalpha(S[i])){
                int n=permu.size();
                for(int j=0;j<n;j++){
                    vector<char> cc(permu[j].begin(),permu[j].end());
                    
                    if(islower(cc[i])){
                        cc[i]=toupper(cc[i]);
                    }else{
                        cc[i]=tolower(cc[i]);
                    }
                    
                    string temp(cc.begin(),cc.end());
                    permu.push_back(temp);
                }
            }
        }
        return permu;
        
    }
};