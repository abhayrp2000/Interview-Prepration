#include<iostream>
#include<vector>

using namespace std;

class Heap{`
    vector<int> v;
    bool minType;//min or max heap

    public:

    bool compare(int a,int b){
        if(minType){
            return a<b;
        }else{
            return a>b;
        }
    }
    Heap(int size=10,int type){
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
}


int main(){

}