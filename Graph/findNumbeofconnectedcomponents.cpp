#include<iostream>
#include<list>
#include<map>

using namespace std;

class Graph{
   
    map<int,list<int> > l;
    public:
    

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(int src,map<int,bool> &visited){
        cout<<src<<" ";
        visited[src]=true;

        for(auto val:l[src]){
            if(!visited[val]){
                dfs_helper(val,visited);
            }
        }
    }

    void dfs(){

        map<int,bool> visited;
        for(auto p: l){
            visited[p.first]=false;
        }

        int count=0;
        for(auto p:l){
            int vertex=p.first;
            if(!visited[vertex]){
                cout<<"Component "<<count<<" --> ";
                dfs_helper(vertex,visited);
                cout<<endl;
                count++;
            }
        }
    }

   

    


};

int main(){

    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(0,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(8,8);


    g.dfs();
    

    
    return 0;
}