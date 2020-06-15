#include<iostream>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int q;
    int k;
    cin>>q>>k;
    vector<int> result;
    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<q;i++){
        int qt;
        cin>>qt;
        
        
        if(qt==1){
            int x,y;
            cin>>x>>y;
            int rs=x*x+y*y;
            pq.push(rs);
        }else if(qt==2){
            vector<int> temp;
            for(int i=0;i<k-1;i++){
                int t=pq.top();
                pq.pop();
                temp.push_back(t);
            }
            //cout<<pq.top()<<endl;
            result.push_back(pq.top());
            pq.pop();
            for(auto val: temp){
                pq.push(val);
            }
        }
    }

    for(auto val:result){
        cout<<val<<endl;
    }
    return 0;
}