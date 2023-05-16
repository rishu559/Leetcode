class Solution {
public:
  
    // int ans = INT_MAX;
    int bfs(vector<vector<pair<int,int>>>& adj,int src,int dst,int k,vector<int> & dist){
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(q.empty()==false){
            auto temp = q.front();
            q.pop();
            int steps = temp.first;
            int source = temp.second.first;
            int cost = temp.second.second;

            if(steps>k) continue;

            for(auto ngb:adj[source]){
                if(cost+ngb.second<dist[ngb.first] && steps<=k){
                    dist[ngb.first] = cost+ngb.second;
                    q.push({steps+1,{ngb.first,cost+ngb.second}});
                }
            }
        }
        return dist[dst];
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        vector<int> dist(n,INT_MAX);
        dist[src]=0;

        // if(k==0 && src!=dst) return 0;
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }

        int num = bfs(adj,src,dst,k,dist);
        return num==INT_MAX || num==0?-1:num;
        
        // return cheapest==INT_MAX?-1:cheapest;

        
    }
};
