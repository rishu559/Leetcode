class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> mt(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mt[i][j] = matrix[i][j]-'0';
            }
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mt[i][j]==1)
                mt[i][j] += min(mt[i-1][j],min(mt[i][j-1],mt[i-1][j-1]));
            }
        }

        int maxy = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                maxy = max(maxy,mt[i][j]);
            }
        }
        return maxy*maxy;
        
    }
};