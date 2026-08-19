//https://leetcode.com/problems/flood-fill/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if(initialColor!=color){
            dfs(image,sr,sc,initialColor,color);
        }
        return image;
    }

    void dfs(vector<vector<int> >& image,int currRow ,int currCol,int initialColor,int newColor){
        int n = image.size();//Total rows
        int m = image[0].size();//Total columns
        if(currRow<0 || currCol<0 || currRow>n-1 || currCol>m-1) return;//You re outside the grid
        //if the cell you landed is not of initial color
        if(image[currRow][currCol]!=initialColor) return;
        if(image[currRow][currCol]==initialColor){
            image[currRow][currCol] = newColor;
            dfs(image,currRow+1,currCol,initialColor,newColor);
            dfs(image,currRow,currCol+1,initialColor,newColor);
            dfs(image,currRow-1,currCol,initialColor,newColor);
            dfs(image,currRow,currCol-1,initialColor,newColor);
        }
    }
};