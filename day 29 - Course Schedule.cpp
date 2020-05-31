class Solution {
public:
    map<int,vector<int>> edge;
    vector<int>vis;
    vector<int>isCycle;

    bool dfs(int u){
        for (int i = 0; i < edge[u].size(); ++i)
        {
            if (isCycle[edge[u][i]])
            {
                return true;
            }
    
            isCycle[edge[u][i]] = true;
            
            if (dfs(edge[u][i]))
            {
                return true;
            }

            isCycle[edge[u][i]] = false;
        }

        vis[u]=true;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < prerequisites.size(); ++i)
        {
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vis.resize(numCourses,false);
        isCycle.resize(numCourses,false);

        for (int i = 0; i < numCourses; ++i)
        {
            if (!vis[i])
            {
                if (dfs(i))
                {
                    return false;
                }
            }
        }
        return true;
    }
};