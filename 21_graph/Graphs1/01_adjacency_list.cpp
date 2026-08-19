#include<iostream>
#include<vector>
#include<list>
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
    display();


}
