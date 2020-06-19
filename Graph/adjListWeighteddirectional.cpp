#include<iostream>
#include<list>
#include<unordered_map>
#include<string>

using namespace std;
class Graph{
    unordered_map<string,list<pair<string,int> > > l;

    public:
    void addEdge(string x,string y,bool bidir,int cost){
        l[x].push_back({y,cost});
        if(bidir){
            l[y].push_back({x,cost});
        }
    }

    void printAdjList(){
        for(auto p:l){
            cout<<"Vertex "<<p.first<<"-->";
            list<pair<string,int> > temp=p.second;
            for(auto val:temp){
                cout<<val.first<<","<<val.second<<"||";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("C","D",true,40);
    g.addEdge("A","D",false,50);

    g.printAdjList();
    return 0;


}