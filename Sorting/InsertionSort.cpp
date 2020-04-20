#include<vector>
#include<iostream>
using namespace std;

void InsertionSort(int A[],int n){
    for(int i=1;i<n;i++){
        int hole=i;
        int value=A[i];
        while(hole>0 && A[hole-1]>value){
            A[hole]=A[hole-1];
            hole--;
        }
        A[hole]=value;
    }
}

int main(){
    int a[]={12,21,1,3,12,4,3,6};
    int n=sizeof(a)/sizeof(a[0]);
    // int n;
    // cin>>n;

    // int a[n];
    // for(int i=0;i<n;i++){
    //     cin>>a[i];
    // }

    InsertionSort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}