#include <iostream>
#include<climits>
using namespace std;

class Edge{
    public:
    int  src,dest,w;
};

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	    int v,e;
	    cin>>v>>e;
	    int flag=0;
	    
	    Edge graph[e];
	    for(int i=0;i<e;i++){
	        int src,dest,w;
	        cin>>src>>dest>>w;
	        graph[i].src=src;
	        graph[i].dest=dest;
	        graph[i].w=w;
	    }
	    
	    int dist[v];
	    for(int i=0;i<v;i++){
	        dist[i]=INT_MAX;
	    }
	    dist[0]=0;
	    
	    for(int i=1;i<=v-1;i++){
	        for(int j=0;j<e;j++){
	            int u=graph[j].src;
	            int v=graph[j].dest;
	            int w=graph[j].w;
	            
	            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
	                dist[v]=dist[u]+w;
	            }
	        }
	    }
	    
	    for(int i=0;i<e;i++){
	        int u=graph[i].src;
	        int v=graph[i].dest;
	        int w=graph[i].w;
	        
	        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
	            flag=1;
	        }
	    }
	    cout<<flag<<endl;
	}
	return 0;
}