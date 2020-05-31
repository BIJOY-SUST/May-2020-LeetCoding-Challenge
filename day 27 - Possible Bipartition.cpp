class Solution {
public:
    
    vector<vector<int>> adj;

    map<int,int> color;

    bool dfs(int node,int c){
        if(color.find(node) != color.end()){
            return color[node] == c;
            // return color[node];
        }

        color[node] = c;

        for(int v : adj[node]){
            if(!dfs(v,1-c)){
                return false;
            }
        }

        return true;
    }
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        adj = vector<vector<int>>(N+1);
        for (vector<int>& edge : dislikes) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for (int i = 1; i <= N; ++i)
        {
            if (color.find(i) == color.end() && !dfs(i,0))
            {
                return false;
            }
        }
        return true; 
    }
};