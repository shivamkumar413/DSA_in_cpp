#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
using namespace std;
vector<list<int> > graph;
int v;//No. of vertices

void add_edge(int src,int dest,bool bi_dir = false){
    graph[src].push_back(dest);
    if(bi_dir) graph[dest].push_back(src);
}
void topoBfs(){
    vector<int> indegree(v,0);
    unordered_set<int> visited;
    for(int i=0;i<v;i++){
        for(auto neighbor : graph[i]){
            // i-->neighbor
            indegree[neighbor]++;
        }
    }
    queue<int> qu;
    for(int i = 0;i<v;i++){
        if(indegree[i]==0){
            qu.push(i);
            visited.insert(i);
        }
    }
    while(qu.size()>0){
        int temp = qu.front();
        qu.pop();
        cout<<temp<<" ";
        for(auto neighbor : graph[temp]){
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                qu.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main(){
    int e;
    cin>>v;
    cin>>e;
    graph.resize(v,list<int>() );
    while(e--){
        int s;
        int d;
        cin>>s>>d;
        add_edge(s,d,false);
    }
    topoBfs();
}