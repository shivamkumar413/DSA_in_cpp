#include<iostream>
#include<queue>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int> > graph;
unordered_set<int> visited;
int v; //No. of vertices
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}

void bfs(int src){
    queue<int> q;
    q.push(src);
    visited.insert(src);
    while(q.size()>0){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        for(auto neighbour : graph[temp]){
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
            }
        }
    }
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
    bfs(0);
}