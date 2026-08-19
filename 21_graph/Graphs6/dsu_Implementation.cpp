#include<iostream>
#include<vector>
using namespace std;
class DSU{
    public:
    vector<int> par;
    vector<int> rank;
    DSU(int n){
        par.resize(n);
        rank.resize(n,1);
        for(int i =0;i<par.size();i++){
            par[i] = i;
        }
    }
    void union1(int x,int y){
        int a = find(x);
        int b = find(y);
        if(rank[b]<=rank[a]){
            par[b] = a;
            rank[a]++; 
        }else{
            par[a] = b;
            rank[b]++;
        }
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x] = find(par[x]);
    }
    void display(){
        for(int i =0;i<par.size();i++){
            cout<<par[i]<<" ";
        }
        cout<<endl;
        for(int i =0;i<par.size();i++){
            cout<<rank[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    DSU d(7);
    d.display();
    cout<<endl;
    d.union1(0,1);
    d.display();
}