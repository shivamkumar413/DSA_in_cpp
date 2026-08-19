#include<bits/stdc++.h>
using namespace std;
vector<list<int> > graph;
int v;//no. of vertices
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<" --> ";
        for(auto el: graph[i]){
            cout<<el<<" , ";
        }
        cout<<endl;
    }
}
bool dfs(int src,int parent,unordered_set<int> &visited){
    visited.insert(src);
    for(auto neighbor : graph[src]){
        if(visited.count(neighbor) and neighbor!= parent){
            //cycle detected
            return true;
        }
        if(not visited.count(neighbor)){
            bool res = dfs(neighbor,src,visited);
            if(res==true) return true;
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int> visited;
    for(int i =0;i<v;i++){
        if(not visited.count(i)){
            bool result = dfs(i,-1,visited);
            if(result==true) return true;
        }
    }
    return false;
}
int main(){
    cout<<"Enter No. of vertices in graph : ";
    cin>>v;
    graph.resize(v,list<int> ());//This will resize the graph vector with size v and at each index will be list with size 0.
    int e;
    cout<<"Enter No. of Edges in graph : ";
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    bool b = has_cycle();
    cout<<b<<"\n";
}