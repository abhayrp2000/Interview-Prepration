#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

class Graph{
   
    map<int,list<int> > l;
    public:
    

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs(int src){
        queue<int> q;
        map<int,bool> visited;

        q.push(src);
        visited[src]=true;

        while (!q.empty())
        {
            int vertex=q.front();
            
            q.pop();
            cout<<vertex<<endl;
            for(auto val:l[vertex]){
                if(!visited[val]){
                    q.push(val);
                    visited[vertex]=true;
                }
                
            }

        }
        
    }

    


};

int main(){

    Graph g;

    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);


    g.bfs(0);

    //g.printAdjList();
    return 0;
}