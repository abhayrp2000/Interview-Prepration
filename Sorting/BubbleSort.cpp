#include<vector>
#include<iostream>
using namespace std;
void BubbleSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(A[j]>A[j+1]){
                int temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
            }
        }
    }
    return;
}



int main(){
    int A[]={12,1,13,5,6,43,8};
    int n=sizeof(A)/sizeof(A[0]);
    // int n;
    // cin>>n;

    // int A[n];
    // for(int i=0;i<n;i++){
    //     cin>>A[i];
    // }

    BubbleSort(A,n);
    for(int i=0;i<n;i++){
        cout<<A[i]<<endl;
    }
}