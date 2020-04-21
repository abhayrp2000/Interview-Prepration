class Solution {
public:
    
    vector<string> v;
    int checkPalindrome(string s,int i,int j){
        int count=0;
        while(i>=0 && j<s.size() && s[i]==s[j]){
            count++;
            //v.push_back(s.substr(i,j));
            i--;
            j++;
        }
        
        return count;
    }
    int countSubstrings(string s) {
        
        if(s.size()<1){
            return 0;
            
        }
        
        int count=0;
        for(int i=0;i<s.size();i++){
            count+=checkPalindrome(s,i,i);
            count+=checkPalindrome(s,i,i+1);
        }
        
        // for(auto it=v.begin();it<v.end();it++){
        //     cout<<*it<<endl;
        // }
        
        return count;
        
    }
};