#include<iostream>
#include<list>
#include<map>

using namespace std;

class Graph{
   
    map<int,list<int> > l;
    public:
    

    void addEdge(int x,int y){
        l[x].push_back(y);
    }

    void dfs_helper(int src,map<int,bool> &visited,list<int> &ordering){

        
        
        visited[src]=true;

        for(auto val:l[src]){
            if(!visited[val]){
                dfs_helper(val,visited,ordering);
            }
        }

        ordering.push_front(src);
    }

    void dfs(){
        list<int> ordering;
        map<int,bool> visited;
        for(auto p: l){
            visited[p.first]=false;
        }

        for(auto p:l){
            int vertex=p.first;
            if(!visited[vertex]){
                dfs_helper(vertex,visited,ordering);
            }
        }

      

        for(auto val:ordering){
            cout<<val<<"-->";
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
    g.addEdge(4,5);


    g.dfs();
    

    
    return 0;
}