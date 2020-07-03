#include<iostream>

using namespace std;

int n=4;
int visited_check=(1<<n)-1;

int graph[][4] = { { 0, 10, 15, 20 }, 
                       { 10, 0, 35, 25 }, 
                       { 15, 35, 0, 30 }, 
                       { 20, 25, 30, 0 } }; 
//i<<n gives 1 followed by n zeros basically shifting left n times.
//Current example n=4
//1<<n = 16 (10000)
//1<<n = 15 (1111)
int tsp(int mask,int pos){
    if(mask==visited_check){
        return graph[pos][0];
    }

    int ans=INT_MAX;
    for(int i=0;i<n;i++){
        if(((1<<i) & mask)==0){//condition to check if its not visited
            int temp=graph[pos][i]+tsp((1<<i)|mask,i);
            ans=min(ans,temp);
        }
        
    }
    return ans;
}

int main(){
    cout<<tsp(1,0);
    return 0;
}
