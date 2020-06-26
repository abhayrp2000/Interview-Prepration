#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<string>
#include<climits>
#include<set>
using namespace std;

template<typename T>

class Graph{
    map<T,list<pair<T,int> > > mp;
    public:
    void addEdge(T u,T v,int dist,bool direction=true){
        mp[u].push_back(make_pair(v,dist));
        if(direction){
            mp[v].push_back(make_pair(u,dist));
        }
    }

    void printList(){
        for(auto val:mp){
            cout<<val.first<<"-->";
            for(auto temp:val.second){
                cout<<"("<<temp.first<<" "<<temp.second<<")";
            }
            cout<<endl;
        }
    }

    void djikstra(T src){

        map<T,int> distmap;

        for(auto val:mp){
            distmap[val.first]=INT_MAX;
        }

        set<pair<int,T> > s;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            auto p=*s.begin();
            T node=p.second;
            int d=p.first;

            s.erase(s.begin());
            cout<<node <<"-->"<<d<<endl;

            for(auto val:mp[node]){
                if(d+val.second<distmap[val.first]){
                    auto it=s.find(make_pair(distmap[val.first],val.first));
                    if(it!=s.end()){
                        s.erase(make_pair(distmap[val.first],val.first));

                    }
                    distmap[val.first]=d+val.second;
                    s.insert(make_pair(distmap[val.first],val.first));
                }
            }


        }

        

    }


};

int main(){
    Graph<string> india;

    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3); 
    india.addEdge("Agra","Delhi",1);

    india.printList();

    india.djikstra("Amritsar");
}
