class Solution {
public:
    vector<int> ans;
    void print(vector<vector<int>>& matrix,int i,int j,int m,int n){
        if(i>=m || j>=n) return;
        for(int c=j;c<n;c++){
            ans.push_back(matrix[i][c]);
        }
        i++;
        if(i>=m) return ;
        for(int r=i;r<m;r++){
            ans.push_back(matrix[r][n-1]);
        }
        n--;
        if(j>=n) return ;
        for(int c=n-1;c>=j;c--){
            ans.push_back(matrix[m-1][c]);
        }
        m--;
        if(i>=m) return ;
        for(int r=m-1;r>=i;r--){
            ans.push_back(matrix[r][j]);
        }
        j++;
        print(matrix,i,j,m,n);

    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        print(matrix,0,0,m,n);
        return ans;
    }   
};