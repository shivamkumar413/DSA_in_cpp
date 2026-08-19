#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_set>
#include<climits>
using namespace std;

void add_edge(vector<list<pair<int,int>>> &graph, int u, int v, int wt){
    graph[u].push_back({wt,v});
    graph[v].push_back({wt,u});
}

int djkstra(vector<list<pair<int,int>>> &graph, int src, int dest){ // O(vlogv + elogv)
    int n = graph.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n,INT_MAX);
    dist[src] = 0;
    vector<int> via(n,-1);

    unordered_set<int> visited;
    pq.push({0,src});

    while(!pq.empty()){ // O((v + e)*logv) -> 
        auto top = pq.top();
        int dist_usrc = top.first;
        int nod = top.second;
        if(visited.count(nod)){
            pq.pop();
            continue;
        }
        pq.pop();
        visited.insert(nod);

        // O(v + e)
        for(auto neighbor : graph[nod]){
            int dist_uv = neighbor.first;
            int v = neighbor.second;

            if(!visited.count(v) and dist_usrc + dist_uv < dist[v]){
                dist[v] = dist_usrc + dist_uv;
                via[v] = nod;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[dest] == INT_MAX ? -1 : dist[dest];
}
int main(){
    int n,m;
    cin>>n>>m;

    vector<list<pair<int,int>>> graph(n, list<pair<int,int>>());

    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(graph,u,v,wt);
    }

    cout<<"Enter source and destination: ";
    int src,dest;
    cin>>src>>dest;
    cout<<djkstra(graph,src,dest)<<endl;

}