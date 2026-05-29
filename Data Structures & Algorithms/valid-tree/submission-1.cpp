class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<pair<int,int>> q;

        vector<int> vis(n,0);

        q.push({0,-1});

        vis[0] = 1;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int parent = it.second;
            for(auto i:adj[node]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i,node});
                }else{
                    if(i != parent){
                        return false;
                    }
                }
            }
        }


        for(int i = 0;i < n;i++){
            if(!vis[i]){
                return false;
            }
        }

        return true;
    }
};
