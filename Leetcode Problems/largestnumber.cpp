
bool lexo(int a,int b){
    string s1=to_string(a);
    string s2=to_string(b);
    string s=s1+s2;
    string t=s2+s1;
    return s>t;
}

class Solution {
public:
    
 
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),lexo);
        string s;
        for(auto x:nums){
            string temp=to_string(x);
            s+=temp;
        }
        char c=s[0];
        while(c=='0'){
            s=s.substr(1);
            c=s[0];
        }
        if(s.size()==0){
            return "0";
        }
        return s;
    }
};

