class Solution {
public:
    
    int factorial(int n){
        if(n<=1){
            return 1;
        }
        return n*factorial(n-1);
    }
    
    void find_k(vector<char> &arr,int k,string &result){
        if(arr.empty()){
            return;
        }
        
        int n=arr.size();
        
        int temp=factorial(n-1);
        int index=(k-1)/temp;
        
        result+=arr[index];
        arr.erase(arr.begin()+index);
        k=k-(temp*index);
        find_k(arr,k,result);
    }
    string getPermutation(int n, int k) {
        
        vector<char> arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i+'0');
        }
        
        string result;
        find_k(arr,k,result);
        return result;
        
    }
};