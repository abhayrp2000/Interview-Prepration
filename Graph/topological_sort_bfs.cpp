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

    void topological_sort(){
        int indegree[v];
        for(int i=0;i<v;i++){
            indegree[i]=0;
        }

        for(int i=0;i<v;i++){
            for(auto val:l[i]){
                indegree[val]++;
            }
        }

        queue<int> q;

        for(int i=0;i<v;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int vertex=q.front();
            cout<<vertex<<" -> ";
            q.pop();

            for(auto val:l[vertex]){
                indegree[val]--;
                if(indegree[val]==0){
                    q.push(val);
                }
            }
        }
        


    }

   

};

int main(){

    Graph g(5);

    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.topological_sort();

    return 0;
}