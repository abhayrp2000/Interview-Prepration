#include<bits/stdc++.h>

using namespace std;

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int A[],int start,int end){
    int pivotvalue=A[end];
    int pivotIndex=start;

    for(int i=start;i<end;i++){
        if(A[i]<=pivotvalue){
            swap(&A[i],&A[pivotIndex]);
            pivotIndex++;
        }
    }
    swap(&A[pivotIndex],&A[end]);

    return pivotIndex;
}


void QuickSort(int A[],int start,int end){
    if(start<end){
        int pivotIndex=Partition(A,start,end);
        QuickSort(A,start,pivotIndex-1);
        QuickSort(A,pivotIndex+1,end); 
    }
    
}

int main(){

    int A[]={21,12,1,5,6,2,16};
    int n=sizeof(A)/sizeof(A[0]);

    QuickSort(A,0,n-1);

    for(int i=0;i<n;i++){
        cout<<A[i]<<" ";
    }
    return 0;
}