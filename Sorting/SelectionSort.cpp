#include<iostream>
#include<vector>

using namespace std;

void SelectionSort(int A[],int n){
    for(int i=0;i<n-1;i++){
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<A[minIndex]){
                minIndex=j;
            }
        }
        int temp=A[i];
        A[i]=A[minIndex];
        A[minIndex]=temp;
    }
}
int main(){
    int a[]={12,1,6,7,3,8,6};

    int n=sizeof(a)/sizeof(a[0]);
    // int n;
    // cin>>n;

    // int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    SelectionSort(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }

    return 0;
}