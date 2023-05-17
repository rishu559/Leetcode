class Solution {
public:
    void dfs(vector<vector<int>>& graph,int src,vector<int>& isSafe){
        if(isSafe[src]) return;
        bool safety = 1;
        isSafe[src] = -1;
        for(int i:graph[src]){
            if(isSafe[i]!=-1){
                dfs(graph,i,isSafe);
                if(!isSafe[i]){
                    safety=0;
                    break;
                }
            }
            else{
                safety=0;
                break;
            }
        }
        isSafe[src] = safety;

        // for(int i:isSafe) cout<<i<<" ";
        // cout<<"\n";
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> isSafe (n,0);

        for(int i=0;i<n;i++){
            if(graph[i].size()==0) isSafe[i]=1;
        }

        for(int i=0;i<n;i++){
            if(isSafe[i]==0)
                dfs(graph,i,isSafe);
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(isSafe[i]==1) ans.push_back(i);
        }
        return ans;

    }
};