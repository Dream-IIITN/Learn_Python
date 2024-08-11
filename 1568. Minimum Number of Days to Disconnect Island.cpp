class Solution {
public:
int m,n;
void dfs(vector<vector<int>>&grid, int i , int j,vector<vector<bool>>&visit){
    if(i<0 || i>m-1 || j<0 || j>n-1 || visit[i][j] || grid[i][j]==0)
    return;
   visit[i][j]=true;
    dfs(grid,i,j+1, visit);
     dfs(grid,i+1,j,visit);
      dfs(grid,i-1,j,visit);
       dfs(grid,i,j-1,visit);
}
int numberisland(vector<vector<int>>&grid){
    int cnt=0;
    vector<vector<bool>>visit(m,vector<bool>(n));
     // find number of island at each 1
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && !visit[i][j]){
                dfs(grid,i,j,visit);
                cnt++;
            }
        }
    }
    return cnt;
}
    int minDays(vector<vector<int>>& grid) {
        int sol=0;
        m= grid.size();// row cnt
        n = grid[0].size();// col cnt
        int final = numberisland(grid);
        if(final>1 || final==0)
        return 0;
        else{
            for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                
                if(grid[i][j]==1){
                grid[i][j]=0;
                int x =numberisland(grid);
                if(x>1 || x==0)
                return 1;
                grid[i][j]=1;// imp!!
                }
                
            }
        }
       
    }
        return 2; 
    }
};
