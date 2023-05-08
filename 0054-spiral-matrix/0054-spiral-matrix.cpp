class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        int sr = 0,sc=0;
        while(sc<n && sr<m){
            for(int i=sc;i<n;i++){
                cout<<matrix[sr][i]<<" ";
                res.push_back(matrix[sr][i]);
            }
            sr++;
            if(sr==m) break;
            cout<<"\n";
            for(int i=sr;i<m;i++){
                cout<<matrix[i][n-1]<<" ";
                res.push_back(matrix[i][n-1]);
            }
            n--;
            if(sc==n) break;
            cout<<"\n";
            for(int i=n-1;i>=sc;i--){
                cout<<matrix[m-1][i]<<" ";
                res.push_back(matrix[m-1][i]);
            }
            m--;
            if(sr==m) break;
            cout<<"\n";
            for(int i=m-1;i>=sr;i--){
                cout<<matrix[i][sc]<<" ";
                res.push_back(matrix[i][sc]);
            }
            sc++;
            
            cout<<"\n";
            // sr++;
            // sc++;
            // n--;
            // m--;
        }
        
        
        return res;
    }
};