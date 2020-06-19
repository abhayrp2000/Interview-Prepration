//Shortest path from a single source
#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<climits>
using namespace std;

class Graph{
   
    map<int,list<int> > l;
    public:
    

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void spss(int src){
        queue<int> q;
        map<int,int> dist;

        q.push(src);
        

        for(auto node:l){
            int vertex=node.first;
            dist[vertex]=INT_MAX;
        }
        dist[src]=0;

        

        while (!q.empty())
        {
            int vertex=q.front();
            
            q.pop();
            for(auto val:l[vertex]){
                if(dist[val]==INT_MAX){
                    q.push(val);
                    dist[val]=dist[vertex]+1;
                }
                
            }

        }

        for(auto val:dist){
            cout<<val.first<<" Vertex ->"<<" "<<val.second<<endl;
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


    g.spss(0);

    
    return 0;
}