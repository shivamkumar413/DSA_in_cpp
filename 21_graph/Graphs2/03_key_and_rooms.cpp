// https://leetcode.com/problems/keys-and-rooms/
class Solution {
public:
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& graph,int curr){
        visited.insert(curr);
        for(auto neighbor : graph[curr]){
            if(not visited.count(neighbor)){
                dfs(graph,neighbor);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        dfs(rooms,0);
        if(visited.size() == rooms.size()) return true;
        else return false;
    }
};