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
        for(int a=-1;a<=1;a++){
            for(int b = -1;b<=1;b++){
                if(abs(a-b)==1){
                    int x = i+a;
                    int y = j+b;
                    if(x>=0 && y>=0 && x<n && y<n && visited[x][y]==false){
                        visited[x][y] = true;
                        q.push({x,y});
                    }
                }
            }
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