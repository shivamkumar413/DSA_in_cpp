#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int> > graph;
int v; // No. of vertices
unordered_set<int> visited;
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr);//Mark current as visited
    for(auto neighbour : graph[curr]){
        if(not visited.count(neighbour)){
            bool result = dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}
bool anyPath(int src,int dest){
    return dfs(src,dest);
}
int main(){
    cout<<"No. of vertex in graph : ";
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cout<<"No. of Edges in graph : ";
    cin>>e;
    while(e--){
        int s,d;
        cout<<"Enter the connected vertex : ";
        cin>>s>>d;
        add_edge(s,d);
    }
    int x,y;
    cout<<"Enter the source and destination vertex : ";
    cin>>x>>y;
    bool ans = anyPath(x,y);
    if(ans==1) cout<<"Path exists b/w the node "<<x<<" and "<<y<<endl;
    else cout<<"There exists no path b/w the given node";
    return 0;
}