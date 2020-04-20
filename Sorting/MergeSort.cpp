#include<bits/stdc++.h>

using namespace std;

void Merge(int A[],int left,int mid,int right){
    int nL=mid-left+1;
    int nR=right-mid;

    

    int leftArray[nL];
    int rightArray[nR];

    for(int i=0;i<nL;i++){
        leftArray[i]=A[left+i];
    }
    for(int j=0;j<nR;j++){
        rightArray[j]=A[mid+j+1];
    }

    //Merging the arrays
    int i=0,j=0,k=left;
    while (i<nL && j<nR){
        if(leftArray[i]<=rightArray[j]){
            A[k]=leftArray[i];
            i++;
        }else{
            A[k]=rightArray[j];
            j++;
            
        }
        k++;
        
    }

    //one of the arrays finish first to add the remaining elements
    while (i<nL)
    {
        A[k]=leftArray[i];
        i++;
        k++;
    }

    while (j<nR)
    {
        A[k]=rightArray[j];
        j++;
        k++;
    }
    
    
    
}




void MergeSort(int A[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,right);
    }
    return;
}

int main(){
    // int a[]={1,423,121,12,1,65,16};
    // int n=sizeof(a)/sizeof(a[0]);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    MergeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}