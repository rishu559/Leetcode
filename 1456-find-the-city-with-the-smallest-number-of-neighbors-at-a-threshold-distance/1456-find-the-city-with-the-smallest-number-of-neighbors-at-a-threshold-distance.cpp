class Solution {
public:
 
    
    int findTheCity(int n, vector<vector<int>>& edges, int DT) {
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        for(int i=0;i<n;i++) matrix[i][i]=0;
        
        for(auto vec:edges){
            matrix[vec[0]][vec[1]] = vec[2];
            matrix[vec[1]][vec[0]] = vec[2];
        }
	    for(int k=0;k<n;k++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(matrix[i][k]==-1 || matrix[k][j]==-1){
	                   
	               }else{
	                   if(matrix[i][j]==-1){
	                       matrix[i][j]=matrix[k][j]+matrix[i][k];
	                   }else{
	                       matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
	                   }
	               }
	            }
	        }
	    }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }

        int city = -1;
        int miny = INT_MAX;
        for(int i=0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=DT){
                    count++;
                }
            }
            if(count-1<=miny){
                miny = count-1;
                city = i;
            }
        }

        return city;
    }
};