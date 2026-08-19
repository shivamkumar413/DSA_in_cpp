#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;
vector<list<pair<int,int> > > graph;
void add_edge(int src,int dest,int wt,bool bi_dir = true){
    graph[src].push_back({dest,wt});
    if(bi_dir) graph[dest].push_back({src,wt});
}

ll prims(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp> > pq;//{wt,node}
    unordered_set<int> vis;
    vector<int> par(n+1);
    unordered_map<int,int> mp;//{Node, discovery wt.}
    for(int i =1;i<=n;i++){
        mp[i] = INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    int edgeCount = 0;
    int result = 0;//Sum of weights
    while(edgeCount<n and pq.size()>0){
        pp curr = pq.top();
        if(vis.count(curr.second)){
            pq.pop();
            continue;
        }

        vis.insert(curr.second);
        edgeCount++;
        result += curr.first;
        pq.pop();

        for(auto neighbor : graph[curr.second]){
            if(!vis.count(neighbor.first) and mp[neighbor.first] > neighbor.second) {
                pq.push({neighbor.second,neighbor.first});
                par[neighbor.first] = curr.second;
                mp[neighbor.first] = neighbor.second;
            }
        }
    }

    return result;

}

int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<pair<int,int> >());
    while(m--){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        add_edge(src,dest,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n)<<"\n";
    return 0;
}