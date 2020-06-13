#include<iostream>
#include<vector>

using namespace std;

class Heap{
    vector<int> v;
    bool minType;//min or max heap

    bool compare(int a,int b){
        if(minType){
            return a<b;
        }else{
            return a>b;
        }
    }

    void heapify(int index){
        int left=2*index;
        int right=left+1;

        int last=v.size()-1;
        int min_index=index;

        if(left<=last && compare(v[left],v[index])){
            min_index=left;
        }

        if(right<=last && compare(v[right],v[min_index])){
            min_index=right;
        }

        if(min_index!=index){
            swap(v[index],v[min_index]);
            heapify(min_index);
        }
    }

    public:

    
    Heap(int size=10,int type=true){
        v.reserve(size);
        v.push_back(-1);
        minType=type;
    }

    void push(int data){
        //first insert at last
        v.push_back(data);
        //index at which it was pushed
        int index=v.size()-1;
        int parent=index/2;

        while(index>1 && compare(v[index],v[parent])){
            swap(v[parent],v[index]);
            index=parent;
            parent=parent/2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){
        int last_index=v.size()-1;
        swap(v[1],v[last_index]);
        v.pop_back();

        heapify(1);
    }

    bool isEmpty(){
        return v.size()==1;
    }
};


int main(){

    Heap h;
    int n=10;

    for(int i=0;i<n;i++){
        h.push(i);
    }

    while(!h.isEmpty()){
        cout<<h.top()<<endl;
        h.pop();
    }


    return 0;
}