#include<iostream>
#include<list>
#include<queue>
using namespace std;

class Graph{
    int v;//number of nodes
    list<int> *l;
    public:
    Graph(int v){
        this->v=v;
        l=new list<int>[v];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
        
    }

    


    bool isTree(){
        bool *visited=new bool[v];
        int *parent=new int[v];

        for(int i=0;i<v;i++){
            visited[i]=false;
            parent[i]=i;
        }

        int src=0;
        queue<int> q;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(auto val:l[node]){
                if(visited[val]==true && parent[val]!=node){
                    return false;
                }else if(!visited[val]){
                    parent[val]=node;
                    visited[val]=true;
                    q.push(val);
                }
            }
        }

        return true;


    }

   

};

int main(){

    Graph g(4);

    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    //g.addEdge(0,3);
    

    cout<<g.isTree();

    return 0;
}