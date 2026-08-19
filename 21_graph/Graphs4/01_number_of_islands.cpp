#include<iostream>
using namespace std;
//https://leetcode.com/problems/number-of-islands/
class Solution {
public:
    void dfs(vector<vector<char>>& grid,int currRow,int currCol){
        int m = grid.size();//NO.of rows
        int n = grid[0].size();//No. of columns
        if(currRow<0 || currCol<0 || currRow>m-1 || currCol>n-1) return;
        if(grid[currRow][currCol]!='1') return;
        grid[currRow][currCol] = '2';
        dfs(grid,currRow-1,currCol);
        dfs(grid,currRow+1,currCol);
        dfs(grid,currRow,currCol-1);
        dfs(grid,currRow,currCol+1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};
int main(){

}