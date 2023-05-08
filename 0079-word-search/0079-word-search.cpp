class Solution {
public:
    bool exists(vector<vector<char>>& board, string& word,int ind,int i,int j,int m,int n,vector<vector<bool>>& visited){

        if(ind==word.size()) return true;
        if(i==m || j==n) return false;
        if(board[i][j]!=word[ind]) return false;

        visited[i][j]=true;
        // cout<<"Here";
        bool left=false,right=false,up=false,down=false;
        // cout<<"Here";
        if(j>0 && visited[i][j-1]==false)
            left = exists(board,word,ind+1,i,j-1,m,n,visited);
        if(j<n-1 && visited[i][j+1]==false)
           right = exists(board,word,ind+1,i,j+1,m,n,visited);
        if(i>0 && visited[i-1][j]==false)
              up = exists(board,word,ind+1,i-1,j,m,n,visited);
        if(i<m-1 && visited[i+1][j]==false)
            down = exists(board,word,ind+1,i+1,j,m,n,visited);
        
        if(left || right || up || down) return true;
        else{
            if(ind==word.size()-1) return true;
            visited[i][j]=false;
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(exists(board,word,0,i,j,m,n,visited)==true) return true;
            }
        }
        return false;
        
    }
};