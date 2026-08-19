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
bool bfs(int src){
    unordered_set<int> vis;
    queue<int> qu;
    vector<int> par(v,-1);
    qu.push(src);
    vis.insert(src);
    while(not qu.empty()){
        int curr = qu.front();
        qu.pop();
        for(auto neighbor : graph[curr]){
            if(vis.count(neighbor) and par[curr]!=neighbor) return true;
            if(!vis.count(neighbor)){
                vis.insert(neighbor);
                par[neighbor] = curr;
                qu.push(neighbor);
            }
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int> visited;
    for(int i =0;i<v;i++){
        if(not visited.count(i)){
            bool result = bfs(i);
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