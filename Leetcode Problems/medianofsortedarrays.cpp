class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int nL=nums1.size();
        int nR=nums2.size();
        
        int i=0,j=0;
        
        
        
        vector<int> res;
        
        while(i<nL && j<nR){
            if(nums1[i]<nums2[j]){
                res.push_back(nums1[i]);
                i++;
            }else{
                res.push_back(nums2[j]);
                j++;
            }
        }
        
        if(i<nL){
            for(int k=i;k<nL;k++){
                res.push_back(nums1[k]);
                
            }
        }
        if(j<nR){
            for(int k=j;k<nR;k++){
                res.push_back(nums2[k]);
            }
        }
        
cout<<res.size()<<endl;
        
        if(res.size()%2!=0){
            int mid=res.size()/2;
            return res[mid];
        }else{
            int mid=res.size()/2;
// //             cout<<mid<<"mid"<<endl;
//             for(auto num:res){
//                 cout<<num<<", ";
//             }
            
// //             cout<<res[mid];
// //             cout<<endl<<res[mid-1]<<endl;
//             cout<<res[0]<<"damn"<<res[1]<<endl;
            return (double)(res[mid]+res[mid-1])/(double)2;
        }
        
    }
};