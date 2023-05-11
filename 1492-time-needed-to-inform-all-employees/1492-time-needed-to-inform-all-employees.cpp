class Solution {
public:
    int findTime(vector<vector<int>>& adj,vector<int>& informTime,int source){
        if(adj[source].size()==0) return 0;
        int res = 0;
        for(int i:adj[source]){
            res = max(res,findTime(adj,informTime,i));
        }
        return informTime[source]+res;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            if(manager[i]==-1) continue;
            adj[manager[i]].push_back(i);
        }
        return findTime(adj,informTime,headID);
    }
};