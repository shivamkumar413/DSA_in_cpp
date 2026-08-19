#include<iostream>
using namespace std;
//https://leetcode.com/problems/coloring-a-border/
//https://www.notion.so/Leetcode-1034-Coloring-A-Border-13b9ed156fec8060b9defbdfc768aead
class Solution {
public:
    vector<pair<int,int>> arr;
    
    void dfs(vector<vector<int>>& grid,int cr , int cc,int initialColor){
        int m = grid.size();
        int n = grid[0].size();
        if(cr<0 || cc <0 || cr>m-1 || cc>n-1) return;
        if(grid[cr][cc]!=initialColor) return;
        grid[cr][cc] = -1;
        dfs(grid,cr+1,cc,initialColor);
        dfs(grid,cr-1,cc,initialColor);
        dfs(grid,cr,cc+1,initialColor);
        dfs(grid,cr,cc-1,initialColor);

        if(cr==0 || cc ==0 || cr==m-1 || cc==n-1){
            cout<<cr<<"   "<<cc<<endl;
            arr.push_back({cr,cc});
        }
        
        if(cr!=m-1 && grid[cr+1][cc]!=-1 ) arr.push_back({cr,cc});
        else if(cr!=0 && grid[cr-1][cc]!=-1) arr.push_back({cr,cc});
        else if(cc!=n-1 && grid[cr][cc+1]!=-1) arr.push_back({cr,cc});
        else if(cc!=0 and grid[cr][cc-1]!=-1) arr.push_back({cr,cc});
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int initialColor = grid[row][col];
        dfs(grid,row,col,initialColor);
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == -1) {
                    grid[i][j] = initialColor;
                }
            }
        }

        for(int i =0 ;i<arr.size();i++){
            int rowIdx = arr[i].first;
            int colIdx = arr[i].second;
            grid[rowIdx][colIdx] = color;
        }
        return grid;
    }
};
int main(){
    
    return 0;
}