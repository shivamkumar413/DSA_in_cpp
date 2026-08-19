#include<iostream>
#include<vector>
#include<unordered_set>
#include<list>
using namespace std;
vector<list<int> > graph;
unordered_set<int> visited;

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

void bfs(int src, vector<int> &dist){
    queue<int> qu;
    visited.clear();
    dist.resize(v,INT_MAX);
    dist[src] = 0;
    visited.insert(src);
    qu.push(src);
    while(!qu.empty()){
        int temp = qu.front();
        qu.pop();
        for(auto neighbour : graph[temp]){
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                dist[neighbour] = dist[temp]+1;
                qu.push(neighbour);
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
        add_edge(s,d,false);
    }
    // display();
    int x
    cin>>x;
    vector<int> dist;
    bfs(x,dist);

    for(int i = 0; i < dist.size(); i++){
        cout<<dist[i]<<" ";
    }

    return 0;


}