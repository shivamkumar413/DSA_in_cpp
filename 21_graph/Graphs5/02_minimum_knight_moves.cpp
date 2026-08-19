// https://www.geeksforgeeks.org/problems/steps-by-knight5927/1
class Solution {
  public:
    int minStepToReachTarget(vector<int>& knightPos, vector<int>& targetPos, int n) {
        // Code here
        queue<pair<pair<int,int>,int>> qu;
        vector<vector<int>> directions ={ {2,1},{2,-1}, {-2,1}, {-2,-1}, {1,2}, {-1,2}, {1,-2}, {-1,-2}};
        vector<vector<bool>> visited(n+1,vector<bool> (n+1,false));
        qu.push({{knightPos[0],knightPos[1]},0});
            
        visited[knightPos[0]][knightPos[1]] = true;
        int ans = INT_MAX;
        while(!qu.empty()){
            auto top = qu.front();
            qu.pop();
            
            if(top.first.first == targetPos[0] and top.first.second == targetPos[1]){
                ans = min(ans,top.second);
            }
            
            int currRow = top.first.first;
            int currCol = top.first.second;
            
            for(int i = 0; i < directions.size(); i++){
                int nextRow = currRow + directions[i][0];
                int nextCol = currCol + directions[i][1];
                
                if(nextRow >= 1 and nextRow <= n and nextCol >=1 and nextCol <= n and !visited[nextRow][nextCol]){
                    visited[nextRow][nextCol] = true;
                    int dist = top.second + 1;
                    qu.push({{nextRow,nextCol},dist});
                }
            }
        }
        
        return ans;
    }
};