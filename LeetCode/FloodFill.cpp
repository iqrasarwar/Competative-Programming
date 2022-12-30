class Solution {
public:
    void dfs(int i,int j, int old,int newColor, vector<vector<int>>& image)
{
   int n = image.size();
   int m = image[0].size();
   if(i<0 || j<0)return;
   if(i >= n || j >= m)return;
   if(image[i][j] == old) image[i][j] = newColor;
   else return;
   dfs(i-1,j,old,newColor,image);
   dfs(i,j-1,old,newColor,image);
   dfs(i,j+1,old,newColor,image);
   dfs(i+1,j,old,newColor,image);
}
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    if(image[sr][sc]!=newColor)
      dfs(sr,sc,image[sr][sc],newColor,image);
      return image;
}
};
