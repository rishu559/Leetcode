class Solution {
public:
    queue<pair<int,int>> q;
    int n;
    int level =0;
    void bfs(vector<vector<int>> &grid,vector<vector<bool>>& visited){  
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        if(i==-1 && j==-1){
            level++;
            q.push({-1,-1});
            return;
        }
        if(i<n-1 && visited[i+1][j]==false){
            visited[i+1][j]=true;
            q.push({i+1,j});
        }
        if(j<n-1 && visited[i][j+1]==false){
            visited[i][j+1]=true;
            q.push({i,j+1});
        }
        if(i>0 && visited[i-1][j]==false){
            visited[i-1][j]=true;
            q.push({i-1,j});
        }
        if(j>0 && visited[i][j-1]==false){
            visited[i][j-1]=true;
            q.push({i,j-1});
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        bool found  = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    visited[i][j]=true;
                    q.push({i,j});
                }
                else found=true;
            }
        }
        if(q.size()==0 || !found) return -1;
        q.push({-1,-1});
        while(q.size()>1){
            bfs(grid,visited);
        }
        return level;
    }
};